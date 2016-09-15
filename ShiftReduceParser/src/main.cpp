/*
 * main.cpp
 *
 *  Created on: 2016/09/12
 *      Author: ryosuke-k
 */

#include <vector>
#include <iostream>
#include <time.h>

#include "conllureader.h"
#include "shiftreduce.h"

using namespace std;

int main() {
    ConlluReader reader;
    vector<vector<Conllu>> sentences = reader.ReadConllu(
            "/home/ryosuke-k/workspace/data/en-ud-dev.conllu");

    ShiftReduce parser(sentences, reader.getVocabSize(), reader.getPosSize());
    parser.Train();
    cout << "END" << endl;

    vector<vector<Conllu>> test_sentences = reader.ReadConllu(
            "/home/ryosuke-k/workspace/data/en-ud-dev.conllu");
    int n = 0;
    clock_t start = clock();
    vector<int> v = parser.Test(test_sentences);
    clock_t end = clock();
    cout << "Accuracy : " << v[1] / static_cast<double>(v[0]) << endl;
    cout << "Sentence : " << test_sentences.size() << endl;
    cout << "Time     : " << (double) (end - start) / CLOCKS_PER_SEC << "sec."
            << endl;

}
