/*
 * conllu.h
 *
 *  Created on: 2016/09/03
 *      Author: ryosuke-k
 */

#ifndef CONLLU_H_
#define CONLLU_H_

#include <string>
#include <vector>
#include <map>

class Conllu {
public:
    Conllu();
    Conllu(std::string id, std::string form, std::string lemma,
            std::string upostag, std::string xpostag, std::string feats,
            std::string head, std::string deprel, std::string deps,
            std::string misc);
    void Print_As_Conllu();
    std::string get_ID();
    std::string getLemma();
    std::string getUpostag();

private:
    std::string mId;
    std::string mForm;
    std::string mLemma;
    std::string mUpostag;
    std::string mXpostag;
    std::string mFeats;
    std::string mHead;
    std::string mDeprel;
    std::string mDeps;
    std::string mMisc;
};

std::vector<std::vector<Conllu>> readconllu(std::string filename);
std::vector<std::vector<std::string>> readtest(std::string filename);

#endif /* CONLLU_H_ */
