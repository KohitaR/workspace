/*
 * obs2id.h
 *
 *  Created on: 2016/09/05
 *      Author: ryosuke-k
 */

#ifndef OBS2ID_H_
#define OBS2ID_H_

#include <string>
#include <map>

class Obs2Id{
public:
    int setObs(std::string obs);
    int getId(std::string obs);
    std::string getObs(int id);
    size_t size();
private:
    std::map<std::string, int> mObs2Id;
    std::map<int, std::string> mId2Obs;
};
#endif /* OBS2ID_H_ */
