/*
 * Heuristic.cpp
 *
 *  Created on: 8 de jan de 2017
 *      Author: mcsma
 */

#include "Heuristic.h"

// an generic greedy algorithm to finished up coloring
void Heuristic::greedyAlgorithm(){
	//define the uncolored vertices
	Set* uncolored = new Set(n);
	uncolored->removeAll();
	for(int i = 0; i < szcl; i++){
		uncolored->unio(colours[i]);
	}
	uncolored->complement();

	int v, color, i;
	bool colored;

	while(!uncolored->isEmpty()){
		//get the firts uncolored vertex
		v = uncolored->firstElem();
		uncolored->remove(v);

		colored = false;
		color = 0;
		i = 0;
		//look for a color for v
		while(!colored && i < szcl){
			//Is there an neigbour of v colored with that color?
			if(g->getNeig(v)->isIntersEmpty(colours[i])){
				colours[i]->add(v);
				colored = true;
			}
			i++;
		}
		//if we could not find a color for v
		if(!colored){
			szcl++;
			colours[szcl]->add(v);
		}
	}
}

// the b coloring algorithm to verify that the b-coloring indeed respect all the constraints
void Heuristic::algoB(){
	Set* colenum = new Set(n);

	long v;

	bool bcolor;
	bool bv;
	long current;

	current = szcl;
	while(current > 0){
		colenum->removeAll();
		colenum->unio(colours[current]);
		v = 0;
		bcolor = false;
		while(!colenum->isEmpty() && !bcolor){
			bv = true;
			v = colenum->firstElemAfter(v);
			colenum->remove(v);
			for(int j = 0; j < szcl; j++){
				if(current!=j){
					if(g->getNeig(v)->isIntersEmpty(colours[j])) bv = false;
				}
			}
			if(bv) bcolor = true;
		}
		if(!bcolor){

		}
	}


}

//Initializes the interface
Heuristic::Heuristic(Graph* h) {
	szcl = 0;
	tm = new Timer();
	g = h;
	n = g->sizeV();
	colours = new Set*[n];
	for(int i = 0; i < n; i++){
		colours[i] = new Set(n);
	}
	elapsedtm = 0;
}

//Destroy the interface
Heuristic::~Heuristic() {
	for(int i = 0; i < n; i++){
		delete colours[i];
	}
	delete colours;
	delete tm;
}

//Interface to the solver
void Heuristic::solve() {
	tm->start();
	innerSolver();
	elapsedtm = tm->stop();
}

//Interface to the solver
void Heuristic::solve(Set* active) {
	tm->start();
	innerSolver(active);
	elapsedtm = tm->stop();
}

//Interface to the solver
void Heuristic::solve(Set* active, Set** colours2) {
	tm->start();
	innerSolver(active, colours2);
	elapsedtm = tm->stop();
}

//Retrive the optimal solution
long Heuristic::getSolution() {
	return szcl;
}

//Retrive the elapsed time to solve the problem
float Heuristic::getElapsedTime() {
	return elapsedtm;
}
