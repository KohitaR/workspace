/*
 * oracle.cpp
 *
 *  Created on: 2016/09/13
 *      Author: ryosuke-k
 */

#include <vector>
#include <iostream>
#include "oracle.h"

using namespace std;

int Oracle::getOracle(vector<Conllu>& stack, vector<Conllu>& buffer) {
    auto s_top1 = stack.end() - 1;
    auto s_top2 = stack.end() - 2;

    if (stack.size() < 2) {
        return 2;
    } else if (buffer.size() == 0 and s_top1->getHead() == 0
            and s_top2->getId() == 0) {
        return 1;
    } else if (s_top1->getHead() == s_top2->getId() and s_top2->getId() != 0
            and s_top1->childN == 0) {
        return 1;
    } else if (s_top2->getHead() == s_top1->getId() and s_top2->childN == 0) {
        return 0;
    } else {
        return 2;
    }
}
