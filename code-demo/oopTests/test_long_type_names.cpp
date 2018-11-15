/*
 * test_long_type_names.cpp
 *
 *  Created on: Nov 14, 2018
 *      Author: KZ
 */

#include "long_type_names.h"
#include "catch.hpp"

template <typename T> void checkPairString(T& pair) {
	pair.first = "test";
	pair.second = {"one","two", "many"};

	REQUIRE(pair.first == "test");
	REQUIRE(pair.second[0] == "one");
	REQUIRE(pair.second[1] == "two");
	REQUIRE(pair.second[2] == "many");
}

template <typename T> void checkPairInt(T& pair) {
	pair.first = 5;
	pair.second = {7, 11, 13};

	REQUIRE(pair.first == 5);
	REQUIRE(pair.second[0] == 7);
	REQUIRE(pair.second[1] == 11);
	REQUIRE(pair.second[2] == 13);
}

TEST_CASE("using pair", "[long]") {

	SECTION("long type") {
		checkPairString(myPair);
	}

	SECTION("with typedef") {
		checkPairString(pairTypedef);
	}

	SECTION("with using") {
		checkPairString(pairUsing);
	}

	SECTION("template+typedef int, string") {
		checkPairInt(pairIntTypedef);
		checkPairString(pairStringTypedef);
	}
 }


