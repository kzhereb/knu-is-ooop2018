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

int Spy::maxID = 0;

Spy::Spy() :
		id(++maxID) {
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

void Spy::report(string message){
	cout<<"Reporting "<<message<<" ";
	printState();
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


RandSpy::RandSpy() :
		Spy() {
	cout << "Rand ";
	printState();
}

RandSpy::~RandSpy() {
	cout << "Rand ";
	printState();
}

void RandSpy::printState() {
	cout << "rand()= " << rand() << " ";
	Spy::printState();
}


int HiddenRandSpy::seed = 1;
HiddenRandSpy::HiddenRandSpy() :
		RandSpy(),callCount(0) {
	cout << "HiddenRand ";
	printState();
}

HiddenRandSpy::~HiddenRandSpy() {
	cout << "HiddenRand ";
	printState();
}

void HiddenRandSpy::printState() {
	cout << "seed=" << seed << ", callCount=" << callCount << " ";
	RandSpy::printState();
	revertState();
}
void HiddenRandSpy::report(string message) {
	callCount++;
	Spy::report(message);
}

void HiddenRandSpy::setSeed(int _seed) {
	seed = _seed;
	cout<<"seed set "<<seed<<endl;
}
void HiddenRandSpy::revertState() {
	srand(seed);
	int notUsed=0;
	for (int i=0;i<callCount-1;i++) {
		notUsed += rand();
	}
	cout<<"notUsed="<<notUsed<<endl;
}
