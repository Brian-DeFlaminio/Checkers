/*
 * CheckerPiece.h
 *
 *  Created on: Sep 25, 2021
 *      Author: bdefl
 */

#ifndef CHECKERPIECE_H_
#define CHECKERPIECE_H_


class CheckerPiece{
public:
	CheckerPiece();
	virtual ~CheckerPiece();

	void setIsRed(bool isRed);
	bool getIsRed();
	void setIsKing(bool isKing);
	bool getIsKing();
	void setxCoord(int xCoord);
	int getxCoord();
	void setyCoord(int yCoord);
	int getyCoord();

private:
		int xCoord{};
		int yCoord{};
		bool isKing{};
		bool isRed{};
};

#endif /* CHECKERPIECE_H_ */
