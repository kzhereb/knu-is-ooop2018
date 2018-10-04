/*
 * spies.h
 *
 *  Created on: Oct 4, 2018
 *      Author: KZ
 */

#ifndef CODE_DEMO_SPIES_SPIES_H_
#define CODE_DEMO_SPIES_SPIES_H_
#include <chrono>
#include <string>

using std::string;
using std::chrono::high_resolution_clock;



class Spy {
private:
	int id;
	static int maxID;
protected:
	virtual void printState();
public:
	Spy();
	virtual ~Spy();
	virtual void report(string message);
};


class TimerSpy: public Spy {
private:
	high_resolution_clock::time_point start;
protected:
	void printState();
public:
	TimerSpy();
	virtual ~TimerSpy();
};


class RandSpy: public Spy {
protected:
	void printState() override;
public:
	RandSpy();
	~RandSpy();
};

class HiddenRandSpy: public RandSpy {
private:
	int callCount;
	static int seed;
	void revertState();

protected:
	void printState() override;
public:
	HiddenRandSpy();
	~HiddenRandSpy();
	void report(string message) override;
	static void setSeed(int seed);
};


#endif /* CODE_DEMO_SPIES_SPIES_H_ */
