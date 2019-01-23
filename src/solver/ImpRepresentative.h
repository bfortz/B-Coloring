

#ifndef SRC_SOLVER_IMPREPRESENTATIVE_H_
#define SRC_SOLVER_IMPREPRESENTATIVE_H_

#include </opt/ibm/ILOG/CPLEX_Studio127/opl/include/ilcplex/cplex.h>
#include <stdlib.h>
#include <string.h>
#include "Solver.h"

class ImpRepresentative: public Solver{
protected:
	CPXENVptr env = NULL;
	CPXLPptr lp = NULL;

	long** x;

	long lb;

	long n;

	long var;

	void innerbuild(); //the real builder

	void innerSolver(); // the method that solves the problem

	void addBinVar(double coef, char* name);

	void addEdgeConst(long v, long u, long w);

	void addSingleVConst(long v, long u);

	void addRepresentativeConst(long v);

	void addBcolConstraint(long v, long u);

public:
	ImpRepresentative(Graph* g, long lb);

	virtual ~ImpRepresentative();
};

#endif /* SRC_SOLVER_IMPREPRESENTATIVE_H_ */
