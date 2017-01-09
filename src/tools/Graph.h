/*
 * Graph.h
 *
 *  Created on: 19 de dez de 2016
 *      Author: marcio
 */

#ifndef SRC_TOOLS_GRAPH_H_
#define SRC_TOOLS_GRAPH_H_

#include "Set.h"

/*A simple graph*/
class Graph {
private:
	long n; // number of vertices
	long m; // number of edges

	Set** edges; //the adjacent matrix of the graph
public:
	//build a empty graph with n nodes
	Graph(long n);

	//destroy the given graph
	virtual ~Graph();

	//add an edge between u and v
	void addEdge(long v, long u);

	//add an edge between v and u
	void removeEdge(long v, long u);

	//verify if there is an edge between v and u
	bool hasEdge(long v, long u);

	//gets the neighboors of v
	Set* getNeig(long v);

};

#endif /* SRC_TOOLS_GRAPH_H_ */
