/*
 * perceptron.h
 *
 *  Created on: 2016/09/05
 *      Author: ryosuke-k
 */

#ifndef PERCEPTRON_H_
#define PERCEPTRON_H_

#include <string>
#include <map>
#include <vector>

#include "obs2id.h"
#include "feature.h"

class Perceptron {
public:
    Perceptron(std::vector<std::vector<std::string>> data);
    void Train();
    void CreateFeats();
    std::vector<std::vector<int>>Sentence2Vec(std::vector<std::string>, size_t n);
    int PredictOne(std::vector<std::vector<int>> x);
    void UpdateWeights(std::vector<std::vector<int>> x, int y);
    int Predict(std::string test_sent);
    void InitializeWeights(){
        for (auto feature : mFeatures){
            mWeights.push_back(feature.InitializeWeight());
        }
    };

    std::vector<double> getWeight(int n){
        return mWeights[n];
    }


private:
    std::vector<std::vector<std::string>> mData;
    std::vector<std::vector<int>> mSentFeats;
    std::vector<std::vector<std::string>> mSentWords;
    std::vector<int> mAnswer;
    std::vector<std::vector<std::vector<int>>> mSentence_vectors;
    std::vector<Feature> mFeatures;
    std::vector<std::vector<double>> mWeights;
};





#endif /* PERCEPTRON_H_ */
