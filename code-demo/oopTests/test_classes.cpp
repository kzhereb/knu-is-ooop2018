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

	SECTION("can access private fields from another instance of same class") {
		AccessModifiersSUT another {5,7,9};
		REQUIRE(target.sum_of_all_fields(another)== 21);
	}

	SECTION("child class has access to protected") {
		Child child(5,7);
		// child.protected_field = 77;
			// ERROR - can only access protected fields from within class
		REQUIRE(child.public_field == 5);
		REQUIRE(child.sum_of_fields() == 12);
	}

	SECTION("friend class has access to all members") {
		AccessModifiersSUT target {5,7,9};
		FriendlyClass friendCl;
		REQUIRE(friendCl.sum_of_all_fields(target) == 21);

		SECTION("friend function also can access everything") {
			REQUIRE(sum_of_all_fields(target) == 21);
		}
	}

	SECTION("use getter to access private fields") {
		REQUIRE(target.get_private_field()==0);

		SECTION("init values first") {
			AccessModifiersSUT target2 {5,7,9};
			REQUIRE(target2.get_private_field()==9);
		}

		SECTION("use setter to change private field") {
			target.set_private_field(123);
			REQUIRE(target.get_private_field()==123);
		}
 	}

	SECTION("setter on another instance of same class") {
		AccessModifiersSUT target2 {5,7,9};
		REQUIRE(target2.get_private_field()==9);
		target.set_another_private_field(target2, 123);
		REQUIRE(target2.get_private_field()==123);
	}
}

TEST_CASE("static members", "[classes]") {
	Static target {9,5};
	REQUIRE(Static::static_sum(target) == 14);
	REQUIRE(target.static_sum(target) == 14);
}

TEST_CASE("const", "[classes]") {

	REQUIRE(MyConst==12345);
	// MyConst = 5;
		// ERROR - cannot assign const
	REQUIRE(*MyIntPointer==12345);
	// *MyIntPointer = 5;
		// ERROR - cannot change value of const pointer
	const int newConst = 5;
	MyIntPointer = &newConst;
		// OK - can change the pointer to a different const
	REQUIRE(*MyIntPointer==5);

	REQUIRE(*MyIntPointerConst==123);
	*MyIntPointerConst = 5;
	REQUIRE(*MyIntPointerConst==5);


	// MyIntPointerConst = &newConst2;
		// ERROR - cannot change the pointer to a different const
	//REQUIRE(*MyIntPointerConst==10);

	REQUIRE(*MyIntPointerConstConst==12345);
	//*MyIntPointerConstConst = 5;
	// MyIntPointerConstConst = &newConst;




}


