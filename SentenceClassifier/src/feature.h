/*
 * feature.h
 *
 *  Created on: 2016/09/09
 *      Author: ryosuke-k
 */

#ifndef FEATURE_H_
#define FEATURE_H_

#include <vector>
#include <unordered_map>
#include "obs2id.h"

class HashVI {  // ハッシュ関数オブジェクト
public:
    size_t operator()(const std::vector<int> &x) const {
        const int C = 997;      // 素数
        size_t t = 0;
        for (size_t i = 0; i != x.size(); ++i) {
            t = t * C + x[i];
        }
        return t;
    }
};

class Feature : public Obs2Id<std::vector<int>, HashVI>{
public:
    std::unordered_map<int, std::vector<int>> CreateFeature(
            std::vector<std::vector< int>> sentences);

    std::vector<std::vector< int>> getSentVec();
    std::vector<std::vector<int>> getSentVec(std::vector<std::vector<int>> sentences);


private:
    std::vector<std::vector< int>> mTrainSentVec;
    std::vector<std::vector< int>> mTestSentVec;
    int mFeatureN;

};
#endif /* FEATURE_H_ */
