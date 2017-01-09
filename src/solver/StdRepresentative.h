/*
 * StdRepresentative.h
 *
 *  Created on: 19 de dez de 2016
 *      Author: marcio
 */

#ifndef SRC_SOLVER_STDREPRESENTATIVE_H_
#define SRC_SOLVER_STDREPRESENTATIVE_H_

#include "../tools/Graph.h"
#include "Solver.h"
#include <ilcplex/ilocplex.h>

class StdRepresentative:public Solver {
private:
	IloEnv* env;//enviroment
	IloModel* model;//problem

protected:
	void innerbuild();//the real builder

	void innerSolver();// the method that solves the problem

public:
	StdRepresentative(Graph* g);

	virtual ~StdRepresentative();

};

#endif /* SRC_SOLVER_STDREPRESENTATIVE_H_ */
