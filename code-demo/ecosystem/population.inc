/*
 * population.cpp
 *
 *  Created on: Sep 27, 2018
 *      Author: KZ
 */
#include "population.h"

#include <algorithm>

template<typename T, typename Prey> Population<T, Prey>::Population(
		int saturation, HuntSource<Prey> * prey) {
	saturation_count = saturation;
	child_count = 0;
	adult_count = 0;
	preyPopulation = prey;
}

template<typename T, typename Prey> Population<T, Prey>::~Population() {
	for (T* child : children) {
		delete child;
	}
	for (T* adult : adults) {
		delete adult;
	}
}

template<typename T, typename Prey> void Population<T, Prey>::born(int count) {
	std::cout << "Born " << count << std::endl;
	for (int i = 0; i < count; i++) {
		T* newborn = new T();
		newborn->print();
		children.push_back(newborn);
	}
	child_count += count;

}
template<typename T, typename Prey> void Population<T, Prey>::daily() {
	children.erase(
			std::remove_if(children.begin(), children.end(),
					[this](T* child)->bool {
						DayResult dr = child->daily();
						if (dr.grow) {
							adults.push_back(child);
							child_count--;
							adult_count++;
							return true;
						}
						return false;
					}), children.end());

	adults.erase(
			std::remove_if(adults.begin(), adults.end(),
					[this](T* adult)->bool {
						if (preyPopulation) {
							Prey* prey = preyPopulation->huntRandom();
							adult->hunt(prey);
						}
						DayResult dr = adult->daily();
						if (dr.die) {
							delete adult;
							adult_count--;
							return true;
						}
						if (dr.born>0) {
							born(dr.born);
						}
						return false;
					}), adults.end());

}

template<typename T, typename Prey> T* Population<T, Prey>::getRandom() {
	if (adult_count <= 0) {
		return nullptr;
	}
	int rand_idx = rand() % adult_count;
	T* result = adults[rand_idx];
	adults.erase(adults.begin() + rand_idx);
	adult_count--;
	return result;
}

template<typename T, typename Prey> T* Population<T, Prey>::huntRandom() {
	if (adult_count < saturation_count) {
		if (rand() % saturation_count > adult_count) {
			return nullptr;
		}
	}
	return getRandom();
}

template<typename T, typename Prey> void Population<T, Prey>::print(
		bool verbose) {
	std::cout << "Population children=" << child_count << ",adults="
			<< adult_count << std::endl;
	if (verbose) {
		std::cout << "Children" << std::endl;
		for (T* child : children) {
			child->print();
		}
		std::cout << "Adults" << std::endl;
		for (T* adult : adults) {
			adult->print();
		}
	}
}
