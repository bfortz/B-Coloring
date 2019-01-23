
#include "Solver.h"

//Constructor
Solver::Solver(Graph* h){
	g = h;
	tm = new Timer();
	elapsedtm = 0.0;
	solution = 0.0;
}

//Destructor
Solver::~Solver(){
	delete tm;
}

//Generic builder, initialize all the inner variables
void Solver::build(){
	innerbuild();
}

//Generic solve, update the current solution and the elapsed time
void Solver::solve(){
	tm->start();
	innerSolver();
	elapsedtm = tm->stop();
}

//Retrieves the optimal solution
long Solver::getSolution(){
	return solution;
}

//Retrieves the elapsed time
float Solver::getElapsedTime(){
	return elapsedtm;
}
