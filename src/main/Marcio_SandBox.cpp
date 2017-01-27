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
#include "../solver/StdRepresentative.h"
#include "Reader.h"
#include <cstdio>

int main(){
	printf("Marcio's SandBox\n");

	Graph* g = new Graph(6);

	g->addEdge(0, 1);

	g->addEdge(1, 2);

	g->addEdge(2, 3);

	g->addEdge(3, 4);

	g->addEdge(4, 5);

	g->addEdge(5, 0);

	g->print();

	BasicHeuristic* bh = new BasicHeuristic(g);

	bh->solve();

	bh->print();

	return 0;
}

