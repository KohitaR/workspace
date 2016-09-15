/*
 * conllureader.cpp
 *
 *  Created on: 2016/09/12
 *      Author: ryosuke-k
 */

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <regex>
#include <typeinfo>
#include <cmath>

#include "conllureader.h"
#include "conllu.h"
#include "utils.h"

using namespace std;

ConlluReader::ConlluReader() {
    Conllu* token;
    token = new Conllu;
    token->setToken(0, FormId_.setObs("ROOT"), LemmaId_.setObs("ROOT"),
            UposTagId_.setObs("ROOT"), XposTagId_.setObs("ROOT"),
            FeatsId_.setObs("ROOT"), DeprelId_.setObs("ROOT"), 0,
            DepsId_.setObs("ROOT"), MiscId_.setObs("ROOT"));
    delete token;
}

vector<vector<Conllu>> ConlluReader::ReadConllu(string filename) {

    ifstream ifs(filename);

    if (!ifs) {
        cout << "file read error" << endl;
        exit(1);
    }

    string str;
    char separator = '\t';
    Conllu* token;
    vector<Conllu> sentence;
    vector<vector<Conllu>> sentences;
    regex pattern1("# S-ID:[0-9]*-[0-9]*");
    regex pattern2("");

    while (getline(ifs, str)) {
        if (regex_match(str, pattern1)) {
            continue;
        } else if (regex_match(str, pattern2)) {
            for (auto token : sentence) {
                if (token.getHead() != 0) {
                    sentence[token.getHead() - 1].pushChild(token.getId());
                }
            }
            if (checkProj(sentence)){
                sentences.push_back(sentence);
                sentence.clear();
            }else{
                sentence.clear();
            }
        } else {
            vector<string> v;
            v = split(str, separator);
            token = new Conllu;
            token->setToken(stoi(string(v[0])), FormId_.setObs(v[1]),
                    LemmaId_.setObs(v[2]), UposTagId_.setObs(v[3]),
                    XposTagId_.setObs(v[4]), FeatsId_.setObs(v[5]),
                    stoi(string(v[6])), DeprelId_.setObs(v[7]),
                    DepsId_.setObs(v[8]), MiscId_.setObs(v[9]));
            sentence.push_back(*token);
            delete token;
        }
    }
    return sentences;
}

const size_t ConlluReader::getVocabSize() const {
    return LemmaId_.size();
}
;

const std::size_t ConlluReader::getPosSize() const {
    return UposTagId_.size();
}
;

bool ConlluReader::checkProj(vector<Conllu> sentence) {
    for (auto token : sentence) {
        int id = token.getId();
        int head = token.getHead();
        int dist = abs(id - head);

        if (dist != 1 and head != 0) {
            if (id < head) {
                for (int i = id; i != head - 1; ++i) {
                    int c_head = sentence[i].getHead();
                    if (c_head < id or c_head > head) {
                        return false;
                    }
                }
            } else {
                for (int i = head; i != id - 1; ++i) {
                    int c_head = sentence[i].getHead();
                    if (c_head < head or c_head > id) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

