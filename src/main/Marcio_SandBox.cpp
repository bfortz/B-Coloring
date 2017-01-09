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
#include "../solver/StdRepresentative.h"
#include "Reader.h"
#include <cstdio>

int main(){
	printf("Marcio's SandBox\n");

	Graph* g = new Graph(10);

	g->addEdge(0, 1);

	g->addEdge(0, 2);

	g->addEdge(1, 3);

	g->addEdge(1, 4);

	g->addEdge(4, 5);
	printf("degre of 1: %ld \n", g->degree(1));

	g->print();

	g->removeEdge(0, 1);

	g->print();

	printf("degre of 1: %ld \n", g->degree(1));

	return 0;
}

