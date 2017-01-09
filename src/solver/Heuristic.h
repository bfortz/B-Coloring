/*
 * Heuristic.h
 *
 *  Created on: 8 de jan de 2017
 *      Author: mcsma
 */

#ifndef SRC_SOLVER_HEURISTIC_H_
#define SRC_SOLVER_HEURISTIC_H_

#include "../tools/Set.h"
#include "../tools/Timer.h"
#include "../tools/Graph.h"

//A generic heuritic method to be used
class Heuristic {
private:

	long szcl;// the number of colours used in this method

	Timer* tm;//the clock

	Set** colours;// the adjacent matrix representing the given coloration

protected:
	Graph* g; //the graph

	// the method that solves the problem
	virtual void innerSolver() = 0;

	// the method that solves the problem
	virtual void innerSolver(Set* active) = 0;

	// the method that solves the problem
	virtual void innerSolver(Set* active, Set** colours) = 0;

	// an generic greedy algorithm to finished up coloring
	void greedyAlgorithm();

	// the b coloring algorithm to verify that the b-coloring indeed respect all the constraints
	void algoB();

public:
	//Initializes the interface
	Heuristic(Graph* h);

	//Destroy the interface
	virtual ~Heuristic();

	//Interface to the solver
	void solve();

	//Interface to the solver
	void solve(Set* active);

	//Interface to the solver
	void solve(Set* active, Set** colours);

	//Retrive the optimal solution
	long getSolution();

	//Retrive the elapsed time to solve the problem
	float getElapsedTime();

};

#endif /* SRC_SOLVER_HEURISTIC_H_ */
