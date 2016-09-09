/*
 * createfests.cpp
 *
 *  Created on: 2016/09/05
 *      Author: ryosuke-k
 */
#include <map>
#include <string>
#include <iostream>

#include "feature.h"

using namespace std;


Feature::Feature(const Feature &rhs) :
        mFeats2Id(rhs.mFeats2Id), mId2Feats(rhs.mId2Feats), mWeight(rhs.mWeight), mEachSentFeats(
                rhs.mEachSentFeats), temp_eachsent(rhs.temp_eachsent) {
}


int Feature::setFeature(string feature) {
    auto itr = mFeats2Id.find(feature);
    int id;
    if (itr == mFeats2Id.end()) {
        id = mFeats2Id.size();
        mFeats2Id[feature] = id;
        mId2Feats[id] = feature;
        temp_eachsent.push_back(id);
        return id;
    } else {
        id = itr->second;
        temp_eachsent.push_back(id);
        return id;
    }
}

int Feature::getId(string feature) {
    auto itr = mFeats2Id.find(feature);
    if (itr == mFeats2Id.end()) {
        return 0;
    } else {
        return itr->second;
    }
}

string Feature::getFeature(int id) {
    auto itr = mId2Feats.find(id);
    if (itr == mId2Feats.end()) {
        return "<UNK>";
    } else {
        return itr->second;
    }
}

void Feature::saveSentFeats(){
    mEachSentFeats.push_back(temp_eachsent);
    temp_eachsent.clear();
}

