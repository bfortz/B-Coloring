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
#include "Reader.h"

int main(){
	printf("Main!\n");


  std::ifstream ifs ("myciel5.col", std::ifstream::in);

	Reader myReader;

	Graph * myGraph = myReader.read(ifs);

myGraph->print();
	return 0;
}

