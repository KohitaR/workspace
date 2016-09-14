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

#include "conllu.h"
#include "obs2id.h"


class Feature {
public:
    std::vector<int> getFeats(
            const std::vector<Conllu> &stack,
            const std::vector<Conllu> &buffer);

private:
};


#endif /* FEATURE_H_ */
