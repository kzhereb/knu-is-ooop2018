/*
 * organism.cpp
 *
 *  Created on: Sep 27, 2018
 *      Author: KZ
 */

#include "organism.h"

	Organism::Organism(int growAge, int breedPeriod, int bornCount) :
			growAge(growAge), breedPeriod(breedPeriod), bornCount(bornCount) {
		age = 0;
		waitBreed = breedPeriod;
	}


	void Organism::checkBreed(DayResult& result) {
		if (age > growAge) {
			waitBreed--;
			if (waitBreed == 0) {
				waitBreed = breedPeriod;
				result.born = bornCount + rand() % bornCount;
			}
		}
	}
