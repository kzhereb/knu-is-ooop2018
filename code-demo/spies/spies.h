/*
 * spies.h
 *
 *  Created on: Oct 4, 2018
 *      Author: KZ
 */

#ifndef CODE_DEMO_SPIES_SPIES_H_
#define CODE_DEMO_SPIES_SPIES_H_

#include <string>
#include <chrono>

using std::string;
using std::chrono::high_resolution_clock;

class Spy {
private:
	int id;
	static int MaxID;
protected:
	virtual void printState();
public:
	Spy();
	virtual ~Spy();
	void report(string message);
};

class TimerSpy: public Spy {
private:
	high_resolution_clock::time_point start;
protected:
	void printState() override;
public:
	TimerSpy();
	~TimerSpy();
};


class RandSpy: public Spy {
protected:
	void printState() override;
public:
	RandSpy();
	~RandSpy();
};

#endif /* CODE_DEMO_SPIES_SPIES_H_ */
