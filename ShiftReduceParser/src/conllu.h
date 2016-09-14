/*
 * conllu.h
 *
 *  Created on: 2016/09/12
 *      Author: ryosuke-k
 */

#ifndef CONLLU_H_
#define CONLLU_H_

#include <string>
#include <vector>

class Conllu {
public:
    void setToken(int id, int form, int lemma, int upostag, int xpostag,
            int feats, int head, int deprel, int deps, int misc);
    void pushChild(int id);

    int getId() const;
    int getLemma() const;
    int getPos() const;
    int getHead() const;
    size_t getChildrenSize();
    void PrintConllu();

    size_t childN;

private:
    int id_;
    int form_;
    int lemma_;
    int upostag_;
    int xpostag_;
    int feats_;
    int head_;
    int deprel_;
    int deps_;
    int misc_;
    std::vector<int> children_;
};

#endif /* CONLLU_H_ */
