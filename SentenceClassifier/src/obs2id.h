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

template <typename Key, typename Hash>
class Obs2Id{
public:

    inline size_t size(){
      return mObs2Id.size();
    };

    //Template
    inline int setObs(Key obs){
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

    inline int getId(Key obs) const{
        auto itr = mObs2Id.find(obs);
        if (itr == mObs2Id.end()) {
            return -1;
        } else {
            return itr->second;
        }
    };

    inline int getObs(int id) {
        auto itr = mId2Obs.find(id);
        if (itr == mId2Obs.end()) {
            return mId2Obs[-1];
        } else {
            return mId2Obs[id];
        }
    };

    inline std::unordered_map<int, Key> getMap(){
        return mId2Obs;
    };

private:
    std::unordered_map<Key, int, Hash> mObs2Id;
    std::unordered_map<int, Key> mId2Obs;
};
#endif /* OBS2ID_H_ */
