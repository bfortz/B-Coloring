/*
 * BasicHeuristic.h
 *
 *  Created on: 26 de jan de 2017
 *      Author: marcio
 */

#ifndef SRC_SOLVER_BASICHEURISTIC_H_
#define SRC_SOLVER_BASICHEURISTIC_H_

#include "Heuristic.h"
#include <algorithm>    // std::swap

class BasicHeuristic: public Heuristic {
protected:

	Set* uncolored;

	void orderVertices(long* ov, long* dg);

	long selectLlist(long* llist);

	long choseBV(long* ov, long* dg);

	/*
	 * Completely or partialy color the graph associated to the current object
	 * */
	void innerSolver();

public:
	BasicHeuristic(Graph* h);

	virtual ~BasicHeuristic();
};

#endif /* SRC_SOLVER_BASICHEURISTIC_H_ */
