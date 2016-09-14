/*
 * perceptron.h
 *
 *  Created on: 2016/09/09
 *      Author: ryosuke-k
 */

#ifndef PERCEPTRON_H_
#define PERCEPTRON_H_

#include <vector>

using ActionVector = std::vector<double>;

class Perceptron {
public:
    void InitializeWeights(const std::size_t& lemma, const std::size_t& pos);
    int CalcScore(const std::vector<int>& x);
    std::vector<int> CalcScoreMulti(const std::vector<int>& x);
    void Update(const int& pred, const int& oracle, const std::vector<int>& x);

private:
    std::vector<std::vector<std::vector<double>>> Weights_;
    // [S1POS[lWeight(double), rWeight, sWeight], S2Lemma[] ... ]
};


#endif /* PERCEPTRON_H_ */
