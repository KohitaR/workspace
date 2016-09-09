/*
 * vocab2int.h
 *
 *  Created on: 2016/09/03
 *      Author: ryosuke-k
 */

#ifndef VOCAB2ID_H_
#define VOCAB2ID_H_

#include <map>
#include <string>
#include <set>

class Vocab2id{
public:
    int setVocab(std::string word);
    int getId(std::string word);
    std::string getWord(int id);
    int size(){
        return mVocab2Id.size();
    }
private:
    std::map<std::string, int> mVocab2Id;
    std::map<int, std::string> mId2Vocab;
};



#endif /* VOCAB2ID_H_ */
