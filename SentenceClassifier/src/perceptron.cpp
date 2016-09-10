/*
 * perceptron.cpp
 *
 *  Created on: 2016/09/09
 *      Author: ryosuke-k
 */




#include <vector>

#include "perceptron.h"

using namespace std;

void Perceptron::InitializeWeight(std::vector<double> w){
    mWeight = w;
}

int Perceptron::CalcScore(vector<int> x){
    double score;
    for (auto itr : x){
        score += mWeight[itr];
    }
    return score > 0 ? 1 : -1;
}

void Perceptron::Update(std::vector<int> x, int y){
    for (auto itr:x){
        mWeight[itr] += y;
    }
}
