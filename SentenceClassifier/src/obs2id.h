/*
 * obs2id.h
 *
 *  Created on: 2016/09/05
 *      Author: ryosuke-k
 */

#ifndef OBS2ID_H_
#define OBS2ID_H_

#include <string>
#include <unordered_map>

template <typename T>
class Obs2Id{
public:

    inline size_t size(){
      return mObs2Id.size();
    };

    //Template
    inline int setObs(T obs){
        auto itr = mObs2Id.find(obs);
        if (itr == mObs2Id.end()) {
            int id = mObs2Id.size();
            mObs2Id[obs] = id;
            mId2Obs[id] = obs;
            return id;
        } else {
            return mObs2Id[obs];
        }
    };

    inline int getId(T obs) const{
        auto itr = mObs2Id.find(obs);
        if (itr == mObs2Id.end()) {
            return -1;
        } else {
            return itr->second;
        }
    };

    inline T getObs(int id) {
        auto itr = mId2Obs.find(id);
        if (itr == mId2Obs.end()) {
            return mId2Obs[-1];
        } else {
            return mId2Obs[id];
        }
    };


private:
    std::unordered_map<T, int> mObs2Id;
    std::unordered_map<int, T> mId2Obs;
};
#endif /* OBS2ID_H_ */
