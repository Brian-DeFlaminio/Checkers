/*
 * Board.h
 *
 *  Created on: Aug 2, 2021
 *      Author: theresesmith
 */

#ifndef BOARD_H_
#define BOARD_H_
#include <stdio.h>
#include "CheckerPiece.h"

class Board {
public:
	Board();
	virtual ~Board();
	void displayBoard();
	void printBoardToFile(FILE* file);
	void populateBoard(Board* theBoard, int r, int c, int color);
	CheckerPiece** getBoardCorner();
	void moveChecker(Board* theBoard, int oldX, int oldY, int moveX, int moveY, int theNum);
	void crownAwarded(Board* theBoard, int moveX, int moveY, int theNum);
	void capture(Board* theBoard, int oldX, int oldY, int moveX, int moveY, int theNum, CheckerPiece* thisChecker);

private:
	CheckerPiece** boardCorner;
	};


#endif /* BOARD_H_ */
