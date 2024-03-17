/*
 * Tests.h
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#ifndef TESTS_H_
#define TESTS_H_
#include "Production.h"
#include <stdio.h>
#include "Board.h"



class Tests {
public:
	Tests();
	virtual ~Tests();
	bool tests();

private:
	bool testReadFile();
	bool testPopulateBoard();
	bool testDisplayBoard();
	bool testMoveChecker();
	bool testCrownAwarded();
	bool testCapture();

};

#endif /* TESTS_H_ */
