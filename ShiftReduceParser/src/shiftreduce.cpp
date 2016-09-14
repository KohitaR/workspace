/*
 * shiftreduce.cpp
 *
 *  Created on: 2016/09/12
 *      Author: ryosuke-k
 */

#include <vector>
#include <iostream>

#include "shiftreduce.h"

using namespace std;

ShiftReduce::ShiftReduce(const vector<vector<Conllu>> sentences,
        const size_t vocab, const size_t pos) :
        sentences_(sentences), vocab_(vocab), pos_(pos) {
    root_.setToken(0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    root_.childN = 0;
}

void ShiftReduce::Action(const int n) {
    if (n == 0) {
        Left();
    } else if (n == 1) {
        Right();
    } else {
        Shift();
    }
}

void ShiftReduce::Action(vector<int> actions) {
    int action = actions.back();
    actions.pop_back();

    if (buffer_.size() == 0 and action == 2) {
        action = actions.back();
        actions.pop_back();
    } else if (stack_.size() == 1 and action != 2) {
        action = 2;
    }

    if (action == 0) {
        Left();
    } else if (action == 1) {
        Right();
    } else {
        Shift();
    }
}

void ShiftReduce::Left() {
    auto s_top2 = (stack_.end() - 2);
    heads_[s_top2->getId()] = (stack_.end() - 1)->getId();
    stack_.erase(s_top2);
    s_top2->childN -= 1;
}

void ShiftReduce::Right() {
    auto s_top1 = (stack_.end() - 1);
    auto s_top2 = (stack_.end() - 2);

    heads_[s_top1->getId()] = s_top2->getId();
    stack_.pop_back();
    s_top2->childN -= 1;

}

void ShiftReduce::Shift() {
    stack_.push_back(buffer_.back());
    buffer_.pop_back();
}

void ShiftReduce::InitializeState(vector<Conllu>& sentence) {
    stack_.clear();
    buffer_.clear();
    heads_.clear();

    stack_.push_back(root_);
    for (auto itr = sentence.rbegin(); itr != sentence.rend(); ++itr) {
        itr->childN = itr->getChildrenSize();
        buffer_.push_back(*itr);
    }
}

void ShiftReduce::Train() {
    cout << "Now training ..." << endl;
    int i = 0;
    int epoch = 50;
    InitializeWeights(vocab_, pos_);

    while (i != epoch) {
        cout << "epoch: " << i << endl;
        for (auto sentence : sentences_) {
            InitializeState(sentence);
            while (stack_.size() > 1 or buffer_.size() > 0) {
                vector<int> feats(getFeats(stack_, buffer_));
                int pred = CalcScore(feats);
                int oracle = getOracle(stack_, buffer_);
                if (pred == oracle) {
                    Action(oracle);
                } else {
                    Update(pred, oracle, feats);
                    Action(oracle);
                }
            }
        }
        ++i;
    }
}

//void ShiftReduce::Test(vector<Conllu>& sentence) {
//    InitializeState(sentence);
//    while (stack_.size() > 1 or buffer_.size() > 0) {
//        if (buffer_.size() == 0 and stack_.size() == 2) {
//            Right();
//            break;
//        }
//        vector<int> feats(getFeats(stack_, buffer_));
//        vector<int> pred = CalcScoreMulti(feats);
//        Action(pred);
//        for (int i = 0; i < sentence.size(); ++i){
//            sentence[i].getHead() == heads_[i];
//            correctN += 1;
//        }
//    }
//}

vector<int> ShiftReduce::Test(vector<vector<Conllu>>& sentences) {
    int corrN;
    int N;
    int s = 0;
    int c = 0;
    for (auto sentence : sentences) {
        InitializeState(sentence);
        while (stack_.size() > 1 or buffer_.size() > 0) {
            if (buffer_.size() == 0 and stack_.size() == 2) {
                Right();
                break;
            }
            vector<int> feats(getFeats(stack_, buffer_));
            vector<int> pred = CalcScoreMulti(feats);
            Action(pred);
            }

        for(int i = 0; i < sentence.size(); ++i){
            if (sentence[i].getHead() == heads_[i+1]){
                corrN += 1;
                N+= 1;
            } else {
                N+=1;
            }
        }
    }
    return {N, corrN};
}
