/*
 * utils.cpp
 *
 *  Created on: 2016/09/03
 *      Author: ryosuke-k
 */

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include <vector>
#include <algorithm>
#include <map>
#include <regex>

#include "utils.h"

using namespace std;

vector<string> split(string &str, char sep) {
    vector<string> v;
    stringstream ss(str);
    string buffer;
    while (getline(ss, buffer, sep)) {
        v.push_back(buffer);
    }
    return v;
}

void count_map(map<string, int> &mp, const string str) {
    auto itr = mp.find(str);
    if (itr != mp.end()) {
        mp[str]++;
    } else {
        mp[str] = 1;
    }
}

vector<double> vecMaltvec(vector<double> vec1, vector<int> vec2){
    vector<double> res;
    for (size_t i = 0; i != vec2.size(); ++i){
        res.push_back(vec1[i] * vec2[i]);
    }
    return res;
}

double vecSum(vector<double> v){
    double res = 0;
    for (auto x:v){
        res += x;
    }
    return res;
}


vector<double> vecSumvec(vector<double> vec1, vector<double> vec2){
    for (int i = 0; i != vec1.size(); ++i){
        vec1[i] += vec2[i];
    }
    return vec1;
}


vector<double> vecMaltint(vector<int> vec, int x){
    vector<double> res;
    for (size_t i = 0; i != vec.size(); ++i){
        res.push_back(vec[i] * x);
    }
    return res;
}


