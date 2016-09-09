/*
 * vocab2int.cpp
 *
 *  Created on: 2016/09/03
 *      Author: ryosuke-k
 */

#include <map>
#include <string>
#include <vector>
#include <string>

#include "vocab2id.h"

using namespace std;

int Vocab2id::setVocab(string word) {
    auto itr = mVocab2Id.find(word);
    if (itr == mVocab2Id.end()) {
        int id = mVocab2Id.size();
        mVocab2Id[word] = id;
        mId2Vocab[id] = word;
        return id;
    } else {
        return itr->second;
    }
}

int Vocab2id::getId(string word) {
    auto itr = mVocab2Id.find(word);
    if (itr == mVocab2Id.end()) {
        return -1;
    } else {
        return itr->second;
    }
}

string Vocab2id::getWord(int id) {
    auto itr = mId2Vocab.find(id);
    if (itr == mId2Vocab.end()) {
        return "<UNK>";
    } else {
        return itr->second;
    }
}
