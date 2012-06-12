#ifndef CARDS2
#define CARDS2

/**\file A01234567_cards2.h
 * \brief Header that defines the functions found in A01234567_cards1Functions.cpp
\verbatim
  First stage of Card project for CS2308-501 Summer 2012
	- Simulates dealing a deck of cards to four players;
	- Uses four integer parallel arrays of "suits":
		   represented by integers and must be displayed via switch statement
	- Uses random numbers
		   (Gaddis ed. 7, pp. 129-130, example program 3-25)
\endverbatim

  Original Author: Carl Gregory

  Date: 21/05/12 15:24

  Modified by: Preston Maness

  Date: 08/06/12 17:38

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

#include <string>

using namespace std;

struct Card{

	/* Sensible naming scheme

	int suit;
	int value;
	string valueSymbol;
	char suitSymbol;
	bool held;
	bool visible;
	int initIndex;

	*/

	/* Required naming scheme */

	int suit;
	int faceValue;
	string vSymbol;
	char sSymbol;
	bool isHeld;
	bool isVisible;
	int initIndex;

};

const int NUM_SUITS = 4;
const int NUM_SUIT_CARDS = 13;
const int DECK_SIZE = NUM_SUITS * NUM_SUIT_CARDS;

const int SPADE = 0;
const int HEART = 1;
const int DIAMOND = 2;
const int CLUB = 3;

/* These arrays would probably be better implemented as maps */

const string valueSymbol[NUM_SUIT_CARDS] = {
		"A","2","3","4","5","6","7","8","9","10","J","Q","K"
};
const char suitSymbol[NUM_SUITS] = {
		'S','H','D','C'
};

void setupRand();
void refresh(int [][NUM_SUIT_CARDS] , int ,  int );
void displayDeck(int [][NUM_SUIT_CARDS] , int ,  int );
void shuffleDeck(int [][NUM_SUIT_CARDS] , int ,  int );
void displayCard(int [][NUM_SUIT_CARDS] , int , int );

#endif
