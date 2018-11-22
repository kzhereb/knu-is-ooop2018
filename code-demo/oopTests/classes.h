/*
 * classes.h
 *
 *  Created on: Nov 8, 2018
 *      Author: KZ
 */

#ifndef CODE_DEMO_OOPTESTS_CLASSES_H_
#define CODE_DEMO_OOPTESTS_CLASSES_H_

class AccessModifiersSUT {
	friend class FriendlyClass;
	friend int sum_of_all_fields(const AccessModifiersSUT & sut);

public:
	AccessModifiersSUT(int pub, int prot, int priv) :
		public_field(pub), protected_field(prot), private_field(priv){

	}
	AccessModifiersSUT():AccessModifiersSUT(0,0,0) {}
	int public_field;

	int sum_of_all_fields(const AccessModifiersSUT & sut) {
		return sut.private_field + sut.protected_field + sut.public_field;
	}

	int get_private_field() const {
		return private_field;
	}

	void set_private_field(int private_field_) {
		private_field = private_field_;
	}
protected:
	int protected_field;
private:
	int private_field;
};

class Child: public AccessModifiersSUT {
public:
	Child(int pub, int prot)
		//: public_field(pub), protected_field(prot)
			// ERROR - must initialize members of base class in base class constructor
	{
		public_field = pub;
			// OK - can assign members of base class from subclass
		protected_field = prot;
			// OK - can access protected members of base class from subclass
		// private_field = 0;
			// ERROR - subclass cannot access private members of base class
	}
	int sum_of_fields() {
		return public_field + protected_field;
	}

};

class FriendlyClass {
public:
	int sum_of_all_fields(const AccessModifiersSUT & sut) {
		return sut.private_field + sut.protected_field + sut.public_field;
	}

};

int sum_of_all_fields(const AccessModifiersSUT & sut ) {
		return sut.private_field + sut.protected_field + sut.public_field;
	}


class Static {
private:
	int private_field;
	static int static_private_field;
public:
	int public_field;
	Static(int priv, int pub) :
		private_field(priv), public_field(pub){
	}
	static int static_sum(const Static & sut) {
		return sut.private_field + sut.public_field;
			// OK - static methods can access private fields from same class argument
	}
};

const int MyConst = 12345;

int MyInt = 123;

const int * MyIntPointer = &MyConst;

int * const MyIntPointerConst = &MyInt;

//const int * const MyIntPointerConst = &MyConst;

#endif /* CODE_DEMO_OOPTESTS_CLASSES_H_ */
