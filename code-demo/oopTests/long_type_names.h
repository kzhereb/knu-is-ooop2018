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

typedef std::pair<std::string,std::vector<std::string>> string_pair_typedef;

using string_pair_using = std::pair<std::string,std::vector<std::string>>;

string_pair_typedef pairTypedef;
string_pair_using pairUsing;


#endif /* CODE_DEMO_OOPTESTS_LONG_TYPE_NAMES_H_ */
