
#include "../tools/Graph.h"
#include "../tools/Timer.h"


#ifndef SRC_SOLVER_SOLVER_H_
#define SRC_SOLVER_SOLVER_H_

//This is an interface commun to all the method to solve the problem of b-coloring
class Solver {
protected:

	// the solution
	long solution;

	//the clock
	Timer* tm;

	// the elapsed time in the solution
	float elapsedtm;

	//the graph
	Graph* g;

	/*
	 * Builds the problem concretly
	 * */
	virtual void innerbuild() = 0;

	/*
	 * Concretely solves the problem
	 *
	 * */
	virtual void innerSolver() = 0;

public:
	/**
	 * Initialize the object to solve the b-coloring problem in a given graph
	 *
	 * @param h: the given graph
	 * */
	Solver(Graph* h);

	/**
	 * An Destructor for this class
	 * */
	virtual ~Solver();

	/*
	 * Interface for the biuld method. Initializes the inner variables of this class.
	 * */
	void build();

	/*
	 * Interface for the solve method. Solves the problem and update the variable solution and
	 * the elapsed time.
	 * */
	void solve();

	/*
	 * Retrivies the optimal solution computed by the last call of the method solve().
	 *
	 * @return the the optimal solution computed by the last call of the method solve().
	 * */
	long getSolution();

	/*
	 * Retrivies the elapsed time by the last call of the method solve() in seconds.
	 *
	 * @return the elapsed time by the last call of the method solve() in seconds.
	 * */
	float getElapsedTime();
};

#endif /* SRC_SOLVER_SOLVER_H_ */
