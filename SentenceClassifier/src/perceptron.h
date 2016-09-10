/*
 * perceptron.h
 *
 *  Created on: 2016/09/09
 *      Author: ryosuke-k
 */

#ifndef PERCEPTRON_H_
#define PERCEPTRON_H_

class Perceptron {
public:
    void InitializeWeight(std::vector<double> w);
    int CalcScore(std::vector<int> x);
    void Update(std::vector<int> x, int y);

private:
    std::vector<double> mWeight;
};


#endif /* PERCEPTRON_H_ */
