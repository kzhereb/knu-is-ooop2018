/*
 * population.h
 *
 *  Created on: Sep 27, 2018
 *      Author: KZ
 */

#ifndef CODE_DEMO_ECOSYSTEM_POPULATION_H_
#define CODE_DEMO_ECOSYSTEM_POPULATION_H_

#include "day_result.h"

#include <vector>

#include <iostream>

using std::vector;

template<typename T> class HuntSource {
public:
	virtual T* huntRandom()=0;
protected:
	virtual ~HuntSource() {
	}
};

template<typename T, typename Prey> class Population: public HuntSource<T> {
private:
	int child_count;
	int adult_count;
	int saturation_count;
	vector<T*> children;
	vector<T*> adults;
	HuntSource<Prey> * preyPopulation;
public:
	Population(int saturation, HuntSource<Prey> * prey = nullptr);
	virtual ~Population();

	void born(int count);

	void daily();
	T* getRandom();

	virtual T* huntRandom();
	void print(bool verbose);
};

#include "population.inc"

#endif /* CODE_DEMO_ECOSYSTEM_POPULATION_H_ */
