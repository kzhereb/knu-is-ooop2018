/*
 * classes.h
 *
 *  Created on: Nov 8, 2018
 *      Author: KZ
 */

#ifndef CODE_DEMO_OOPTESTS_CLASSES_H_
#define CODE_DEMO_OOPTESTS_CLASSES_H_

class AccessModifiersSUT {
private:
	int private_field;
protected:
	int protected_field;
public:
	int public_field;
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

#endif /* CODE_DEMO_OOPTESTS_CLASSES_H_ */
