/*
 * Main.cpp
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
#include "../solver/ImpRepresentative.h"
#include "Reader.h"

int main(){
	printf("Main!\n");


	std::ifstream ifs ("instances/myciel5.col", std::ifstream::in);

	Reader myReader;

	Graph * myGraph = myReader.read(ifs);
	myGraph->print();

	ImpRepresentative* formulation = new ImpRepresentative(myGraph, 0);

	formulation->build();
	formulation->solve();

	printf("Solution = %ld \n", formulation->getSolution());

	//myGraph->print();
	return 0;
}

