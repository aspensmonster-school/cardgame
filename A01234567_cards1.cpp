/*
  Name: cards1.cpp
  Author: Carl Gregory
  Date: 19/05/12 19:46
  Description:
        simulates dealing a deck of cards to four players;
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
