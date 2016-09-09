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
