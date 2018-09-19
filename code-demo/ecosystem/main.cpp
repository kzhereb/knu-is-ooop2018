#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using std::vector;
using std::cout;
using std::endl;

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

class Plant {
private:
	int age;
	int waitBreed;
	const int growAge = 5;
	const int breedPeriod = 4;
	const int bornCount = 5;
public:
	bool canGrow() {
		return (age == growAge);
	}
	DayResult daily() {
		DayResult result;
		age++;
		if (canGrow()) {
			result.grow = true;
			waitBreed = breedPeriod;
			return result;
		}
		if (age < growAge) {
			return result;
		}

		if (waitBreed == 0) {
			result.born = bornCount + rand() % bornCount;
			waitBreed = breedPeriod;
		} else {
			waitBreed--;
		}

		return result;
	}

	void print() {
		cout << "Plant age=" << age << ", wait=" << waitBreed << endl;
	}
};

class Population {
private:
	vector<Plant*> children;
	vector<Plant*> adults;
	int childCount;
	int adultCount;
public:
	Population(int starting):  adultCount(0) {
		for (int i=0;i<starting;i++) {
			children.push_back(new Plant());
		}
		childCount=starting;
	}
	void daily() {
		children.erase(
				std::remove_if(children.begin(), children.end(),
						[this](Plant* child)->bool {
							DayResult dr = child->daily();
							if (dr.grow) {
								childCount--;
								adultCount++;
								adults.push_back(child);
								return true;
							} else {
								return false;
							}
						}), children.end());
	}

	void print(bool verbose) {
		cout<<"childcount="<<childCount<<", adultcount ="<<adultCount<<endl;
		if (verbose) {
			cout<<"Children\n";
			for(Plant* plant:children) {
				plant->print();
			}
			cout<<"Adults\n";
			for(Plant* plant:adults) {
				plant->print();
			}
		}
	}
};

int main() {
	srand(time(NULL));
//	Plant * plant = new Plant();
//	for (int i = 0; i < 10; i++) {
//		plant->daily();
//		plant->print();
//	}

	Population pop(5);
	for (int i = 0; i < 10; i++) {
			pop.daily();
			pop.print(true);
		}

}
