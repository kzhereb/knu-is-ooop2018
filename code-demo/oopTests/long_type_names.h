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

//template<typename T> typedef std::pair<T,std::vector<T>> typed_pair_typedef;
//typed_pair_typedef<int> pairIntTypedef;
	// ERROR - template declaration of typedef not allowed

template<typename T> struct type_holder {
	typedef std::pair<T,std::vector<T>> typed_pair_typedef;
};

type_holder<int>::typed_pair_typedef pairIntTypedef;
type_holder<std::string>::typed_pair_typedef pairStringTypedef;

#endif /* CODE_DEMO_OOPTESTS_LONG_TYPE_NAMES_H_ */
