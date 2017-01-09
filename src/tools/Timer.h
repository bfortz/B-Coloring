/*
 * Timer.h
 *
 *  Created on: 26/06/2014
 *      Author: santosma
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <sys/time.h>
#include <unistd.h>

//represents a clock for the problems
class Timer {
private:
	struct timeval  clockinit;
	struct timeval  clockend;
	struct timezone tz;
	float seconds;
public:
	//build a clock
	Timer();

	virtual ~Timer();

	//starts the clock
	void start();

	//pause and return the elapsed time in seconds
	float pause();

	//stop and return the elapsed time in seconds
	float stop();
};

#endif /* TIMER_H_ */
