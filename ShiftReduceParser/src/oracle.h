/*
 * oracle.h
 *
 *  Created on: 2016/09/13
 *      Author: ryosuke-k
 */

#ifndef ORACLE_H_
#define ORACLE_H_

#include <vector>
#include "conllu.h"

class Oracle {
public:
    int getOracle(std::vector<Conllu>& stack_, std::vector<Conllu>& buffer_);

private:
};

#endif /* ORACLE_H_ */
