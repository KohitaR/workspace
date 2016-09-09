/*
 * conllu.cpp
 *
 *  Created on: 2016/09/03
 *      Author: ryosuke-k
 */

#include "conllu.h"
#include "utils.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>
#include <vector>

using namespace std;

Conllu::Conllu() :
        mId(0), mForm(0), mLemma(0), mUpostag(0), mXpostag(0), mFeats(0), mHead(
                0), mDeprel(0), mDeps(0), mMisc(0) {
}

Conllu::Conllu(string id, string form, string lemma, string upostag,
        string xpostag, string feats, string head, string deprel, string deps,
        string misc) :
        mId(id), mForm(form), mLemma(lemma), mUpostag(upostag), mXpostag(
                xpostag), mFeats(feats), mHead(head), mDeprel(deprel), mDeps(
                deps), mMisc(misc) {
}

void Conllu::Print_As_Conllu() {
    cout << mId << "\t" << mForm << "\t" << mLemma << "\t" << mUpostag << "\t"
            << mXpostag << "\t" << mFeats << "\t" << mHead << "\t" << mDeprel
            << "\t" << mDeps << "\t" << mMisc << endl;
}

string Conllu::get_ID() {
    return mId;
}

string Conllu::getLemma() {
    return mLemma;
}

string Conllu::getUpostag() {
    return mUpostag;
}

vector<vector<Conllu>> readconllu(string filename) {
    ifstream ifs(filename);

    if (!ifs) {
        cout << "file read error" << endl;
        exit(1);
    }

    string str;
    vector<Conllu> sentence;
    vector<vector<Conllu>> sentences;
    regex pattern1("# S-ID:[0-9]*-[0-9]*");
    regex pattern2("");

    while (getline(ifs, str)) {
        if (regex_match(str, pattern1)) {
            continue;
        } else if (regex_match(str, pattern2)) {
            sentences.push_back(sentence);
            sentence.clear();
            continue;
        } else {
            char separator = '\t';
            vector<string> v = split(str, separator);
            Conllu token(v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8],
                    v[9]);
            sentence.push_back(token);
        }
    }
    return sentences;
}


vector<vector<string>> readtest(string filename){
    ifstream ifs(filename);

    if (!ifs) {
        cout << "file read error" << endl;
        exit(1);
    }
    string str;
    vector<string> sentence;
    vector<vector<string>> sentences;
    regex pattern1("# S-ID:[0-9]*-[0-9]*");
    regex pattern2("");

    while (getline(ifs, str)) {
        if (regex_match(str, pattern1)) {
            continue;
        } else if (regex_match(str, pattern2)) {
            sentences.push_back(sentence);
            sentence.clear();
            continue;
        } else {
            char separator = '\t';
            vector<string> v = split(str, separator);
            sentence.push_back(v[1]);
        }
    }
    return sentences;
}
