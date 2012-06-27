/**\file A01234567_Card.h
 * \brief Describes a Card object.
 * \author Preston Maness
 *
 */

/*
    Copyright 2012 Preston Maness.

    This file is part of CardGame.

    CardGame is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    CardGame is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with CardGame.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CARD_H_
#define CARD_H_

#include "A01234567_cards4Utils.h"

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
	int getInitIndex() const { return initIndex; }
	bool getIsHeld() const { return isHeld;}

	/* Some of these functions act as setters */
	void initialize(int, int, int, bool isHere = true);
	void pickUp(bool showing = false);
	void play(bool showing = false);
	void show() { isVisible = true; }
	void hide() { isVisible = false; }
	void display();
	void setDebugFlag(bool flag) {debugging = flag;}

};

#endif /* CARD_H_ */
