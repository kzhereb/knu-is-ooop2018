/*
 * day_result.h
 *
 *  Created on: Sep 27, 2018
 *      Author: KZ
 */

#ifndef CODE_DEMO_ECOSYSTEM_DAY_RESULT_H_
#define CODE_DEMO_ECOSYSTEM_DAY_RESULT_H_


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


#endif /* CODE_DEMO_ECOSYSTEM_DAY_RESULT_H_ */
