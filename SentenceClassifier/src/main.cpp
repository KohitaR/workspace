/*
 * main.cpp
 *
 *  Created on: 2016/09/08
 *      Author: ryosuke-k
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "dataload.h"
#include "feature.h"
#include "perceptron.h"

using namespace std;

int main() {
    /// Loading data
    DataLoader data;
    vector<vector<int>> sentences = data.load_train("/home/ryosuke-k/workspace/data/titles-en-train.labeled");
    vector<int> gold_labels = data.getLabels("train");

    /// Create features
    Feature feats_creator;
    unordered_map<int, vector<int>> phi = feats_creator.CreateFeature(sentences);
    vector<vector<int>> sentence_vecs = feats_creator.getSentVec();

    Perceptron classifier;
    vector<double> w(phi.size(),0);
    classifier.InitializeWeight(w);
    int i = 0;

    cout << endl;
    cout << "LOADING TEST DATA SET" << endl;
    cout << endl;

    vector<vector<int>> test_sentences = data.load_test("/home/ryosuke-k/workspace/data/titles-en-train.labeled");
    vector<int> test_gold_labels = data.getLabels("test");
    vector<vector<int>> test_sentence_vecs = feats_creator.getSentVec(
            test_sentences);

    while (i < 10) {
        cout << "ITERATION: " << i+1 << endl;
        int pred, gold;
        for (auto sentence = sentence_vecs.begin();
                sentence != sentence_vecs.end(); ++sentence) {
            pred = classifier.CalcScore(*sentence);
            gold = gold_labels[distance(sentence_vecs.begin(), sentence)];
            if (pred != gold) {
                classifier.Update(*sentence, gold);
            }
        }

        int test_pred, test_gold;
        int N = 0;
        int correctN = 0;
        for (int sentence = 0 ; sentence != test_sentence_vecs.size(); ++sentence) {
            test_pred = classifier.CalcScore(test_sentence_vecs[sentence]);
            test_gold = test_gold_labels[sentence];
            if (test_pred == test_gold) {
                N++;
                correctN++;
            } else {
                N++;
            }
        }

        cout << "EVALUATION" << endl;
        cout << "Accuracy: " << double(correctN) / N << endl;
        cout << endl;

        ++i;
    }
}


//    vector<vector<int>> test_sentences = data.load_test("/home/ryosuke-k/workspace/SentenceClassifier/titles-en-test.labeled");
//    vector<int> test_gold_labels = data.getLabels("test");
//    vector<vector<int>> test_sentence_vecs = feats_creator.getSentVec(
//            test_sentences);
//
//    int test_pred, test_gold;
//    int N = 0;
//    int correctN = 0;
//    for (int sentence = 0 ; sentence != test_sentence_vecs.size(); ++sentence) {
//        test_pred = classifier.CalcScore(test_sentence_vecs[sentence]);
//        test_gold = test_gold_labels[sentence];
//        if (test_pred == test_gold) {
//            N++;
//            correctN++;
//        } else {
//            N++;
//        }
//    }
//
//    cout << "EVALUATION" << endl;
//    cout << "Accuracy: " << double(correctN) / N << endl;
//}
//
