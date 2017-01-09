/*
 * Heuristic.h
 *
 *  Created on: 8 de jan de 2017
 *      Author: mcsma
 */

#ifndef SRC_SOLVER_HEURISTIC_H_
#define SRC_SOLVER_HEURISTIC_H_


//A generic heuritic method to be used
class Heuristic {
private:

	long solution;// the solution

	Timer* tm;//the clock

protected:
	Graph* g; //the graph

	virtual void innerSolver() = 0; // the method that solves the problem

public:
	//Initializes the interface
	Heuristic(Graph* h);

	//Destroy the interface
	virtual ~Heuristic();

	//Interface Solver
	void solve(Set* active);

	//Retrive the optimal solution
	long getSolution();

	//Retrive the elapsed time to solve the problem
	float getElapsedTime();

};

#endif /* SRC_SOLVER_HEURISTIC_H_ */
