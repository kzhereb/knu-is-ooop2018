/*
 * test_long_type_names.cpp
 *
 *  Created on: Nov 14, 2018
 *      Author: KZ
 */

#include "long_type_names.h"
#include "catch.hpp"

TEST_CASE("using pair", "[long]") {
	myPair.first = "test";
	myPair.second = {"one","two", "many"};

	REQUIRE(myPair.first == "test");
	REQUIRE(myPair.second[0] == "one");
	REQUIRE(myPair.second[1] == "two");
	REQUIRE(myPair.second[2] == "many");

	SECTION("using typedef") {
		secondPair.first = "test2";
		secondPair.second = {"one","two", "many"};

		REQUIRE(secondPair.first == "test2");
		REQUIRE(secondPair.second[0] == "one");
		REQUIRE(secondPair.second[1] == "two");
		REQUIRE(secondPair.second[2] == "many");


	}
 }
