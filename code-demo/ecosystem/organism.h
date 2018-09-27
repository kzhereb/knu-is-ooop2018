/*
 * organism.h
 *
 *  Created on: Sep 27, 2018
 *      Author: KZ
 */

#ifndef CODE_DEMO_ECOSYSTEM_ORGANISM_H_
#define CODE_DEMO_ECOSYSTEM_ORGANISM_H_

#include "day_result.h"
#include <iostream>
#include <string>
#include <cassert>



class Organism {
protected:
	int id;
	int age;
	int waitBreed;
	const int growAge;
	const int breedPeriod;
	const int bornCount;
	Organism(int growAge, int breedPeriod, int bornCount) :
			growAge(growAge), breedPeriod(breedPeriod), bornCount(bornCount) {
		age = 0;
		waitBreed = breedPeriod;
	}

	virtual void checkBreed(DayResult& result) {
		if (age > growAge) {
			waitBreed--;
			if (waitBreed == 0) {
				waitBreed = breedPeriod;
				result.born = bornCount + rand() % bornCount;
			}
		}
	}

	virtual std::string getName() {
		return "Organism";
	}
	virtual std::string stringState() {
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
		std::cout << getName() << " " << stringState() << std::endl;
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
