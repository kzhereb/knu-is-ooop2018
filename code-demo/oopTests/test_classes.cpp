/*
 * test_classes.cpp
 *
 *  Created on: Nov 8, 2018
 *      Author: KZ
 */

#include "classes.h"
#include "catch.hpp"

TEST_CASE("access modifiers for classes", "[classes]") {
	AccessModifiersSUT target;
	target.public_field = 5;
	REQUIRE(target.public_field == 5);
	// target.protected_field = 7;
		// ERROR - 'int AccessModifiersSUT::protected_field' is protected within this context
	// target.private_field = 9;
		// ERROR - access to private field outside class

	SECTION("child class has access to protected") {
		Child child(5,7);
		// child.protected_field = 77;
			// ERROR - can only access protected fields from within class
		REQUIRE(child.public_field == 5);
		REQUIRE(child.sum_of_fields() == 12);
	}
}

