/*
 * wolf.h
 *
 *  Created on: Sep 27, 2018
 *      Author: KZ
 */

#ifndef CODE_DEMO_ECOSYSTEM_WOLF_H_
#define CODE_DEMO_ECOSYSTEM_WOLF_H_

#include "animal.h"

class Wolf: public Animal {
private:
	static int maxID;
protected:
	std::string getName() {
		return "Wolf";
	}
public:
	Wolf() :
			Animal(7, 5, 2, 5) {
		maxID++;
		id = maxID;

	}

};
int Wolf::maxID = 0;




#endif /* CODE_DEMO_ECOSYSTEM_WOLF_H_ */
