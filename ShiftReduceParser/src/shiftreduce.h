/*
 * shiftreduce.h
 *
 *  Created on: 2016/09/12
 *      Author: ryosuke-k
 */

#ifndef SHIFTREDUCE_H_
#define SHIFTREDUCE_H_

#include <vector>
#include <unordered_map>

#include "feature.h"
#include "conllu.h"
#include "obs2id.h"
#include "perceptron.h"
#include "oracle.h"

class ShiftReduce: public Feature, public Perceptron, public Oracle {
public:
    ShiftReduce(const std::vector<std::vector<Conllu>> data, const size_t vocab,
            const size_t pos);

    void Action(int n);
    void Action(std::vector<int> actions);
    void Left();
    void Right();
    void Shift();

    void InitializeState(std::vector<Conllu>& sentence);

    void Train();
//    void Test(std::vector<Conllu>& testsentence);
    std::vector<int> Test(std::vector<std::vector<Conllu>>& testsentence);

private:

    Conllu root_;
    const size_t vocab_;
    const size_t pos_;
    std::vector<std::vector<Conllu>> sentences_;
    std::vector<Conllu> stack_;
    std::vector<Conllu> buffer_;
    std::vector<std::vector<int>> oracle_;
    std::unordered_map<int, int> heads_;

};

#endif /* SHIFTREDUCE_H_ */
