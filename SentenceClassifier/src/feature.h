/*
 * feature.h
 *
 *  Created on: 2016/09/09
 *      Author: ryosuke-k
 */

#ifndef FEATURE_H_
#define FEATURE_H_

#include <vector>

class Feature {
public:
    std::vector<std::vector< int>> CreateFeature(
            std::vector<std::vector< int>> sentences);
    std::vector<std::vector< int>> getFeature();
    int pushFeature(std::vector< int>);

    std::vector<std::vector< int>> getSentVec();

    std::vector<std::vector<int>> getSentVec(std::vector<std::vector<int>> sentences);
    int getIndex(std::vector<int>);


private:
    std::vector<std::vector< int>> mFeature;
    std::vector<std::vector< int>> mTrainSentVec;
    std::vector<std::vector< int>> mTestSentVec;
    int mFeatureN;

};
#endif /* FEATURE_H_ */
