/*
 * Timer.cpp
 *
 *  Created on: 26/06/2014
 *      Author: santosma
 */

#include "Timer.h"

Timer::Timer(){}

Timer::~Timer(){}

void Timer::start(){
	gettimeofday(&clockinit, &tz);
}

float Timer::pause(){
	gettimeofday(&clockend, &tz);
	seconds += ((float)(clockend.tv_sec - clockinit.tv_sec)) + ((float)(clockend.tv_usec - clockinit.tv_usec))/1000000;
	gettimeofday(&clockinit, &tz);
	return seconds;
}

float Timer::stop(){
	gettimeofday(&clockend, &tz);
	seconds += ((float)(clockend.tv_sec - clockinit.tv_sec)) + ((float)(clockend.tv_usec - clockinit.tv_usec))/1000000;
	return seconds;
}
