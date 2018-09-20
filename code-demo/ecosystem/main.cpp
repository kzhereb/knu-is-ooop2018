#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cassert>



using std::vector;

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

template<typename T> class HuntSource {
public:
	virtual T* huntRandom()=0;
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


class Organism {
protected:
	int id;
	int age;
	int waitBreed;
	const int growAge = 5;
	const int breedPeriod = 4;
	const int bornCount = 7;
};


class Plant: public Organism {

	static int maxID;
public:
	Plant() {
		age = 0;
		waitBreed = breedPeriod;
		maxID++;
		id = maxID;

	}
	void hunt(Plant* p) {
		assert(false); //plants don't hunt

		//if you want to include message in error output:
		assert(false && "plants don't hunt");
	}

	DayResult daily() {
		DayResult result;
		age++;
		if (age == growAge) {
			result.grow = true;
			waitBreed = breedPeriod;
			return result;
		}
		if (age > growAge) {
			waitBreed--;
			if (waitBreed == 0) {
				waitBreed = breedPeriod;
				result.born = bornCount + rand() % bornCount;
			}
		}
		return result;
	}

	void print() {
		std::cout << "Plant id=" << id << ",age=" << age << std::endl;
	}
};
int Plant::maxID = 0;

class Rabbit {
private:
	int id;
	int age;
	int hungry_days;
	int waitBreed;
	const int growAge = 4;
	const int breedPeriod = 3;
	const int bornCount = 5;
	const int maxHunger = 3;
	static int maxID;

public:
	Rabbit() {
		age = 0;
		hungry_days = 0;
		waitBreed = breedPeriod;
		maxID++;
		id = maxID;

	}
	void hunt(Plant* p) {
		if (p) {
			std::cout << "Rabbit ";
			this->print();
			std::cout << " ate plant ";
			p->print();
			hungry_days = 0;
			delete p;
		} else {
			hungry_days++;
		}
	}

	DayResult daily() {
		DayResult result;
		age++;
		if (age == growAge) {
			result.grow = true;
			waitBreed = breedPeriod;
			return result;
		}
		if (age > growAge) {
			if (hungry_days > maxHunger) {
				// die of hunger
				print();
				std::cout << " died of hunger" << std::endl;
				result.die = true;
				return result;
			}
			if (waitBreed == 0) {
				if (hungry_days == 0) {
					waitBreed = breedPeriod;
					result.born = bornCount + rand() % bornCount;
				}
			} else {
				waitBreed--;
			}
			return result;
		}
		return result;
	}

	void print() {
		std::cout << "Rabbit id=" << id << ",age=" << age << ", hunger="
				<< hungry_days << std::endl;
	}
};
int Rabbit::maxID = 0;

class Wolf {
private:
	int id;
	int age;
	int hungry_days;
	int waitBreed;
	const int growAge = 7;
	const int breedPeriod = 5;
	const int bornCount = 2;
	const int maxHunger = 5;
	static int maxID;


public:
	Wolf() {
		age = 0;
		hungry_days = 0;
		waitBreed = breedPeriod;
		maxID++;
		id = maxID;

	}
	void hunt(Rabbit* p) {

		if (p) {
			std::cout << "Wolf ";
			this->print();
			std::cout << " ate rabbit ";
			p->print();
			hungry_days = 0;
			delete p;
		} else {
			hungry_days++;
		}
	}

	DayResult daily() {
		DayResult result;
		age++;
		if (age == growAge) {
			result.grow = true;
			waitBreed = breedPeriod;
			return result;
		}
		if (age > growAge) {
			if (hungry_days > maxHunger) {
				// die of hunger
				print();
				std::cout << " died of hunger" << std::endl;
				result.die = true;
				return result;
			}
			if (waitBreed == 0) {
				if (hungry_days == 0) {
					waitBreed = breedPeriod;
					result.born = bornCount + rand() % bornCount;
				}
			} else {
				waitBreed--;
			}
			return result;
		}
		return result;
	}

	void print() {
		std::cout << "Wolf id=" << id << ",age=" << age << ", hunger="
				<< hungry_days << std::endl;
	}
};
int Wolf::maxID = 0;

class Environment {
private:
	Population<Plant, Plant> plants;
	Population<Rabbit, Plant> rabbits;
	Population<Wolf, Rabbit> wolves;
public:
	Environment() :
			plants(30), rabbits(10, &plants), wolves(10,&rabbits) {
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
