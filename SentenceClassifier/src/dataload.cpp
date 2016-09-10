/*
 * datareader.cpp
 *
 *  Created on: 2016/09/08
 *      Author: ryosuke-k
 */




#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <fstream>

#include "dataload.h"

#include "utils.h"
#include "obs2id.h"

using namespace std;

vector< vector<int> > DataLoader::load_train(string filename){

    ifstream ifs(filename);
    if (!ifs) {
        cout << "file read error" << endl;
        exit(1);
    };

    string str;
    int id;
    vector<string> v;
    vector<string> words;
    vector<int> words_id;
    vector<int> label;

    mWordIdMap.setObs("<s>");
    mWordIdMap.setObs("</s>");

    while (getline(ifs, str)){
        char separator = '\t';
        v = split(str, separator);
        words = split(v[1], ' ');

        for (auto word:words){
            id = mWordIdMap.setObs(word);
            words_id.push_back(id);
        }

        if (words_id.size() > 5){
            mGoldLabel.push_back(stoi(v[0]));
            mTrainSentences.push_back(words_id);
            words_id.clear();
        }
    }
    return mTrainSentences;
}

std::vector<int> DataLoader::getLabels(string type){
    if (type == "test"){
        return mTestLabel;
    }else if (type == "train"){
        return mGoldLabel;
    }else{
        cout << "no such label, test or train" << endl;
        exit(1);
    }
}
std::vector<std::vector<int>> DataLoader::load_test(std::string filename){

    ifstream ifs(filename);
    if (!ifs) {
        cout << "test file read error" << endl;
        exit(1);
    };

    string str;
    int id;
    vector<string> v;
    vector<string> words;
    vector<int> words_id;
    vector<int> label;


    while (getline(ifs, str)){
        char separator = '\t';
        v = split(str, separator);
        words = split(v[1], ' ');

        words_id.push_back(mWordIdMap.getId("<s>"));

        for (auto word:words){
            id = mWordIdMap.getId(word);
            words_id.push_back(id);
        }

        if (words_id.size() > 5){
            mTestLabel.push_back(stoi(v[0]));
            words_id.push_back(mWordIdMap.getId("</s>"));
            mTestSentences.push_back(words_id);
            words_id.clear();
        }
    }
    return mTestSentences;
}
