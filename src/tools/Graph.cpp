/*
 * Graph.cpp
 *
 *  Created on: 19 de dez de 2016
 *      Author: marcio
 */

#include "Graph.h"

#include <cstdlib>

//build a empty graph with n nodes
Graph::Graph(long n){
	this->n = n; // number of vertices
	m = 0; // number of edges

	edges = new Set*[n];
	for(int i = 0; i < n; i++) edges[i] = new Set(n);
}

//destroy the given graph
Graph::~Graph(){
	for(int i = 0; i < n; i++) delete edges[i];
	delete edges;
}

//add an edge between u and v
void Graph::addEdge(long v, long u){
	edges[v]->add(u);
	edges[u]->add(v);
}

//add an edge between v and u
void Graph::removeEdge(long v, long u){
	edges[v]->remove(u);
	edges[u]->remove(v);
}

//verify if there is an edge between v and u
bool Graph::hasEdge(long v, long u){
	return edges[v]->isIn(u);
}

//gets the neighboors of v
Set* Graph::getNeig(long v){
	Set* ret = new Set(n);
	ret->unio(edges[v]);
	return ret;
}

