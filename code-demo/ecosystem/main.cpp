#include "plant.h"
#include "rabbit.h"
#include "wolf.h"


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cassert>

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
	Population(int saturation, HuntSource<Prey> * prey = nullptr) {
		saturation_count = saturation;
		child_count = 0;
		adult_count = 0;
		preyPopulation = prey;
	}
	virtual ~Population() {
		for (T* child : children) {
			delete child;
		}
		for (T* adult : adults) {
			delete adult;
		}
	}

	void born(int count) {
		std::cout << "Born " << count << std::endl;
		for (int i = 0; i < count; i++) {
			T* newborn = new T();
			newborn->print();
			children.push_back(newborn);
		}
		child_count += count;

	}
	void daily() {
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

	T* getRandom() {
		if (adult_count <= 0) {
			return nullptr;
		}
		int rand_idx = rand() % adult_count;
		T* result = adults[rand_idx];
		adults.erase(adults.begin() + rand_idx);
		adult_count--;
		return result;
	}

	virtual T* huntRandom() {
		if (adult_count < saturation_count) {
			if (rand() % saturation_count > adult_count) {
				return nullptr;
			}
		}
		return getRandom();
	}

	void print(bool verbose) {
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
};



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

int main() {
	srand(time(NULL));
	Environment env;
	for (int i = 0; i < 20; i++) {
		env.daily();
		std::cout << "===============Day " << i << std::endl;
		env.print(false);
	}

}
