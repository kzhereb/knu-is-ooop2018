/*
 * long_type_names.h
 *
 *  Created on: Nov 14, 2018
 *      Author: KZ
 */

#ifndef CODE_DEMO_OOPTESTS_LONG_TYPE_NAMES_H_
#define CODE_DEMO_OOPTESTS_LONG_TYPE_NAMES_H_

#include <vector>
#include <utility>
#include <string>

std::pair<std::string,std::vector<std::string>> myPair;

typedef std::pair<std::string,std::vector<std::string>> string_pair;

string_pair secondPair;


#endif /* CODE_DEMO_OOPTESTS_LONG_TYPE_NAMES_H_ */
