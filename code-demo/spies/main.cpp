/*
 * main.cpp
 *
 *  Created on: Oct 4, 2018
 *      Author: KZ
 */
#include "spies.h"
#include <iostream>
#include <vector>
#include <cstdlib>

using std::cout;
using std::endl;

int main() {
	srand(12345);
	HiddenRandSpy::setSeed(12345);

	Spy* spy = new HiddenRandSpy;
	cout << spy << endl;


	std::vector<int> randoms;
	for (int i = 0; i < 10; i++) {
		spy->report("new value");
		int val = rand();
		randoms.push_back(val);
		if (val%100==13) {
			throw std::logic_error("bad luck, escaping...");
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << randoms[i] << " ";
	}
	cout << endl;

	delete spy;

	return 0;
}

