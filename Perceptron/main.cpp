/*
 * main.cpp
 *
 *  Created on: 2016/09/05
 *      Author: ryosuke-k
 */

#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <fstream>


#include "perceptron.h"
#include "utils.h"

using namespace std;

int main(){
    ifstream ifs("/home/ryosuke-k/workspace/data/test-perceptron.txt");
    if (!ifs) {
        cout << "file read error" << endl;
        exit(1);
    };

    string str;
    vector<string> v;
    vector<vector<string>> sentences;

    while (getline(ifs, str)){
        char separator = '\t';
        v = split(str, separator);
        vector<string> words = split(v[1], ' ');
        if (words.size() > 5){
            sentences.push_back({v[0], v[1]});
        };
    };



    Perceptron model(sentences);
    model.Train();

    ifstream test("/home/ryosuke-k/workspace/data/test-perceptron.txt");

    if (!test) {
        cout << "file read error" << endl;
        exit(1);
    };

    int correctN = 0;
    int N = 0;
    while (getline(test, str)){
        char separator = '\t';
        v = split(str, separator);
        vector<string> words = split(v[1], ' ');
        if (words.size() < 5){
            continue;
        }
        int gold = stoi(v[0]);
        int pred = model.Predict(v[1]);
        if (gold == pred){
            correctN++;
            N++;
        } else{
            N++;
        }
    }
    cout << "Accuracy " << double(correctN) / N << "("<< N << ")" <<  endl;
}



