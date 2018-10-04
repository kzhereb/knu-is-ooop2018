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

	Spy* spy = new RandSpy;
	cout << spy << endl;


	std::vector<int> randoms;
	for (int i = 0; i < 1e7; i++) {
		randoms.push_back(rand());
	}
	for (int i = 0; i < 100; i++) {
		cout << randoms[i] << " ";
	}
	cout << endl;

	delete spy;

	return 0;
}

