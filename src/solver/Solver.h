/*
 * Solver.h
 *
 *  Created on: 19 de dez de 2016
 *      Author: marcio
 */

#include "../tools/Graph.h"
#include "../tools/Timer.h"


#ifndef SRC_SOLVER_SOLVER_H_
#define SRC_SOLVER_SOLVER_H_

//This is an interface commun to all the method to solve the problem of b-coloring
class Solver {
private:

	long solution;// the solution

	Timer* tm;//the clock

protected:
	Graph* g; //the graph

	virtual void innerbuild() = 0; //the real builder

	virtual void innerSolver() = 0; // the method that solves the problem

public:
	//Initializes the interface
	Solver(Graph* h);

	//Destroy the interface
	virtual ~Solver();

	//Interface build
	void build();

	//Interface Solver
	void solve();

	//Retrive the optimal solution
	long getSolution();

	//Retrive the elapsed time to solve the problem
	float getElapsedTime();
};

#endif /* SRC_SOLVER_SOLVER_H_ */
