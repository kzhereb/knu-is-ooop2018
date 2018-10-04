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

std::string Organism::getName() {
	return "Organism";
}

std::string Organism::stringState() {
	return "id=" + std::to_string(id) + ",age=" + std::to_string(age);
}

Organism::~Organism() {
}

DayResult Organism::daily() {
	DayResult result;
	age++;
	if (checkGrow(result)) {
		return result;
	}
	checkBreed(result);
	return result;
}

void Organism::hunt(Organism* p) {
	assert(false); //plants don't hunt

	//if you want to include message in error output:
	assert(false && "plants don't hunt");
}

void Organism::print() {
	std::cout << getName() << " " << stringState() << std::endl;
}

bool Organism::checkGrow(DayResult& result) {
	if (age == growAge) {
		result.grow = true;
		waitBreed = breedPeriod;
		return true;
	}
	return false;
}

