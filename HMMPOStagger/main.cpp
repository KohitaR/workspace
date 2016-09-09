/*
 * main.cpp
 *
 *  Created on: 2016/09/03
 *      Author: ryosuke-k
 */

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include "utils.h"
#include "conllu.h"
#include "hmm.h"
#include "viterbi.h"
#include "vocab2id.h"

using namespace std;

//int main(int argc, char* argv[]) {

int main() {

//    if (argc < 3) {
//        cout << "### Missing argument" << endl;
//        cout << "### Arguments: ./HMMPOStagger TRAINING TEST" << endl;
//        return 1;
//    } else if (argc > 3) {
//        cout << "### Too much arguments" << endl;
//        cout << "### Arguments: ./HMMPOStagger TRAINING TEST" << endl;
//    }

//    string train;
//    string test;
//    train = argv[1];
//    test = argv[2];
//    cout << "Training File : " << train << endl;
//    cout << "TestFile : " << test << endl;

    vector<vector<Conllu>> train_sentences = readconllu("./data/ja_ktc-ud-train.conllu.word");
    cout << "Creating model ...." << endl;
    HMM model(train_sentences);
    model.CreateModel();
    model.OutModel("model.txt");

    map<vector<int>, double> tra = model.getTrans();
    map<vector<int>, double> emi = model.getEmi();
    Vocab2id vocab_id_mp = model.getVocab();
    Vocab2id pos_id_mp = model.getPos();

    cout << "Now evaluating ...." << endl;
    vector<vector<string>> test_sentences = readtest("./data/test2");
    vector<vector<Conllu>> eval_sentences = readconllu("./data/test2");

    Viterbi model_viterbi(tra, emi, pos_id_mp, vocab_id_mp);

    ofstream outfile;
    outfile.open("pred.txt", ios::out);
    int N = 0;
    int correct = 0;
    int n = 0;
    for (int i = 0; i < test_sentences.size(); ++i) {
        cout << ++N << endl;
        map<vector<int>, vector<int>> paths = model_viterbi.Forward(
                test_sentences[i]);
        vector<int> best_path = model_viterbi.Backward(paths,
                (test_sentences[i]).size());
        for (int j = 0; j != best_path.size(); ++j) {
            string pred = pos_id_mp.getWord(best_path[j]);
            outfile << eval_sentences[i][j].getLemma() << " "
                    << eval_sentences[i][j].getUpostag() << " "
                    << pred << endl;
            if (eval_sentences[i][j].getUpostag() == pred) {
                correct += 1;
                n += 1;
            } else {
                n += 1;
            }
        }
    }
    cout << "Accuracy : " << correct / double(n) << "(" << n << ")" << endl;
}

