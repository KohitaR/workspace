/*
 * readdata.h
 *
 *  Created on: 2016/09/08
 *      Author: ryosuke-k
 */

#ifndef DATALOAD_H_
#define DATALOAD_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "obs2id.h"

class DataLoader {
public:
    std::vector< std::vector<int> > load_train(std::string filename);
    std::vector<int> getLabels(std::string type);
    std::vector<std::vector<int>> load_test(std::string filename);
    Obs2Id getWordIdMap();


private:
    std::vector<std::vector<int>> mTrainSentences;
    std::vector<std::vector<int>> mTestSentences;
    std::vector<int> mGoldLabel;
    std::vector<int> mTestLabel;

    Obs2Id mWordIdMap;


};


#endif /* DATALOAD_H_ */
