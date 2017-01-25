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

/*
 * An generic class to handle the heuristics to the b-coloring problem
 *
 * */
class Heuristic {
protected:

	long szcl;// the number of colours used in this method

	Timer* tm;//the clock

	Set** colours;// the adjacent matrix representing the given coloration

	long n;

	float elapsedtm;

	Graph* g; //the graph

	/*
	 * Completely or partialy color the graph associated to the current object
	 * */
	virtual void innerSolver() = 0;

	/*
	 * Completely or partialy color the subgraph associated to vertex set represented to active
	 *
	 * @param active a subset of the vertex set of the graph that will be colored
	 * */
	virtual void innerSolver(Set* active) = 0;

	/*
	 * Completely or partialy color the subgraph associated to vertex set represented to active
	 * consider the colors given by colours for the vertices
	 *
	 * @param active a subset of the vertex set of the graph that will be colored
	 * @param colours the adjacent matrix of a partial color for the complete graph, which may
	 * or not contain the vertices in active
	 * */
	virtual void innerSolver(Set* active, Set** colours) = 0;

	/*
	 * An generic greedy coloring algorithm, this algorithm expands any partial color to a complete color
	 * */
	void greedyAlgorithm();

	/*
	 * An generic b coloring algorithm, this algorithm turns any coloring of the graph into a b-coloring
	 * */
	void algoB();

public:
	/*
	 * Build an heuristic to color the graph passed as input
	 *
	 * @param h the graph
	 * */
	Heuristic(Graph* h);

	/*
	 * Destroy this object
	 * */
	virtual ~Heuristic();

	/* INTERFACE
	 * Completely or partialy color the graph associated to the current object
	 * */
	void solve();

	/* INTERFACE
	 * Completely or partialy color the subgraph associated to vertex set represented to active
	 *
	 * @param active a subset of the vertex set of the graph that will be colored
	 * */
	void solve(Set* active);

	/* INTERFACE
	 * Completely or partialy color the subgraph associated to vertex set represented to active
	 * consider the colors given by colours for the vertices
	 *
	 * @param active a subset of the vertex set of the graph that will be colored
	 * @param colours the adjacent matrix of a partial color for the complete graph, which may
	 * or not contain the vertices in active
	 * */
	void solve(Set* active, Set** colours);

	/*
	 * Retrivies the value of the optimal solution founded by the heuristic represented
	 * by this objetc
	 *
	 * @return the value of the solution built by the concrete object
	 * */
	long getSolution();

	/*
	 * Retrivies the elapsed time spend in the calculus
	 *  of the optimal solution founded by the heuristic represented
	 * by this object
	 *
	 * @return the elapsed time in the computation of the solution built by the concrete object
	 * */
	float getElapsedTime();

};

#endif /* SRC_SOLVER_HEURISTIC_H_ */
