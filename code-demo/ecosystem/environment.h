/*
 * environment.h
 *
 *  Created on: Sep 27, 2018
 *      Author: KZ
 */

#ifndef CODE_DEMO_ECOSYSTEM_ENVIRONMENT_H_
#define CODE_DEMO_ECOSYSTEM_ENVIRONMENT_H_

#include "plant.h"
#include "rabbit.h"
#include "wolf.h"
#include "population.h"



class Environment {
private:
	Population<Plant, Plant> plants;
	Population<Rabbit, Plant> rabbits;
	Population<Wolf, Rabbit> wolves;
public:
	Environment() :
			plants(30), rabbits(10, &plants), wolves(10, &rabbits) {
		plants.born(5);
		rabbits.born(5);
		wolves.born(2);

	}

	void daily() {
		plants.daily();
		rabbits.daily();
		wolves.daily();
	}
	void print(bool verbose) {
		std::cout << "Plants: ";
		plants.print(verbose);
		std::cout << "Rabbits: ";
		rabbits.print(verbose);
		std::cout << "Wolves: ";
		wolves.print(verbose);
	}

};




#endif /* CODE_DEMO_ECOSYSTEM_ENVIRONMENT_H_ */
