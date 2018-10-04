#include "organism.h"
#include "population.h"


#include <cstdlib>
#include <ctime>


class Animal: public Organism {
protected:
	int hungry_days;
	const int maxHunger;
	Animal(int growAge, int breedPeriod, int bornCount, int maxHunger) :
			Organism(growAge, breedPeriod, bornCount), maxHunger(maxHunger) {
		hungry_days = 0;
	}

	virtual void checkBreed(DayResult& result) {
		if (waitBreed == 0 && hungry_days > 0) {
			// too hungry to breed
			return;
		}
		Organism::checkBreed(result);
	}

	std::string getName() {
		return "Animal";
	}

	std::string getStateString() {
		return Organism::getStateString() +", hunger=" + std::to_string(hungry_days);
	}

public:
	DayResult daily() {
		DayResult result = Organism::daily();

		checkHunger(result);
		return result;
	}

	void hunt(Organism * p) {
		if (p) {
			this->print();
			std::cout << " ate ";
			p->print();
			hungry_days = 0;
			delete p;
		} else {
			hungry_days++;
		}
	}



private:
	bool checkHunger(DayResult& result) {
		if (age > growAge) {
			if (hungry_days > maxHunger) {
				// die of hunger
				print();
				std::cout << " died of hunger" << std::endl;
				result.die = true;
				return true;
			}
		}
		return false;
	}
};

class Plant: public Organism {

	static int maxID;
protected:
	std::string getName() {
		return "Plant";
	}
public:
	Plant() :
			Organism(5, 4, 7) {
		maxID++;
		id = maxID;

	}


};
int Plant::maxID = 0;

class Rabbit: public Animal {
private:

	static int maxID;
protected:
	std::string getName() {
		return "Rabbit";
	}
public:
	Rabbit() :
			Animal(4, 3, 5, 3) {
		maxID++;
		id = maxID;

	}

};
int Rabbit::maxID = 0;

class Wolf: public Animal {
private:
	static int maxID;
protected:
	std::string getName() {
		return "Wolf";
	}
public:
	Wolf() :
			Animal(7, 5, 2, 5) {
		maxID++;
		id = maxID;

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
