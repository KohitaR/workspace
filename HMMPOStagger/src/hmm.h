/*
 * hmm.h
 *
 *  Created on: 2016/09/03
 *      Author: ryosuke-k
 */

#ifndef HMM_H_
#define HMM_H_

#include <vector>
#include <map>
#include <string>
#include <set>

#include "conllu.h"
#include "vocab2id.h"

class HMM {
public:
    HMM(std::vector<std::vector<Conllu>> sentences);

    void CreateModel();

    void OutModel(char* modelfile);
    void ReadModel(char* modelfile);

    std::map<std::vector<int>, double> getTrans() {
        return mTransition_Prob;
    };
    std::map<std::vector<int>, double> getEmi() {
        return mEmission_Prob;
    };

    Vocab2id getPos() {
        return mPos_id_mp;
    }
    Vocab2id getVocab() {
        return mVocab_id_mp;
    }

private:
    std::vector<std::vector<Conllu>> mSentences;

    std::map<int, int> mContext_Count;
    void CountMap(std::map<int, int> *mp, int id);
    std::map<std::vector<int>, int> mTransitionCount;
    std::map<std::vector<int>, int> mEmissionCount;
    void CountMap(std::map<std::vector<int>, int> *mp, std::vector<int>);

    std::map<std::vector<int>, double> mTransition_Prob;
    std::map<std::vector<int>, double> mEmission_Prob;

    Vocab2id mVocab_id_mp;
    Vocab2id mPos_id_mp;

    std::string mModelfile;

    void makeVocab();
    void Count();
    void CalcProb();
};

#endif /* HMM_H_ */
