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

	Organism(int growAge, int breedPeriod, int bornCount);

	virtual void checkBreed(DayResult& result);
	virtual std::string getName();
	virtual std::string stringState();

public:
	virtual ~Organism();
	DayResult daily();
	virtual void hunt(Organism* p);
	void print();

private:
	bool checkGrow(DayResult& result);

};

#endif /* CODE_DEMO_ECOSYSTEM_ORGANISM_H_ */
