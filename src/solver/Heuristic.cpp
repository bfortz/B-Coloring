/*
 * Heuristic.cpp
 *
 *  Created on: 8 de jan de 2017
 *      Author: mcsma
 */

#include "Heuristic.h"

// an generic greedy algorithm to finished up coloring
void greedyAlgorithm(){
	// TODO
}

// the b coloring algorithm to verify that the b-coloring indeed respect all the constraints
void algoB(){
	// TODO
}

//Initializes the interface
Heuristic::Heuristic(Graph* h) {
	// TODO
}

//Destroy the interface
Heuristic::~Heuristic() {
	// TODO
}

//Interface to the solver
void Heuristic::solve() {
	// TODO
}

//Interface to the solver
void Heuristic::solve(Set* active) {
	// TODO
}

//Interface to the solver
void Heuristic::solve(Set* active, Set** colours2) {
	// TODO
}

//Retrive the optimal solution
long Heuristic::getSolution() {
	// TODO
	return 0;
}

//Retrive the elapsed time to solve the problem
float Heuristic::getElapsedTime() {
	// TODO
	return 0;
}
