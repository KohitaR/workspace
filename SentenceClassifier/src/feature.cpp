/*
 * feature.cpp
 *
 *  Created on: 2016/09/09
 *      Author: ryosuke-k
 */

#include <iostream>
#include <vector>
#include <algorithm>

#include "feature.h"

using namespace std;

vector<vector<int>> Feature::CreateFeature(vector<vector<int>> sentences) {
    int start = 0;
    int end = 1;
    int word_i, word_ip1, word_ip2;
    vector<int> sentence_feats;
    for (auto sentence : sentences) {
        size_t n = sentence.size();
        for (size_t i = 0; i < n; ++i) {
            word_i = sentence[i];
            word_ip1 = sentence[i + 1];
            word_ip2 = sentence[i + 2];
            if (i == 0) {
                sentence_feats.push_back(pushFeature( { word_i }));
                sentence_feats.push_back(pushFeature( { start, word_i }));
                sentence_feats.push_back(
                        pushFeature( { start, word_i, word_ip1 }));
            } else if (i == n - 1) {
                sentence_feats.push_back(pushFeature( { word_i }));
                sentence_feats.push_back(pushFeature( { word_i, end }));
            } else if (i == n - 2) {
                sentence_feats.push_back(pushFeature( { word_i }));
                sentence_feats.push_back(pushFeature( { word_i, word_ip1 }));
                sentence_feats.push_back(
                        pushFeature( { word_i, word_ip1, end }));
            } else {
                sentence_feats.push_back(pushFeature( { word_i }));
                sentence_feats.push_back(pushFeature( { word_i, word_ip1 }));
                sentence_feats.push_back(pushFeature( { word_i, word_ip1,
                        word_ip2 }));
            }
        }
        mTrainSentVec.push_back(sentence_feats);
        sentence_feats.clear();
    }
    return mFeature;
}

vector<vector<int>> Feature::getFeature() {
    return mFeature;
}

int Feature::pushFeature(vector<int> feature) {
    auto itr = find(mFeature.begin(), mFeature.end(), feature);
    if (itr == mFeature.end()) {
        mFeatureN += 1;
        cout << "Creating new feature ..." << mFeatureN << endl;
        mFeature.push_back(feature);
        return mFeature.size()-1;
    } else {
        return distance(mFeature.begin(), itr);
    }
}

vector<vector<int>> Feature::getSentVec() {
    return mTrainSentVec;
}

vector<vector<int>> Feature::getSentVec(vector<vector<int>> sentences) {
    int start = 0;
    int end = 1;
    int word_i, word_ip1, word_ip2;
    vector<int> sentence_feats;
    for (auto sentence : sentences) {
        size_t n = sentence.size();
        for (size_t i = 0; i < n; ++i) {
            word_i = sentence[i];
            word_ip1 = sentence[i + 1];
            word_ip2 = sentence[i + 2];
            int d;
            if (i == 0) {
                d = getIndex({word_i});
                if (d != -1){sentence_feats.push_back(d);}

                d = getIndex({ start, word_i});
                if (d != -1){sentence_feats.push_back(d);}

            } else if (i == n - 1) {
                d = getIndex({word_i});
                if (d != -1){sentence_feats.push_back(d);}

                d = getIndex({ word_i, end });
                if (d != -1){sentence_feats.push_back(d);}


            } else if (i == n - 2) {
                d = getIndex({word_i});
                if (d != -1){sentence_feats.push_back(d);}

                d = getIndex({ word_i, word_ip1 });
                if (d != -1){sentence_feats.push_back(d);}
//
//                d = getIndex({ word_i, word_ip1, end });
//                if (d != -1){sentence_feats.push_back(d);}

            } else {
                d = getIndex({word_i});
                if (d != -1){sentence_feats.push_back(d);}

                d = getIndex({ word_i, word_ip1 });
                if (d != -1){sentence_feats.push_back(d);}
//
//                d = getIndex({ word_i, word_ip1, word_ip2 });
//                if (d != -1){sentence_feats.push_back(d);}
            }
        }
        mTestSentVec.push_back(sentence_feats);
        sentence_feats.clear();
    }
    return mTestSentVec;
}


int Feature::getIndex(vector<int> feature){
    auto itr = find(mFeature.begin(), mFeature.end(), feature);
    if (itr != mFeature.end()){
        return distance(mFeature.begin(), itr);
    }
    return -1;
}
