/*
 * Reader.h
 *
 *  Created on: 19 de dez de 2016
 *      Author: marcio
 */

#ifndef SRC_MAIN_READER_H_
#define SRC_MAIN_READER_H_

#include <cstdio>
#include <cstdlib>

#include "../tools/Graph.h"

class Reader {
public:
	Reader();

	virtual ~Reader();

	static Graph* read(FILE*);
};

#endif /* SRC_MAIN_READER_H_ */
