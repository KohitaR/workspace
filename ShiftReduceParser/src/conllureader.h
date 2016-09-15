/*
 * conllureader.h
 *
 *  Created on: 2016/09/12
 *      Author: ryosuke-k
 */

#ifndef CONLLUREADER_H_
#define CONLLUREADER_H_

#include <iostream>
#include <vector>
#include <unordered_map>

#include "obs2id.h"
#include "conllu.h"

class ConlluReader : public Conllu{
public:
    ConlluReader();

    std::vector<std::vector<Conllu>>ReadConllu(std::string filename);

    const std::size_t getVocabSize() const;
    const std::size_t getPosSize() const;

    bool checkProj(std::vector<Conllu> sentence);


private:
    Obs2Id<std::string, std::hash<std::string>> FormId_;
    Obs2Id<std::string, std::hash<std::string>> LemmaId_;
    Obs2Id<std::string, std::hash<std::string>> UposTagId_;
    Obs2Id<std::string, std::hash<std::string>> XposTagId_;
    Obs2Id<std::string, std::hash<std::string>> FeatsId_;
    Obs2Id<std::string, std::hash<std::string>> DeprelId_;
    Obs2Id<std::string, std::hash<std::string>> DepsId_;
    Obs2Id<std::string, std::hash<std::string>> MiscId_;
};




#endif /* CONLLUREADER_H_ */
