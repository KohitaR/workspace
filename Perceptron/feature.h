/*
 * createfeats.h
 *
 *  Created on: 2016/09/05
 *      Author: ryosuke-k
 */

#ifndef FEATURE_H_
#define FEATURE_H_

#include <map>
#include <vector>

class Feature {
public:
    Feature(){};
    Feature(const Feature &rhs);
    int setFeature(std::string feats);
    int getId(std::string feats);
    std::string getFeature(int id);
    void saveSentFeats();


    int size() {
        return mFeats2Id.size();
    }
    ;

    std::vector<int> getSentFeats(int n) {
        return mEachSentFeats[n];
    }
    ;
    std::vector<double> InitializeWeight() {
        for (int i = 0; i < mFeats2Id.size(); ++i){
            mWeight.push_back(0.0);
        }
        return mWeight;
    };

private:
    std::map<std::string, int> mFeats2Id;
    std::map<int, std::string> mId2Feats;
    std::vector<double> mWeight;
    std::vector<std::vector<int>> mEachSentFeats;
    std::vector<int> temp_eachsent;
};

#endif /* FEATURE_H_ */
