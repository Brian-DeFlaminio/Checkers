/*
 * CheckerPiece.cpp
 *
 *  Created on: Sep 25, 2021
 *      Author: bdefl
 */

#include "CheckerPiece.h"

CheckerPiece::CheckerPiece() {
	// TODO Auto-generated constructor stub
}

CheckerPiece::~CheckerPiece() {
	// TODO Auto-generated destructor stub
}

void CheckerPiece::setIsKing(bool isKing){
	this->isKing = isKing;
}

void CheckerPiece::setIsRed(bool isRed){
	this->isRed = isRed;
}

void CheckerPiece::setxCoord(int xCoord){
	this->xCoord = xCoord;
}

void CheckerPiece::setyCoord(int yCoord){
	this->yCoord = yCoord;
}


bool CheckerPiece::getIsKing(){
	return this->isKing;
}

bool CheckerPiece::getIsRed(){
	return this->isRed;
}

int CheckerPiece::getxCoord(){
	return this->xCoord;
}

int CheckerPiece::getyCoord(){
	return this->yCoord;
}
