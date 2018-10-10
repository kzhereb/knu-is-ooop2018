/*
 * main.cpp
 *
 *  Created on: Oct 4, 2018
 *      Author: KZ
 */
#include "spies.h"
#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
using std::cout;
using std::endl;
using std::vector;
using std::unique_ptr;

void generateRandoms() {
	srand(12345);
	HiddenRandSpy::setSeed(12345);
	unique_ptr<Spy> spy(new HiddenRandSpy);
	cout << spy.get() << endl;
	vector<int> randoms;
	for (int i = 0; i < 10; i++) {
		spy->report("new value");
		int val = rand();
		if (val % 100 == 13) {
			throw std::logic_error("Bad luck");
		}
		randoms.push_back(val);
	}
	for (int i = 0; i < 10; i++) {
		cout << randoms[i] << " ";
	}
	cout << endl;
	//delete spy;
}

int main() {
	try {
		generateRandoms();
	} catch (const std::logic_error& e) {
		cout <<"Something really bad happened: "<< e.what() << endl;
		return 1;
	}
	return 0;
}

