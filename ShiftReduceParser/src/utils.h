/*
 * utils.h
 *
 *  Created on: 2016/09/03
 *      Author: ryosuke-k
 */

#ifndef UTILS_H_
#define UTILS_H_


#include <iostream>
#include <vector>
#include <string>
#include <map>

std::vector<std::string> split(std::string &str, char sep);
void count_map(std::map<std::string, int>, std::string str);

std::vector<double> vecMaltvec(std::vector<double> vec1, std::vector<int> vec2);

std::vector<double> vecMaltint(std::vector<int> vec, int x);

std::vector<double> vecSumvec(std::vector<double> vec1, std::vector<double> vec2);

double vecSum(std::vector<double>);

#endif /* UTILS_H_ */
