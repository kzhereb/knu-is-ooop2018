/*
 * animal.h
 *
 *  Created on: Sep 27, 2018
 *      Author: KZ
 */

#ifndef CODE_DEMO_ECOSYSTEM_ANIMAL_H_
#define CODE_DEMO_ECOSYSTEM_ANIMAL_H_

#include "organism.h"



class Animal: public Organism {
protected:
	int hungry_days;
	const int maxHunger;
	Animal(int growAge, int breedPeriod, int bornCount, int maxHunger) :
			Organism(growAge, breedPeriod, bornCount), maxHunger(maxHunger) {
		hungry_days = 0;
	}

	virtual void checkBreed(DayResult& result) {
		if (waitBreed == 0 && hungry_days > 0) {
			// too hungry to breed
			return;
		}
		Organism::checkBreed(result);
	}

	std::string getName() {
		return "Animal";
	}
	std::string stringState() {
		return Organism::stringState() + ", hunger="
				+ std::to_string(hungry_days);
	}

public:
	DayResult daily() {
		DayResult result = Organism::daily();

		checkHunger(result);
		return result;
	}

	void hunt(Organism* p) {
		if (p) {
			//std::cout << "Rabbit ";
			this->print();
			std::cout << " ate ";
			p->print();
			hungry_days = 0;
			delete p;
		} else {
			hungry_days++;
		}
	}

private:
	bool checkHunger(DayResult& result) {
		if (age > growAge) {
			if (hungry_days > maxHunger) {
				// die of hunger
				print();
				std::cout << " died of hunger" << std::endl;
				result.die = true;
				return true;
			}
		}
		return false;
	}
};




#endif /* CODE_DEMO_ECOSYSTEM_ANIMAL_H_ */
