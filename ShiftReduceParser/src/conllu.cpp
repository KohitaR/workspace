/*
 * conllu.cpp
 *
 *  Created on: 2016/09/12
 *      Author: ryosuke-k
 */

#include <iostream>
#include <vector>
#include "conllu.h"

using namespace std;


void Conllu::setToken(int id, int form, int lemma, int upostag, int xpostag,
        int feats, int head, int deprel, int deps, int misc) {
    id_ = id;
    form_ = form;
    lemma_ = lemma;
    upostag_ = upostag;
    xpostag_ = xpostag;
    feats_ = feats;
    head_ = head;
    deprel_ = deprel;
    deps_ = deps;
    misc_ = misc;
}

void Conllu::pushChild(int id) {
    children_.push_back(id);
}

size_t Conllu::getChildrenSize() {
    return children_.size();
}

int Conllu::getId() const {
    return id_;
}

int Conllu::getLemma() const {
    return lemma_;
}

int Conllu::getPos() const {
    return upostag_;
}

int Conllu::getHead() const {
    return head_;
}

void Conllu::PrintConllu() {
    cout << id_ << "\t" << form_ << "\t" << lemma_ << "\t" << upostag_ << "\t"
            << xpostag_ << "\t" << feats_ << "\t" << head_ << "\t" << deprel_
            << "\t" << deps_ << "\t" << misc_ << endl;
}
