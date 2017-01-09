/*
 * Set.h
 *
 *  Created on: 19 de dez de 2016
 *      Author: marcio
 */

#ifndef SRC_TOOLS_SET_H_
#define SRC_TOOLS_SET_H_

/**
 * Representation of a set of integer numbers
 * */
class Set {
private:
	bool* elems;// binary representation
	long size;//number of elements
public:
	//build a emptyset with size "size"
	Set(int size);

	//destroy the set
	virtual ~Set();

	//add elem to the set
	void add(long elem);

	//add all posible elems
	void addAll();

	//remove elem of the set
	void remove(long elem);

	//remove all the elems of the set
	void removeAll();

	//verify if the elem is in the set or not
	bool isIn(long elem);

	//intersects the current set with the set s
	void inter(Set* s);

	//subtracts the set s from the current set
	void subtr(Set* s);

	//add all elements of the set s into the current set
	void unio(Set* s);

	//returns the first element of the set
	long firstElem();

	//returns the first element of the set greater ot equals to elem
	long firstElemAfter(long elem);
};

#endif /* SRC_TOOLS_SET_H_ */
