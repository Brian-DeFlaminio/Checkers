/*
 * Tests.cpp
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#include "Tests.h"
#include <stdbool.h>

Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}



bool Tests::tests()
{
	bool answer = true;

	bool ok3 = testReadFile();
	bool ok2 = testPopulateBoard();
	bool ok1 = testDisplayBoard();
	bool ok4 = testMoveChecker();
	bool ok5 = testCrownAwarded();
	bool ok6 = testCapture();
	answer = ok1 && ok2 && ok3 && ok4 && ok5  && ok6;
	return answer;
}

bool Tests::testReadFile()
{
	Board* theBoard = new Board();
	Production* pP = new Production();
	puts("starting testReadFile"); fflush(stdout);
	bool ok = true;



	ok = pP->readFile("boards.txt", theBoard);

	theBoard->displayBoard();
	ok = pP->getYesNo((char*)"Does the board look right?");
	if(ok)
	{
		puts("testReadfile did pass");
	}
	else
	{
		puts("testReadfile did not pass.");
	}

	return ok;
}

bool Tests::testPopulateBoard(){
	Board* theBoard = new Board();
	Board* comparisonBoard = new Board();
	Production* pP = new Production();
	puts("starting testPopulateBoard"); fflush(stdout);
	bool ok = true;
	theBoard->populateBoard(theBoard, 0, 0, 1);
	theBoard->populateBoard(theBoard, 7, 7, 1);
	pP->readFile("MTBoard.txt", comparisonBoard);

	theBoard->displayBoard();
	puts("\n------------------------------------------------\n");
	comparisonBoard->displayBoard();



	if(pP->getYesNo((char*)"These two boards should be the same, are they?"))
	{
		puts("testPopulateBoard did pass");
	}
	else
	{
		puts("testPopulateBoard did not pass.");
	}

	return ok;
}

bool Tests::testDisplayBoard(){
	Board* theBoard = new Board();
	Production* pP = new Production();
	puts("starting testDisplayBoard"); fflush(stdout);
	bool ok = true;

	theBoard->displayBoard();


	if((pP->getYesNo((char*)"Can you see an empty board?")))
	{
		puts("testDisplayBoard did pass");
	}
	else
	{
		puts("testDisplayBoard did not pass.");
	}

	return ok;
}

bool Tests::testMoveChecker(){
	Board* theBoard = new Board();
	puts("starting testMoveChecker"); fflush(stdout);
	bool ok = false;

	theBoard->populateBoard(theBoard, 2, 2, 1);
	CheckerPiece** redpawn = (theBoard->getBoardCorner()) + 2*8 + 2;
	CheckerPiece* thisredpawn = *redpawn;
	theBoard->populateBoard(theBoard, 3, 3, 2);
	CheckerPiece** redking = (theBoard->getBoardCorner()) + 3*8 + 3;
	CheckerPiece* thisredking = *redking;
	theBoard->populateBoard(theBoard, 4, 4, 3);
	CheckerPiece** blackpawn = (theBoard->getBoardCorner()) + 4*8 + 4;
	CheckerPiece* thisblackpawn = *blackpawn;
	theBoard->populateBoard(theBoard, 5, 5, 4);
	CheckerPiece** blackking = (theBoard->getBoardCorner()) + 5*8 + 5;
	CheckerPiece* thisblackking = *blackking;

	theBoard->moveChecker(theBoard, 2, 2, 1, 1, 1);
	CheckerPiece** redpawn1 = (theBoard->getBoardCorner()) + 1*8 + 1;
	CheckerPiece* thisredpawn1 = *redpawn1;
	theBoard->moveChecker(theBoard, 3, 3, 4, 2, 2);
	CheckerPiece** redking1 = (theBoard->getBoardCorner()) + 4*8 + 2;
	CheckerPiece* thisredking1 = *redking1;
	theBoard->moveChecker(theBoard, 4, 4, 3, 5, 4);
	CheckerPiece** blackpawn1 = (theBoard->getBoardCorner()) + 3*8 + 5;
	CheckerPiece* thisblackpawn1 = *blackpawn1;
	theBoard->moveChecker(theBoard, 5, 5, 6, 6, 3);
	CheckerPiece** blackking1 = (theBoard->getBoardCorner()) + 6*8 + 6;
	CheckerPiece* thisblackking1 = *blackking1;
	theBoard->displayBoard();

	if(!thisredpawn1==0&&!thisredking1==0&&!thisblackpawn1==0&&!thisblackking1==0){
		ok=true;
	}

	if(ok)
	{
		puts("testMoveChecker did pass");
	}
	else
	{
		puts("testMoveChecker did not pass.");
	}

	return ok;
}

bool Tests::testCrownAwarded(){
	Board* theBoard = new Board();
	puts("starting testCrownAwarded"); fflush(stdout);
	bool ok = false;

	theBoard->populateBoard(theBoard, 1, 1, 1);
	theBoard->moveChecker(theBoard, 1, 1, 0, 0, 1);
	theBoard->moveChecker(theBoard, 0, 0, 1, 1, 2);
	CheckerPiece** redpawntoking = (theBoard->getBoardCorner()) + 1*8 + 1;
	CheckerPiece* thisredpawntoking = *redpawntoking;
	bool isking = thisredpawntoking->getIsKing();
	bool isred = thisredpawntoking->getIsRed();

	if(isred&&isking){
		ok=true;
	}


	if(ok)
	{
		puts("testCrownAwarded did pass");
	}
	else
	{
		puts("testCrownAwarded did not pass.");
	}

	return ok;
}

bool Tests::testCapture(){
	Board* theBoard = new Board();
	puts("starting testCapture"); fflush(stdout);
	bool ok = false;

	theBoard->populateBoard(theBoard, 3, 3, 2);
	theBoard->populateBoard(theBoard, 4, 4, 3);
	theBoard->moveChecker(theBoard, 3, 3, 4, 4, 2);

	CheckerPiece** shouldbeemptynow = (theBoard->getBoardCorner()) + 4*8 + 4;
	CheckerPiece* betterbeempty = *shouldbeemptynow;
	CheckerPiece** shouldhaveking = (theBoard->getBoardCorner()) + 5*8 + 5;
	CheckerPiece* betterhaveaking = *shouldhaveking;

	if(betterbeempty==0&&!betterhaveaking==0){
		ok=true;
	}

	if(ok)
	{
		puts("testCapture did pass");
	}
	else
	{
		puts("testCapture did not pass.");
	}

	return ok;
}
