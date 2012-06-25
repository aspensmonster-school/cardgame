#ifndef CARDS3FUNCTIONS_H_
#define CARDS3FUNCTIONS_H_

/**\file A01234567_cards3.h
 * \brief Header that defines the functions found in A01234567_cards3Utils.cpp. Mostly
 * left overs from the refactoring. Basically just holds constants.
 *
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

#include <string>

using namespace std;

const int NUM_SUITS = 4;
const int NUM_SUIT_CARDS = 13;
const int DECK_SIZE = NUM_SUITS * NUM_SUIT_CARDS;

const int SPADE = 0;
const int HEART = 1;
const int DIAMOND = 2;
const int CLUB = 3;

/* These arrays would probably be better implemented as maps */

const string valueTable[NUM_SUIT_CARDS] = {
		"A","2","3","4","5","6","7","8","9","10","J","Q","K"
};
const char suitTable[NUM_SUITS] = {
		'S','H','D','C'
};

void setupRand();

#endif
