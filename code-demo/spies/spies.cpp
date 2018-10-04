/*
 * spies.cpp
 *
 *  Created on: Oct 4, 2018
 *      Author: KZ
 */

#include "spies.h"
#include <iostream>
using std::cout;
using std::endl;

int Spy::MaxID = 0;
Spy::Spy() :
		id(++MaxID) {
	cout << "Init ";
	printState();
}
Spy::~Spy() {
	cout << "Destroyed ";
	printState();
}
void Spy::printState() {
	cout << "spy id=" << id << endl;
}

TimerSpy::TimerSpy() :
		Spy(), start(high_resolution_clock::now()) {
	cout << "Timer ";
	printState();
}
TimerSpy::~TimerSpy() {
	cout << "Timer ";
	printState();
}

void TimerSpy::printState() {
	using std::chrono::duration_cast;
	using std::chrono::milliseconds;
	auto now = high_resolution_clock::now();
	cout << "Elapsed " << duration_cast<milliseconds>(now - start).count()
			<< " ms ";
	Spy::printState();
}
