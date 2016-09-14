/*
 * perceptron.cpp
 *
 *  Created on: 2016/09/09
 *      Author: ryosuke-k
 */

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <random>
#include "perceptron.h"

using namespace std;
std::random_device rnd;     // 非決定的な乱数生成器を生成
std::mt19937 mt(rnd());     //  メルセンヌ・ツイスタの32ビット版、引数は初期シード値
std::uniform_int_distribution<> rand100(1, 99);        // [0, 99] 範囲の一様乱数

void Perceptron::InitializeWeights(const size_t& lemma, const size_t& pos) {
    vector<double> pos_v(pos, 0);
    vector<vector<double>> pos_vs = { pos_v, pos_v, pos_v };
    vector<double> lemma_v(lemma, 0);
    vector<vector<double>> lemma_vs = { lemma_v, lemma_v, lemma_v };

    Weights_.push_back(pos_vs);
    Weights_.push_back(lemma_vs);
    Weights_.push_back(pos_vs);
    Weights_.push_back(lemma_vs);
    Weights_.push_back(pos_vs);
    Weights_.push_back(lemma_vs);
}

int Perceptron::CalcScore(const vector<int>& x) {
    double lScore(0), rScore(0), sScore(0);

    for (size_t i = 0; i != x.size(); ++i) {
        if (x[i] == -1) {
            continue;
        }

        lScore += Weights_[i][0][x[i]];
        rScore += Weights_[i][1][x[i]];
        sScore += Weights_[i][2][x[i]];

    }
    return lScore > rScore and lScore > sScore ? 0 : rScore > sScore ? 1 : 2;
}

vector<int> Perceptron::CalcScoreMulti(const vector<int>& x) {
    double lScore(0), rScore(0), sScore(0);

    for (size_t i = 0; i != x.size(); ++i) {
        if (x[i] == -1) {
            continue;
        }

        lScore += Weights_[i][0][x[i]];
        rScore += Weights_[i][1][x[i]];
        sScore += Weights_[i][2][x[i]];
    }

    unordered_map<double, int> temp_mp;
    temp_mp[lScore] = 0;
    temp_mp[rScore] = 1;
    temp_mp[sScore] = 2;

    vector<double> temp_v { lScore, rScore, sScore };
    sort(temp_v.begin(), temp_v.end());

    vector<int> return_v{temp_mp[temp_v[0]], temp_mp[temp_v[1]], temp_mp[temp_v[2]]};
    return return_v;
}

void Perceptron::Update(const int& pred, const int& oracle,
        const vector<int>& x) {
    double a = 0.1;
    for (size_t i = 0; i != x.size(); ++i) {
        if (x[i] == -1) {
            continue;
        }

        Weights_[i][pred][x[i]] -= 1 * rand100(mt)/1000000.0;
        Weights_[i][oracle][x[i]] += 1* rand100(mt)/1000000.0;
    }
}
