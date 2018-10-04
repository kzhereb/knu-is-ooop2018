/*
 * organism.h
 *
 *  Created on: Sep 27, 2018
 *      Author: KZ
 */

#ifndef CODE_DEMO_ECOSYSTEM_ORGANISM_H_
#define CODE_DEMO_ECOSYSTEM_ORGANISM_H_
#include <string>
#include <iostream>
#include <cassert>


struct DayResult {
	bool grow;
	bool die;
	int born;
	DayResult() {
		grow = false;
		die = false;
		born = 0;
	}
};

class Organism {
protected:
	int id;
	int age;
	int waitBreed;
	const int growAge;
	const int breedPeriod;
	const int bornCount;
	Organism(int growAge, int breedPeriod, int bornCount);

	virtual void checkBreed(DayResult& result) ;


	virtual std::string getName() {
		return "Organism";
	}
	virtual std::string getStateString() {
		return "id=" + std::to_string(id) + ",age=" + std::to_string(age);
	}

public:
	virtual ~Organism() {
	}
	DayResult daily() {
		DayResult result;
		age++;
		if (checkGrow(result)) {
			return result;
		}
		checkBreed(result);
		return result;
	}
	virtual void hunt(Organism* p) {
		assert(false); //plants don't hunt

		//if you want to include message in error output:
		assert(false && "plants don't hunt");
	}
	void print() {
		std::cout << getName() << " " << getStateString() << std::endl;
	}


private:
	bool checkGrow(DayResult& result) {
		if (age == growAge) {
			result.grow = true;
			waitBreed = breedPeriod;
			return true;
		}
		return false;
	}

};





#endif /* CODE_DEMO_ECOSYSTEM_ORGANISM_H_ */
