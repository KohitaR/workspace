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

#endif /* UTILS_H_ */
