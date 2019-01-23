


#include "../tools/Graph.h"
#include "../tools/Set.h"
#include "../tools/Timer.h"
#include "../solver/Solver.h"
#include "../solver/Heuristic.h"
#include "../solver/ImpRepresentative.h"
#include "Reader.h"

int main(){
	printf("Main!\n");


	std::ifstream ifs ("bin/dimacs/myciel2.col", std::ifstream::in);

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

