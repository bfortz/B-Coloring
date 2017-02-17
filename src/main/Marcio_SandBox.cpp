/*
 * Marcio_SandBox.cpp
 *
 *  Created on: 19 de dez de 2016
 *      Author: marcio
 */


#include "../tools/Graph.h"
#include "../tools/Set.h"
#include "../tools/Timer.h"
#include "../solver/Solver.h"
#include "../solver/Heuristic.h"
#include "../solver/BasicHeuristic.h"
#include "../solver/ImpRepresentative.h"
#include "Reader.h"
#include <cstdio>

int main(int argc, char **argv ){


	printf("Marcio's SandBox\n");

	printf("testing graph : %s", argv[1]);
	std::ifstream ifs (argv[1], std::ifstream::in);

	Reader myReader;

	Graph * g = myReader.read(ifs);

	g->print();

	int limit  = atoi(argv[2]);

	ImpRepresentative* rep = new ImpRepresentative(g, limit);

	rep->build();

	rep->solve();

	printf("Solution = %ld in time = %f \n", rep->getSolution(), rep->getElapsedTime());

	return 0;
}

