/*
 * CardClass.h
 *
 *  Created on: Jun 23, 2012
 *      Author: preston
 */

#ifndef CARD_H_
#define CARD_H_

#include "A01234567_cards3Utils.h"

class Card

{

private:

	int suitValue;
	char suitSymbol;
	int faceValue;
	string faceSymbol;
	bool isHeld;
	bool isVisible;
	bool debugging;
	int initIndex;

public:

	Card();
	Card(int, int, int, bool);
	~Card();

	int getSuitValue() const { return suitValue; }
	char getSuitSymbol() const { return suitSymbol; }
	int getFaceValue() const { return faceValue; }
	string getFaceSymbol() const { return faceSymbol; }
	bool getDebugFlag() const { return debugging; }

	/* Some of these functions act as setters */
	void initialize(int, int, int, bool isHere = true);
	void pickUp(bool showing = false);
	void play(bool showing = false);
	void show() { isVisible = true; }
	void hide() { isVisible = false; }
	void display();
	void setDebug(bool flag) {debugging = flag;}

};

#endif /* CARD_H_ */
