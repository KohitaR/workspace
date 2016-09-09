/*
 * viterbi.cpp
 *
 *  Created on: 2016/09/02
 *      Author: ryosuke-k
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <ostream>

#include "viterbi.h"
#include "utils.h"
#include "vocab2id.h"

using namespace std;

Viterbi::Viterbi(map<vector<int>, double> transition,
        map<vector<int>, double> emission, Vocab2id state, Vocab2id observe) :
        mTra(transition), mEmi(emission), mState(state), mObs(observe) {
}

bool Viterbi::Search(vector<int> tar, map<vector<int>, double> mp) {
    auto itr = mp.find(tar);
    if (itr != mp.end()) {
        return true;
    } else {
        return false;
    }
}

double Viterbi::CalcScore(vector<int> i_here, vector<int> here_next,
        vector<int> next_obs, map<vector<int>, double> best_scores) {
    double s(best_scores[i_here] + mTra[here_next] + mEmi[next_obs]);
    return s;
}

map<vector<int>, vector<int>> Viterbi::Forward(vector<string> sequence) {
    map<vector<int>, double> best_scores;
    map<vector<int>, double> temp_scores;
    map<vector<int>, vector<int>> best_edge;
    int n(sequence.size());
    vector<int> i_here;
    vector<int> here_next;
    vector<int> next_obs;
    vector<int> i_next;

    double score;

    int start_id = mState.getId("<s>");
    best_scores[ { 0, start_id }] = 0;
    temp_scores[ { 0, start_id }] = 0;
    best_edge[ {0, start_id} ] = {};
    for (int i = 0; i < n - 1; ++i) {
        cout << i << endl;
        for (int here = 0; here != mState.size(); ++here) {
            for (int next = 0; next != mState.size(); ++next) {
                i_here = {i, here};
                here_next = {here, next};
                next_obs = {next, mObs.getId(sequence[i])};



                if (Search(i_here, best_scores)
                        and Search(here_next, mTra)) {
                    score = CalcScore(i_here, here_next, next_obs,
                            best_scores);
                    i_next = {i+1, next};
                    if (!Search(i_next, best_scores)
                            or best_scores[i_next] < score) {
                        best_scores[i_next] = score;
                        temp_scores[i_next] = score;
                        best_edge[i_next] = i_here;
                    }
                }
            }
        }
        best_scores.clear();
        best_scores = temp_scores;
        temp_scores.clear();
    }
    // END
    for (int here = 0; here != mState.size(); ++here) {
        for (int next = 0; next != mState.size(); ++next) {
            i_here = {n-1, here};
            here_next = {here, next};
            i_next = {n, next};
            vector<int> next_end = {next, mState.getId("</s>")};
            vector<int> i_end = {n+1, mState.getId("</s>")};
            next_obs = {next, mObs.getId(sequence[n-1])};
            if (Viterbi::Search(i_here, best_scores)
                    and Viterbi::Search(here_next, mTra)
                    and Viterbi::Search(next_end, mTra)) {
                score = Viterbi::CalcScore(i_here, here_next, next_obs,
                        best_scores) + mTra[next_end];
                if (!Viterbi::Search(i_next, best_scores)
                        or best_scores[i_next] < score) {
                    best_scores[i_next] = score;
                    best_edge[i_next] = i_here;
                    best_edge[i_end] = i_next;
                }
            }
        }
    }
    return best_edge;
}

vector<int> Viterbi::Backward(map<vector<int>, vector<int>> best_edge, int n) {
    vector<int> best_path;
    vector<int> str;
    vector<int> next_edge = best_edge[{n+1, mState.getId("</s>")}];
    vector<int> start = {0, mState.getId("<s>")};

    while (next_edge != start) {
        best_path.push_back(next_edge[1]);
        next_edge = best_edge[next_edge];
    }
    reverse(best_path.begin(), best_path.end());
    return best_path;
}

