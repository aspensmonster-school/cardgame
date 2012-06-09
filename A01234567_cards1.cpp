/*
  Name: cards1.cpp
  Author: Carl Gregory
  Date: 19/05/12 19:46
  Modified by: Preston Maness
  Date: 08/06/12 17:38
  Description:
        simulates dealing a deck of cards to four players;
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

#include <iostream>
#include <string>
#include <cstdlib> /* You need this lib in order to use the EXIT_SUCCESS macro */

#include "A01234567_cards1.h"

using namespace std;

int main(int argc, char *argv[])
{
    int Spades[NUM_SUIT_CARDS];
    int Hearts[NUM_SUIT_CARDS];
    int Diamonds[NUM_SUIT_CARDS];
    int Clubs[NUM_SUIT_CARDS];

    setupRand();
    cout << "\nA new deck:" << endl;
    freshDeck(Spades, Hearts, Diamonds, Clubs, NUM_SUIT_CARDS);
    displayDeck(Spades, Hearts, Diamonds, Clubs, NUM_SUIT_CARDS);
    
    cout << "\nand a shuffled deck:" << endl;
    shuffleDeck(Spades, Hearts, Diamonds, Clubs, NUM_SUIT_CARDS);
    displayDeck(Spades, Hearts, Diamonds, Clubs, NUM_SUIT_CARDS);

	cout << "Press ENTER to Continue." << endl;
	cin.get();
    return EXIT_SUCCESS;
}
