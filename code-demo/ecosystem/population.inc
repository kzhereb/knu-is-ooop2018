/*
 * population.cpp
 *
 *  Created on: Sep 27, 2018
 *      Author: KZ
 */
#include "population.h"


	template<typename T, typename Prey> Population<T,Prey>::Population(int saturation, HuntSource<Prey> * prey) {
		saturation_count = saturation;
		child_count = 0;
		adult_count = 0;
		preyPopulation = prey;
	}

