/*
 * rabbit.h
 *
 *  Created on: Sep 27, 2018
 *      Author: KZ
 */

#ifndef CODE_DEMO_ECOSYSTEM_RABBIT_H_
#define CODE_DEMO_ECOSYSTEM_RABBIT_H_

#include "animal.h"

class Rabbit: public Animal {
private:

	static int maxID;
protected:
	std::string getName() {
		return "Rabbit";
	}
public:
	Rabbit() :
			Animal(4, 3, 5, 3) {
		maxID++;
		id = maxID;

	}

};
int Rabbit::maxID = 0;




#endif /* CODE_DEMO_ECOSYSTEM_RABBIT_H_ */
