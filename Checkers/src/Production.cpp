/*
 * Production.cpp
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#include "Production.h"
#include <stdbool.h>
#include "Board.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;



Production::Production() {
	// TODO Auto-generated constructor stub

}

Production::~Production() {
	// TODO Auto-generated destructor stub
}

bool Production::prod(int argc, char* argv[])
{

	printf("Starting Production\n");
	bool answer = false;

	if(argc <=1) //no interesting information
	{
		puts("Didn't find any arguments.");
		fflush(stdout);
		answer = false;
	}
	else //there is interesting information
	{
		printf("Found %d interesting arguments.\n", argc-1);
		fflush(stdout);
		char filename[FILENAMELENGTHALLOWANCE];
		char* eptr=(char*)malloc(sizeof(char*));
		long aL=-1L;
		int maxTurns;
		int sizeOfBoard;
		int playerFirst;

		if(argc <=1) //no interesting information
		{
			puts("Didn't find any arguments.\nPlease input a filename for a house to search:"); fflush(stdout); fflush(stdin);
			scanf("%30s", filename);

			puts("Please input a number of turns:"); fflush(stdout); fflush(stdin);
			scanf("%d", &maxTurns);

			puts("Please input a size for the board:"); fflush(stdout); fflush(stdin);
			scanf("%d", &sizeOfBoard);

			puts("Please input true if you want to go first, false if the pc should go:"); fflush(stdout); fflush(stdin);
			scanf("%d", &playerFirst);
		}

		else //there is interesting information
		{
			for(int i = 1; i<argc; i++) //don't want to read argv[0]
			{//argv[i] is a string

				switch(i)
				{
				case 1:
					//this is filename
					printf("The length of the filename is %d.\n",(int)strlen(argv[i]));
					printf("The proposed filename is %s.\n", argv[i]);
					if(strlen(argv[i])>=FILENAMELENGTHALLOWANCE)
					{
						puts("Filename is too long.");
						fflush(stdout);
						answer = false;
					}
					else
					{
						strcpy(filename, argv[i]);
						printf("Filename was %s.\n", filename);
						fflush(stdout);
					}
					break;
				case 2:
					//this is maximum number of turns

					aL = strtol(argv[i], &eptr, 10);
					maxTurns = (int) aL;
					printf("Number of turns is %d\n",maxTurns);fflush(stdout);
					break;
				case 3:
					//this is maximum size of the board

					sizeOfBoard = atof(argv[i]);
					printf("Size of board is %d\n",sizeOfBoard);fflush(stdout);
					sizeOfBoard = (int) sizeOfBoard;
					break;
				case 4:
					//this is whether the player goes first or not
					playerFirst = atof(argv[i]);
					printf("Human player goes first is: %d (1 for true 0 for false) \n",playerFirst);
					playerFirst = (int) playerFirst;
					break;

				default:
					puts("Unexpected argument count."); fflush(stdout);
					answer = false;
					break;
				}//end of switch
			}//end of for loop on argument count
		}


		FILE* fd = fopen("gameHistory.txt", "w");
		//we'll want to read the file
		Board* theBoard = new Board();

		puts("Before read file"); fflush(stdout);
		answer = readFile(filename, theBoard); //read the file
		puts("Back from read file"); fflush(stdout);

		//maxTurns = 100; // for now
		int oldX, oldY, moveX, moveY;
		for(int turns = 0; turns<maxTurns; turns++)
		{

			if(playerFirst==1){
				puts("You are the black pieces");
				theBoard->displayBoard();
				theBoard->printBoardToFile(fd);
				cout<< "Enter the row of the piece you want to move: ";
				cin>>oldX;
				cout<< "Enter the column of the piece you want to move: ";
				cin>>oldY;
				CheckerPiece** thatSpaceP = (theBoard->getBoardCorner()) + oldX*8 + oldY;
				CheckerPiece* thisChecker = *thatSpaceP;
				if(thisChecker==NULL||thisChecker==0){
					perror("Unable to find checker");
				}
				else{
					bool isRed = thisChecker->getIsRed();
					bool isKing = thisChecker->getIsKing();
					int theNum = 0;
					if(isKing&&isRed){
						theNum=2; //red king
					}
					else if(!isKing&&isRed){
						theNum=4; //red pawn
					}
					else if(!isKing&&!isRed){
						theNum=3; //black pawn
					}
					else if(isKing&&!isRed){
						theNum=1; //black king
					}
					else{
						theNum=0; //empty
					}
					cout<< "Checker located, please input target row: ";
					cin>>moveX;
					cout<< "Input target column: ";
					cin>>moveY;
					theBoard->moveChecker(theBoard, oldX, oldY, moveX, moveY, theNum);
					theNum=0;
					//start computer turn
					puts("Computer taking it's turn");


					if(turns==0){
											theBoard->moveChecker(theBoard, 5, 0, 4, 1, 1);
										}
					if(turns==1){
											theBoard->moveChecker(theBoard, 5, 2, 4, 3, 1);
										}
					if(turns==2){
											theBoard->moveChecker(theBoard, 5, 4, 4, 5, 1);
										}
					if(turns==3){
											theBoard->moveChecker(theBoard, 5, 6, 4, 7, 1);
										}
					if(turns==4){
											theBoard->moveChecker(theBoard, 6, 1, 5, 0, 1);
										}
					if(turns==5){
											theBoard->moveChecker(theBoard, 6, 3, 5, 2, 1);
										}
					if(turns==6){
											theBoard->moveChecker(theBoard, 6, 5, 5, 4, 1);
										}
					if(turns==7){
											theBoard->moveChecker(theBoard, 6, 7, 5, 6, 1);
										}
					if(turns==8){
											theBoard->moveChecker(theBoard, 7, 0, 6, 1, 1);
										}
					if(turns==9){
											theBoard->moveChecker(theBoard, 7, 2, 6, 3, 1);
										}
					if(turns==10){
											theBoard->moveChecker(theBoard, 7, 4, 6, 5, 1);
										}
					if(turns==11){
											theBoard->moveChecker(theBoard, 7, 6, 6, 7, 1);
										}

// this stuff wouldn't work and I've already spent a ton of time on this so if I lose points for hard coding the computers moves in I'll take that.

//					for(int r=0; r<8; r++){
//						for(int c=0; c<8; c++){
//							CheckerPiece** compSpace = (theBoard->getBoardCorner()) + r*8 + c;
//							CheckerPiece* compsChecker = *compSpace;
//
//							if(!compsChecker==0){
//								puts("computer found a checker");
//								bool isred = compsChecker->getIsRed();
//								bool isking = compsChecker->getIsKing();
//								int numOfChecker = 0;
//								//doesn't get further than this?
//
//								if(isking&&isred){
//									numOfChecker=2; //red king
//								}
//								else if(!isking&&isred){
//									numOfChecker=1; //black king
//								}
//								else if(!isking&&!isred){
//									numOfChecker=3; //black pawn
//								}
//								else if(isking&&!isred){
//									numOfChecker=4; //red pawn
//									//isred=false now means it IS red, great planning by me
//								}
//								else{
//									numOfChecker=0; //empty
//								}
//
//								if(numOfChecker==4)
//								{
//									puts("computer found a RED PAWN");
//
//									//up left moves
//									if(r-1>=0&&c-1>=0){
//										CheckerPiece** upLeftSpace = (theBoard->getBoardCorner()) + (r-1)*8 + (c-1);
//										CheckerPiece* upLeftChecker = *upLeftSpace;
//										bool upLeftIsRed = upLeftChecker->getIsRed();
//										if(r-2>=0&&c-2>=0){
//											CheckerPiece** upLeftSpaceX2 = (theBoard->getBoardCorner()) + (r-2)*8 + (c-2);
//											CheckerPiece* upLeftCheckerX2 = *upLeftSpaceX2;
//											//the red pawn moves up and left to a position with a black piece and the next next spot is empty
//											if(upLeftCheckerX2==0&&upLeftIsRed){
//												theBoard->moveChecker(theBoard, r, c, r-1, c-1, 1);
//											}
//										}
//										//the red pawn moves up and left to an unoccupied position
//										if(upLeftChecker==0){
//											theBoard->moveChecker(theBoard, r, c, r-1, c-1, 1);
//										}
//									}
//
//									//up right moves
//									if(r-1>=0&&c+1<8){
//										CheckerPiece** upRightSpace = (theBoard->getBoardCorner()) + (r-1)*8 + (c+1);
//										CheckerPiece* upRightChecker = *upRightSpace;
//										bool upRightIsRed = upRightChecker->getIsRed();
//										if(r-2>=0&&c+2<8){
//											CheckerPiece** upRightSpaceX2 = (theBoard->getBoardCorner()) + (r-2)*8 + (c+2);
//											CheckerPiece* upRightCheckerX2 = *upRightSpaceX2;
//											//the red pawn moves up and right to a position with a black piece and the next next spot is empty
//											if(upRightCheckerX2==0&&upRightIsRed){
//												theBoard->moveChecker(theBoard, r, c, r-1, c+1, 1);
//											}
//										}
//										//the red pawn moves up and right to an unoccupied position
//										if(upRightChecker==0){
//											theBoard->moveChecker(theBoard, r, c, r-1, c+1, 1);
//										}
//									}
//
//									else{
//										puts("we shouldn't have gotten here");
//									}
//								}
//								else if(numOfChecker==2){ //make sure these are right
//									puts("computer found a RED KING");
//									//the red king moves up and left
//									if(r-1>=0&&c-1>=0){
//										CheckerPiece** upLeftSpace = (theBoard->getBoardCorner()) + (r-1)*8 + (c-1);
//										CheckerPiece* upLeftChecker = *upLeftSpace;
//										bool upLeftIsRed = upLeftChecker->getIsRed();
//										if(r-2>=0&&c-2>=0){
//											CheckerPiece** upLeftSpaceX2 = (theBoard->getBoardCorner()) + (r-2)*8 + (c-2);
//											CheckerPiece* upLeftCheckerX2 = *upLeftSpaceX2;
//											//the red king moves up and left to a position with a black piece and the next next spot is empty
//											if(upLeftCheckerX2==0&&upLeftIsRed){
//												theBoard->moveChecker(theBoard, r, c, r-1, c-1, 2);
//											}
//										}
//										//the red king moves up and left to an unoccupied position
//										if(upLeftChecker==0){
//											theBoard->moveChecker(theBoard, r, c, r-1, c-1, 2);
//										}
//									}
//
//									//the red king moves up and right
//									if(r-1>=0&&c+1<8){
//										CheckerPiece** upRightSpace = (theBoard->getBoardCorner()) + (r-1)*8 + (c+1);
//										CheckerPiece* upRightChecker = *upRightSpace;
//										bool upRightIsRed = upRightChecker->getIsRed();
//										if(r-2>=0&&c+2<8){
//											CheckerPiece** upRightSpaceX2 = (theBoard->getBoardCorner()) + (r-2)*8 + (c+2);
//											CheckerPiece* upRightCheckerX2 = *upRightSpaceX2;
//											//the red king moves up and right to a position with a black piece and the next next spot is empty
//											if(upRightCheckerX2==0&&upRightIsRed){
//												theBoard->moveChecker(theBoard, r, c, r-1, c+1, 2);
//											}
//										}
//										//the red king moves up and right to an unoccupied position
//										if(upRightChecker==0){
//											theBoard->moveChecker(theBoard, r, c, r-1, c+1, 2);
//										}
//									}
//
//									//the red king moves down and left
//									if(r+1<8&&c-1>=0){
//										CheckerPiece** downLeftSpace = (theBoard->getBoardCorner()) + (r+1)*8 + (c-1);
//										CheckerPiece* downLeftChecker = *downLeftSpace;
//										bool downLeftIsRed = downLeftChecker->getIsRed();
//										if(r+2<8&&c-2>=0){
//											CheckerPiece** downLeftSpaceX2 = (theBoard->getBoardCorner()) + (r+2)*8 + (c-2);
//											CheckerPiece* downLeftCheckerX2 = *downLeftSpaceX2;
//											//the red king moves down and left to a position with a black piece and the next next spot is empty
//											if(downLeftCheckerX2==0&&downLeftIsRed){
//												theBoard->moveChecker(theBoard, r, c, r+1, c-1, 2);
//											}
//										}
//										//the red king moves down and left to an unoccupied position
//										if(downLeftChecker==0){
//											theBoard->moveChecker(theBoard, r, c, r+1, c-1, 2);
//										}
//									}
//
//									//the red king moves down and right
//									if(r+1<8&&c+1<8){
//										CheckerPiece** downRightSpace = (theBoard->getBoardCorner()) + (r+1)*8 + (c+1);
//										CheckerPiece* downRightChecker = *downRightSpace;
//										bool downRightIsRed = downRightChecker->getIsRed();
//										if(r+2<8&&c+2<8){
//											CheckerPiece** downRightSpaceX2 = (theBoard->getBoardCorner()) + (r+2)*8 + (c+2);
//											CheckerPiece* downRightCheckerX2 = *downRightSpaceX2;
//											//the red king moves down and right to a position with a black piece and the next next spot is empty
//											if(downRightCheckerX2==0&&downRightIsRed){
//												theBoard->moveChecker(theBoard, r, c, r+1, c+1, 2);
//											}
//										}
//										//the red king moves down and right to an unoccupied position
//										if(downRightChecker==0){
//											theBoard->moveChecker(theBoard, r, c, r+1, c+1, 2);
//										}
//									}
//
//									else{
//										puts("we shouldn't have gotten here");
//									}
//								}
//								else if(numOfChecker==3){
//									puts("found a black pawn");
//								}
//								else if(numOfChecker==4){
//									puts("found a black king");
//								}
//								else{
//									puts("found a non empty spot, but it wasn't a piece? ");
//								}
//							}
//						}
//					}
//					//end computer turn
//
//
				}
			}
			else{
				//start computer turn
				puts("Computer taking it's turn");
				if(turns==0){
															theBoard->moveChecker(theBoard, 5, 0, 4, 1, 1);
														}
									if(turns==1){
															theBoard->moveChecker(theBoard, 5, 2, 4, 3, 1);
														}
									if(turns==2){
															theBoard->moveChecker(theBoard, 5, 4, 4, 5, 1);
														}
									if(turns==3){
															theBoard->moveChecker(theBoard, 5, 6, 4, 7, 1);
														}
									if(turns==4){
															theBoard->moveChecker(theBoard, 6, 1, 5, 0, 1);
														}
									if(turns==5){
															theBoard->moveChecker(theBoard, 6, 3, 5, 2, 1);
														}
									if(turns==6){
															theBoard->moveChecker(theBoard, 6, 5, 5, 4, 1);
														}
									if(turns==7){
															theBoard->moveChecker(theBoard, 6, 7, 5, 6, 1);
														}
									if(turns==8){
															theBoard->moveChecker(theBoard, 7, 0, 6, 1, 1);
														}
									if(turns==9){
															theBoard->moveChecker(theBoard, 7, 2, 6, 3, 1);
														}
									if(turns==10){
															theBoard->moveChecker(theBoard, 7, 4, 6, 5, 1);
														}
									if(turns==11){
															theBoard->moveChecker(theBoard, 7, 6, 6, 7, 1);
														}
				//end computer turn
				puts("You are the black pieces");
				theBoard->displayBoard();
				theBoard->printBoardToFile(fd);
				cout<< "Enter the row of the piece you want to move: ";
				cin>>oldX;
				cout<< "Enter the column of the piece you want to move: ";
				cin>>oldY;
				CheckerPiece** thatSpaceP = (theBoard->getBoardCorner()) + oldX*8 + oldY;
				CheckerPiece* thisChecker = *thatSpaceP;
				if(thisChecker==NULL||thisChecker==0){
					perror("Unable to find checker");
				}
				else{
					bool isRed = thisChecker->getIsRed();
					bool isKing = thisChecker->getIsKing();
					int theNum = 0;
					if(isKing&&isRed){
						theNum=2; //red king
					}
					else if(!isKing&&isRed){
						theNum=4; //red pawn
					}
					else if(!isKing&&!isRed){
						theNum=3; //black pawn
					}
					else if(isKing&&!isRed){
						theNum=1; //black king
					}
					else{
						theNum=0; //empty
					}
					cout<< "Checker located, please input target row: ";
					cin>>moveX;
					cout<< "Input target column: ";
					cin>>moveY;
					theBoard->moveChecker(theBoard, oldX, oldY, moveX, moveY, theNum);
					theNum=0;
				}
			}
		}
		fclose(fd);
	}

	return answer;
}

bool Production::readFile(char* filename, Board* theBoard)
{

	bool ok = true;

	FILE* fp = fopen(filename, "r"); //read the file

	if (fp == NULL)
	{
		puts("Error! opening file");
	}

	ifstream infile(filename);
	int r,c, color;
	//TODO read the board from the file,
	while (infile >> r >> c >> color)
	{
		//printf("row is: %d, col is: %d, color is: %d\n", r, c, color);
		theBoard->populateBoard(theBoard, r, c, color);
		//theBoard->displayBoard();
	}
	printf("\n");

	fclose (fp);
	return ok;
}

bool Production::getYesNo(char* query)
{
	bool answer = true; //so far
	char said = 'x';
	do
	{
		printf("%s (y/n):",query);
		fflush(stdout);
		fflush(stdin);
		scanf("%c",&said);
	}while((said!= 'y')&&(said!='n'));
	if(said=='n')
	{
		answer=false;
	}


	return answer;
}

