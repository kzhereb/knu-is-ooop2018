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

	SECTION("with typedef") {
		pairTypedef.first = "test2";
		pairTypedef.second = {"one","two", "many"};

		REQUIRE(pairTypedef.first == "test2");
		REQUIRE(pairTypedef.second[0] == "one");
		REQUIRE(pairTypedef.second[1] == "two");
		REQUIRE(pairTypedef.second[2] == "many");


	}

	SECTION("with using") {
			pairUsing.first = "test2";
			pairUsing.second = {"one","two", "many"};

			REQUIRE(pairUsing.first == "test2");
			REQUIRE(pairUsing.second[0] == "one");
			REQUIRE(pairUsing.second[1] == "two");
			REQUIRE(pairUsing.second[2] == "many");


		}
 }
