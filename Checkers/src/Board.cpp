/*
 * Board.cpp
 *
 *  Created on: Aug 2, 2021
 *      Author: theresesmith
 */

#include "Board.h"
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


Board::Board() {
	// TODO Auto-generated constructor stub
	boardCorner = (CheckerPiece**) malloc(8*8*sizeof(CheckerPiece*));

	for(int r = 0; r<8; r++){
		for(int c = 0; c<8; c++){
			CheckerPiece** thatSpaceP = boardCorner + r*8 + c;
			*thatSpaceP = NULL;
		}
	}
	//later on these locations will have checkers put in them if they exist
}

Board::~Board() {
	// TODO Auto-generated destructor stub
}


void Board::crownAwarded(Board* theBoard, int moveX, int moveY, int theNum){

	if(theNum==1){
		if(moveX==0){
			//puts("got here");
			theBoard->populateBoard(theBoard, moveX, moveY, 0); //remove old piece
			theBoard->populateBoard(theBoard, moveX, moveY, 2); //red king
		}
		else{

		}
	}

	else if(theNum==3){
		if(moveX==7){
			theBoard->populateBoard(theBoard, moveX, moveY, 0); //remove old piece
			theBoard->populateBoard(theBoard, moveX, moveY, 4); //black king
		}
		else{

		}
	}
	else{
		theBoard->populateBoard(theBoard, moveX, moveY, theNum);
	}
}

void Board::moveChecker(Board* theBoard, int oldX, int oldY, int moveX, int moveY, int theNum){
	CheckerPiece** thatSpacePToGoTo = (theBoard->getBoardCorner()) + moveX*8 + moveY;
	CheckerPiece* thisCheckerToGoTo = *thatSpacePToGoTo;
	if(theNum==1){
		//red pawn moveset
		//puts("red pawn moveset chosen");
		if(((moveX-oldX==-1)&&(moveY-oldY==1))||((moveX-oldX==-1)&&(moveY-oldY==-1))){
			if(!thisCheckerToGoTo==0){
				theBoard->capture(theBoard, oldX, oldY, moveX, moveY, theNum, thisCheckerToGoTo); // is there a capture? if not, go about a regular turn
			}
			else{
				theBoard->populateBoard(theBoard, oldX, oldY, 0); //remove old location
				theBoard->populateBoard(theBoard, moveX, moveY, theNum); //place new location
				theBoard->crownAwarded(theBoard, moveX, moveY, theNum); //update the checker to a king if appropriate
			}
		}
		else{
			puts("Invalid move");
		}
	}
	else if(theNum==3){
		//black pawn moveset
		//puts("black pawn moveset chosen");
		if(((moveX-oldX==1)&&(moveY-oldY==1))||((moveX-oldX==1)&&(moveY-oldY==-1))){
			if(!thisCheckerToGoTo==0){
				theBoard->capture(theBoard, oldX, oldY, moveX, moveY, theNum, thisCheckerToGoTo); // is there a capture? if not, go about a regular turn
			}
			else{
				theBoard->populateBoard(theBoard, oldX, oldY, 0); //remove old location
				theBoard->populateBoard(theBoard, moveX, moveY, theNum); //place new location
				theBoard->crownAwarded(theBoard, moveX, moveY, theNum); //update the checker to a king if appropriate
			}
		}
		else{
			puts("Invalid move");
		}
	}
	else if (theNum==2||theNum==4){
		//red and black king moveset
		puts("king moveset chosen");
		if(((moveX-oldX==-1)&&(moveY-oldY==1))||((moveX-oldX==1)&&(moveY-oldY==-1))||((moveX-oldX==1)&&(moveY-oldY==1))||((moveX-oldX==-1)&&(moveY-oldY==-1))){
			if(!thisCheckerToGoTo==0){
				theBoard->capture(theBoard, oldX, oldY, moveX, moveY, theNum, thisCheckerToGoTo); // is there a capture? if not, go about a regular turn
			}
			else{
				theBoard->populateBoard(theBoard, oldX, oldY, 0); //remove old location
				theBoard->populateBoard(theBoard, moveX, moveY, theNum); //place new location
			}
		}
		else{
			puts("Invalid move");
		}
	}
}


void Board::displayBoard() {
	printf(" |0|1|2|3|4|5|6|7|");
	printf("\n");
	for(int r = 0; r<8; r++)
	{
		printf("%d",r);
		for(int c = 0; c<8; c++)
		{
			CheckerPiece** thatSpaceP = this->boardCorner + r*8 + c;
			CheckerPiece* thisChecker = *thatSpaceP;
			if(thisChecker==0||thisChecker==NULL){
				printf("| ");
			}
			else{
				bool isRed = thisChecker->getIsKing();
				bool isKing = thisChecker->getIsRed();
				//printf("isKing is:%d  isRed is:%d\n", isKing, isRed);
				//printf("The pointer is: %p\n", boardCorner);
				if(isRed&&isKing)
				{
					printf("|R");
				}
				else if(isRed&&!isKing){
					printf("|r");
				}
				else if(!isRed&&!isKing){
					printf("|b");
				}
				else if(!isRed&&isKing){
					printf("|B");
				}
				else{
					puts("Something went wrong...");
				}
			}


		}
		printf("|\n");
	}

}

void Board::populateBoard(Board* theBoard, int r, int c, int color)
{
	//the space that the checker we are currently dealing with will occupy
	CheckerPiece** thatSpaceP = (theBoard->getBoardCorner()) + r*8 + c;

	//this is where the info of that scanned checker goes
	CheckerPiece* aChecker = (CheckerPiece*) malloc(sizeof(CheckerPiece));

	//black king
	if(color==1){
		aChecker->setIsKing(true);
		aChecker->setIsRed(false);
		aChecker->setxCoord(r);
		aChecker->setyCoord(c);
		*thatSpaceP = aChecker; //put its address into board space
		printf("Checker was a black king, placed at %d,%d\n", r, c);
	}
	//red king
	else if(color==2){
		aChecker->setIsKing(true);
		aChecker->setIsRed(true);
		aChecker->setxCoord(r);
		aChecker->setyCoord(c);
		*thatSpaceP = aChecker;
		printf("Checker was a red king, placed at %d,%d\n", r, c);
	}
	//black pawn
	else if(color==3){
		aChecker->setIsKing(false);
		aChecker->setIsRed(false);
		aChecker->setxCoord(r);
		aChecker->setyCoord(c);
		*thatSpaceP = aChecker;
		printf("Checker was a black pawn, placed at %d,%d\n", r, c);
	}
	//red pawn
	else if(color==4){
		aChecker->setIsKing(false);
		aChecker->setIsRed(true);
		aChecker->setxCoord(r);
		aChecker->setyCoord(c);
		*thatSpaceP = aChecker;
		printf("Checker was a black king, placed at %d,%d\n", r, c);
	}
	else{
		//empty spot
		*thatSpaceP = (CheckerPiece*)0;
		printf("Checker was empty\n");
	}

}



CheckerPiece** Board::getBoardCorner(){
	return this->boardCorner;
}


void Board::capture(Board* theBoard, int oldX, int oldY, int moveX, int moveY, int theNum, CheckerPiece* thisChecker){
	bool isRed = thisChecker->getIsRed();
	bool isKing = thisChecker->getIsKing();
	int nextSpotsNum;
	if(isRed&&isKing)
	{
		nextSpotsNum=2; //red king
	}
	else if(isRed&&!isKing){
		nextSpotsNum=3; //red pawn
	}
	else if(!isRed&&!isKing){
		nextSpotsNum=3; //black pawn
	}
	else if(!isRed&&isKing){
		nextSpotsNum=1; //black king
	}
	else{
		puts("Something went wrong...");
	}
	bool sameTeam = false;
	//dont mind this mess, a wise man would have organized things better, but a wise man I am not.
	if((theNum==nextSpotsNum)||(theNum==2&&nextSpotsNum==1)||(theNum==1&&nextSpotsNum==2)||(theNum==3&&nextSpotsNum==4)||(theNum==4&&nextSpotsNum==3)){
		sameTeam=true;
	}
	if(!sameTeam){
		//up right move
		if((moveX-oldX==-1)&&(moveY-oldY==1)){
			CheckerPiece** destinationSpace = (theBoard->getBoardCorner()) + (moveX-1)*8 + (moveY+1);
			CheckerPiece* thisCheckersDestination = *destinationSpace;
			if(thisCheckersDestination==0){
				puts("Piece Captured!");
				theBoard->populateBoard(theBoard, moveX, moveY, 0); //remove old location
				theBoard->populateBoard(theBoard, moveX-1, moveY+1, theNum);
				theBoard->populateBoard(theBoard, oldX, oldY, 0); //remove old location
				theBoard->crownAwarded(theBoard, moveX-1, moveY+1, theNum); //update the checker to a king if appropriate
			}
			else{
				puts("destination space isn't empty!");
			}
		}
		//up left move
		else if((moveX-oldX==-1)&&(moveY-oldY==-1)){
			CheckerPiece** destinationSpace = (theBoard->getBoardCorner()) + (moveX-1)*8 + (moveY-1);
			CheckerPiece* thisCheckersDestination = *destinationSpace;
			if(thisCheckersDestination==0){
				puts("Piece Captured!");
				theBoard->populateBoard(theBoard, moveX, moveY, 0); //remove old location
				theBoard->populateBoard(theBoard, moveX-1, moveY-1, theNum);
				theBoard->populateBoard(theBoard, oldX, oldY, 0); //remove old location
				theBoard->crownAwarded(theBoard, moveX-1, moveY-1, theNum); //update the checker to a king if appropriate
			}
			else{
				puts("destination space isn't empty!");
			}
		}
		//down right move
		else if((moveX-oldX==1)&&(moveY-oldY==1)){
			CheckerPiece** destinationSpace = (theBoard->getBoardCorner()) + (moveX+1)*8 + (moveY+1);
			CheckerPiece* thisCheckersDestination = *destinationSpace;
			if(thisCheckersDestination==0){
				puts("Piece Captured!");
				theBoard->populateBoard(theBoard, moveX, moveY, 0); //remove old location
				theBoard->populateBoard(theBoard, moveX+1, moveY+1, theNum);
				theBoard->populateBoard(theBoard, oldX, oldY, 0); //remove old location
				theBoard->crownAwarded(theBoard, moveX+1, moveY+1, theNum); //update the checker to a king if appropriate
			}
			else{
				puts("destination space isn't empty!");
			}
		}
		//down left move
		else if((moveX-oldX==1)&&(moveY-oldY==-1)){
			CheckerPiece** destinationSpace = (theBoard->getBoardCorner()) + (moveX+1)*8 + (moveY-1);
			CheckerPiece* thisCheckersDestination = *destinationSpace;
			if(thisCheckersDestination==0){
				puts("Piece Captured!");
				theBoard->populateBoard(theBoard, moveX, moveY, 0); //remove old location
				theBoard->populateBoard(theBoard, moveX+1, moveY-1, theNum);
				theBoard->populateBoard(theBoard, oldX, oldY, 0); //remove old location
				theBoard->crownAwarded(theBoard, moveX+1, moveY-1, theNum); //update the checker to a king if appropriate
			}
			else{
				puts("destination space isn't empty!");
			}
		}
	}
	else{
		puts("Cannot take your own piece!");
	}
}



void Board::printBoardToFile(FILE* fd){


	fprintf(fd," |0|1|2|3|4|5|6|7|");
		fprintf(fd,"\n"); fflush(fd);
		for(int r = 0; r<8; r++)
		{
			fprintf(fd,"%d",r); fflush(fd);
			for(int c = 0; c<8; c++)
			{
				CheckerPiece** thatSpaceP = this->boardCorner + r*8 + c;
				CheckerPiece* thisChecker = *thatSpaceP;
				if(thisChecker==0||thisChecker==NULL){
					fprintf(fd,"| "); fflush(fd);
				}
				else{
					bool isRed = thisChecker->getIsKing();
					bool isKing = thisChecker->getIsRed();
					//printf("isKing is:%d  isRed is:%d\n", isKing, isRed);
					//printf("The pointer is: %p\n", boardCorner);
					if(isRed&&isKing)
					{
						fprintf(fd,"|R"); fflush(fd);
					}
					else if(isRed&&!isKing){
						fprintf(fd,"|r"); fflush(fd);
					}
					else if(!isRed&&!isKing){
						fprintf(fd,"|b"); fflush(fd);
					}
					else if(!isRed&&isKing){
						fprintf(fd,"|B"); fflush(fd);
					}
					else{
						puts("Something went wrong...");
					}
				}


			}
			fprintf(fd,"|\n"); fflush(fd);
		}

		fprintf(fd,"\n\n"); fflush(fd);

}
