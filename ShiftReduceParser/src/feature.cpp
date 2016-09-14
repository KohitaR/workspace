/*
 * feature.cpp
 *
 *  Created on: 2016/09/13
 *      Author: ryosuke-k
 */

#include <vector>

#include "feature.h"

using namespace std;

vector<int> Feature::getFeats(const std::vector<Conllu>& stack,
        const std::vector<Conllu> &buffer) {
    auto s_top = (stack.end() - 1);
    auto s_top2 = (stack.end() - 2);
    auto b_top = (buffer.end() - 1);

    if (buffer.size() > 0) {
        if (stack.size() == 1) {
            vector<int> feats { s_top->getPos(), s_top->getLemma(), -1, -1,
                    b_top->getPos(), b_top->getLemma() };
            return feats;
        } else {
            vector<int> feats { s_top->getPos(), s_top->getLemma(),
                    s_top2->getPos(), s_top2->getLemma(), b_top->getPos(),
                    b_top->getLemma() };
            return feats;
        }
    } else {
        if (stack.size() == 1) {
            vector<int> feats { s_top->getPos(), s_top->getLemma(), -1, -1, -1,
                    -1 };
            return feats;
        } else {
            vector<int> feats { s_top->getPos(), s_top->getLemma(),
                    s_top2->getPos(), s_top2->getLemma(), -1, -1 };
            return feats;
        }
    }
}
