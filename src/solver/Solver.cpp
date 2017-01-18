/*
 * Solver.cpp
 *
 *  Created on: 19 de dez de 2016
 *      Author: marcio
 */

#include "Solver.h"

Solver::Solver(Graph* h){
	g = h;
	tm = new Timer();
	elapsedtm = 0.0;
	solution = 0.0;
}

Solver::~Solver(){
	delete tm;
}

void Solver::build(){
	innerbuild();
}

void Solver::solve(){
	tm->start();
	innerSolver();
	elapsedtm = tm->stop();
}

long Solver::getSolution(){
	return solution;
}

float Solver::getElapsedTime(){
	return elapsedtm;
}
