/*
 * plant.h
 *
 *  Created on: Sep 27, 2018
 *      Author: KZ
 */

#ifndef CODE_DEMO_ECOSYSTEM_PLANT_H_
#define CODE_DEMO_ECOSYSTEM_PLANT_H_

#include "organism.h"

class Plant: public Organism {

	static int maxID;

protected:
	std::string getName() {
		return "Plant";
	}
public:
	Plant() :
			Organism(5, 4, 7) {
		maxID++;
		id = maxID;

	}

};
int Plant::maxID = 0;




#endif /* CODE_DEMO_ECOSYSTEM_PLANT_H_ */
