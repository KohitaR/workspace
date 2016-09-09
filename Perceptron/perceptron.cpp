/*
 * perseotrib.cpp
 *
 *  Created on: 2016/09/05
 *      Author: ryosuke-k
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "perceptron.h"
#include "feature.h"
#include "utils.h"

using namespace std;

// data frame : class sentence
Perceptron::Perceptron(vector<vector<string>> data) :
        mData(data) {
}

void Perceptron::CreateFeats() {
    Feature mUnigram;
    Feature mBigram;
    Feature mTrigram;

    for (auto itr = mData.begin(); itr != mData.end(); ++itr) {
        mAnswer.push_back(stoi((*itr)[0]));
        vector<string> words = split((*itr)[1], ' ');
        mSentWords.push_back(words);
        size_t n = words.size();

        for (size_t i = 0; i < n; ++i) {
            if (i == 0) {
                mUnigram.setFeature(words[i]);
                mBigram.setFeature("<s> " + words[i]);
                mTrigram.setFeature("<s> " + words[i] + " " + words[i + 1]);
            } else if (i == n - 1) {
                mUnigram.setFeature(words[i]);
                mBigram.setFeature(words[i] + " </s>");
            } else if (i == n - 2) {
                mUnigram.setFeature(words[i]);
                mBigram.setFeature(words[i] + " </s>");
                mTrigram.setFeature(words[i] + " " + words[i + 1] + " </s>");

            } else {
                mUnigram.setFeature(words[i]);
                mBigram.setFeature(words[i] + " " + words[i + 1]);
                mTrigram.setFeature(
                        words[i] + " " + words[i + 1] + " " + words[i + 2]);
            }
        }
        mUnigram.saveSentFeats();
        mBigram.saveSentFeats();
        mTrigram.saveSentFeats();
    }
    mFeatures.push_back(mUnigram);
    mFeatures.push_back(mBigram);
    mFeatures.push_back(mTrigram);
}

vector<vector<int>> Perceptron::Sentence2Vec(vector<string>, size_t n) {
    vector<vector<int>> sent_vec;
    vector<int>feat_vec1(mFeatures[0].size(), 0);
    vector<int>feat_vec2(mFeatures[1].size(), 0);
    vector<int>feat_vec3(mFeatures[2].size(), 0);
    vector<vector<int>> temp{feat_vec1, feat_vec2, feat_vec3};
    for (auto itr : mFeatures) {
        vector<int> feat_vec(itr.size(), 0); // get zero-vector [0, 0, 0, 0, .... n (number of features)]
        vector<int> sent_feats(itr.getSentFeats(n)); // get feature IDs
        for (auto feat : sent_feats) {
            feat_vec[feat] += 1; // stand 1 at the IDs
        }
        sent_vec.push_back(feat_vec); // sent_vec [ [ feature1], [feature2], ... [feature N]]
    }
    return sent_vec;
}

int Perceptron::PredictOne(vector<vector<int>> sentence) {
    double score = 0;
    for (size_t i = 0; i != mFeatures.size(); ++i) {
        score += vecSum(vecMaltvec(getWeight(i), sentence[i]));
    }
    if (score >= 0) {
        return 1;
    } else {
        return -1;
    }
}

void Perceptron::UpdateWeights(vector<vector<int>> x, int y) {
    for (size_t i = 0; i != mWeights.size(); ++i) {
        mWeights[i] = vecSumvec(mWeights[i], vecMaltint(x[i], y));
    }
}

void Perceptron::Train() {
    CreateFeats();
    cout << mData.size() << endl;
    vector<vector<int>> sent_vec;
    for (size_t sentenceN = 0; sentenceN != mData.size(); ++sentenceN) {
        cout << "Creating sentence vector ..." << sentenceN + 1 << endl;
        mSentence_vectors.push_back(Sentence2Vec(mData[sentenceN], sentenceN));
    }

    InitializeWeights();

    int y = 0;
    int sent_index;

    for (int itr = 0; itr < 20; ++itr) {
        cout << "Iteration : " << itr + 1 << " / 10" << endl;
        int N = 0;
        for (auto x = mSentence_vectors.begin(); x != mSentence_vectors.end();
                ++x) {
            sent_index = x - mSentence_vectors.begin();
            y = PredictOne(*x);
            if (y != mAnswer[sent_index]) {
                N += 1;
                UpdateWeights(*x, mAnswer[sent_index]);
            }
        }
    }
}

int Perceptron::Predict(string test_sent) {
    vector<string> words = split(test_sent, ' ');
    vector<int> unigram_feats;
    vector<int> bigram_feats;
    vector<int> trigram_feats;
    size_t n = words.size();
    for (size_t i = 0; i < n; ++i) {
        if (i == 0) {
            unigram_feats.push_back(mFeatures[0].getId(words[i]));
            bigram_feats.push_back(mFeatures[1].getId(("<s> " + words[i])));
            trigram_feats.push_back(
                    mFeatures[2].getId(
                            ("<s>" + words[i] + " " + words[i + 1])));
        } else if (i == n - 1) {
            unigram_feats.push_back(mFeatures[0].getId(words[i]));
            bigram_feats.push_back(mFeatures[1].getId((words[i]) + " </s>"));
        } else if (i == n - 2) {
            unigram_feats.push_back(mFeatures[0].getId(words[i]));
            bigram_feats.push_back(
                    mFeatures[1].getId((words[i] + " " + words[i + 1])));
            trigram_feats.push_back(
                    mFeatures[2].getId(
                            (words[i] + " " + words[i + 1] + " </s>")));
        } else {
            unigram_feats.push_back(mFeatures[0].getId(words[i]));
            bigram_feats.push_back(
                    mFeatures[1].getId((words[i] + " " + words[i + 1])));
            trigram_feats.push_back(
                    mFeatures[2].getId(
                            (words[i] + " " + words[i + 1] + " " + words[i + 2])));
        }
    }
    double score = 0;
    for (auto uni_itr : unigram_feats) {
        score += mWeights[0][uni_itr];
    }
    for (auto big_itr : bigram_feats) {
        score += mWeights[1][big_itr];
    }
    for (auto tri_itr : trigram_feats) {
        score += mWeights[2][tri_itr];
    }
    if (score >= 0) {
        return 1;
    } else {
        return -1;
    }
}
