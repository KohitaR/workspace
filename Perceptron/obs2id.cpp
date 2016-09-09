/*
 * obs2id.cpp
 *
 *  Created on: 2016/09/05
 *      Author: ryosuke-k
 */

#include <map>
#include <string>
#include <vector>

#include "obs2id.h"

using namespace std;

int Obs2Id::setObs(string word) {
    auto itr = mObs2Id.find(word);
    if (itr == mObs2Id.end()) {
        int id = mObs2Id.size();
        mObs2Id[word] = id;
        mId2Obs[id] = word;
        return id;
    } else {
        return mObs2Id[word];
    }
}

int Obs2Id::getId(string word) {
    auto itr = mObs2Id.find(word);
    if (itr == mObs2Id.end()) {
        return -1;
    } else {
        return mObs2Id[word];
    }
}

string Obs2Id::getObs(int id) {
    auto itr = mId2Obs.find(id);
    if (itr == mId2Obs.end()) {
        return "<UNK>";
    } else {
        return mId2Obs[id];
    }
}
