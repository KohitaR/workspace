/*
 * viterbi.h
 *
 *  Created on: 2016/09/02
 *      Author: ryosuke-k
 */

#ifndef VITERBI_H_
#define VITERBI_H_

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>

#include "vocab2id.h"

class Viterbi {
public:
    Viterbi(std::map<std::vector<int>, double> transition,
            std::map<std::vector<int>, double> emission, Vocab2id state,
            Vocab2id observe);

    std::map<std::vector<int>, std::vector<int>> Forward(
            std::vector<std::string> sequence);
    std::vector<int> Backward(
            std::map<std::vector<int>, std::vector<int>> mp, int n);


    bool Search(std::vector<int> tar, std::map<std::vector<int>, double> mp);
    double CalcScore(std::vector<int> i_here, std::vector<int> here_next,
            std::vector<int> next_obs,
            std::map<std::vector<int>, double> best_scores);
private:
    std::map<std::vector<int>, double> mTra;
    std::map<std::vector<int>, double> mEmi;
    Vocab2id mState;
    Vocab2id mObs;

};

#endif /* VITERBI_H_ */
