/** \file A01234567_cards2Functions.cpp
  \brief Contains various functions used by the program to do tasks.

  Original Author: Carl Gregory

  Date: 05/06/12 13:24
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
#include <iomanip>
#include <string>
#include <cstdlib>   // rand and srand
#include <ctime>     // For the time function

#include "A01234567_cards2.h"

using namespace std;

/**

  Seeds the random number generator.

  Original Author: Carl Gregory

  Date: 21/05/12 14:07

*/

void setupRand()
{
    // Set up pseusorandom numbers

    // Get the system time.
    unsigned seed = time(0);

    // Seed the random number generator with unsidned system time
    srand(seed);

} //

/**

  I really don't think "refresh" is a good name for what amounts to a constructor
  function.

  Original Author: Carl Gregory

  Date: 25/04/12 13:48

  Modified by: Preston Maness

  Date: 09/06/12

  \pre The array of Card structs is filled with uninitialized structs

  \post Each struct is initialized with appropriate values

  \param[in] cardSet Array of Card structs. Array forms basis for a deck. Each
  player has a full "deck" of 52 struct cards, but only certain cards are revealed.
  \param[in] inSet A boolean value that basically states whether or not the given
  array of structs is the shoe (true if the array is the shoe). A player's hand,
  or the table's pot/trash, instead sets inSet to false.

*/

void refresh(Card cardSet[], bool inSet)
{

	//call initialize... separately? Why?
	/*
	 *
	 * for ( int i = 0 ; i < NUM_SUITS ; i++)
	 * {
	 * 		for ( int j = 0 ; j < NUM_CARDS ; j++)
	 * 		{
	 * 			cardSet[i] = initialize(j+(i*NUM_CARDS),i,j,inSet);
	 * 		}
	 * }
	 *
	 */

 	 // just assign each element its own index
 	/*
	for (int i = 0 ; i < suits ; i++)
 	 {
 		 for (int j = 0 ; j < cards ; j++)
 		 {
 			 cardDeck[i][j] = j;
 		 }
	 }
 	 */
} // void freshDeck( )

/**

  This function takes an array of Card structs and then proceeds to
  call another function to actually do the job...? Lolwut?
  I can understand wanting the freedom to pass either the whole deck
  or a card. So why not just take advantage of polymorphism here?

  Original Author: Carl Gregory

  Date: 25/04/12 13:48

  Modified by: Preston Maness

  Date: 09/06/12

  \param[in] cardSet Array of Card structs. Array forms basis for a deck. Each
  player has a full "deck" of 52 struct cards, but only certain cards are revealed.
  \param[in] debugging A flag that, when set to true, will print out helpful debugging
  information.

*/

void display(Card cardSet[], bool debugging)
{

	/*
	 *
	 * for ( int i = 0 ; i < DECK_SIZE ; i++)
	 * {
	 * 		displayCard(cardSet[i],debugging);
	 * }
	 *
	 */

	/*
	for (int i = 0 ; i < suits ; i++)
	{
		for (int j = 0 ; j < cards ; j++)
		{
			displayCard(cardDeck,i,j);
			cout << ", ";
		}
		cout << "\n";
	}
	*/

} // void displayDeck( )

/**

  Randomly swaps card values in the array of Card structs.
  Uses the Knuth Shuffle algorithm to do so.

  \pre The deck is initialized and the cards are in any particular order.
  Typically this function is called from main right after creating a deck,
  as the created deck is in order and needs to be shuffled.

  \post The deck is shuffled.

  Original Author: Carl Gregory

  Date: 25/04/12 13:48

  \verbatim
  Algorithm:

  Uses the Knuth Shuffle to randomize the elements of the array.

  Taken right from wikipedia:

  To shuffle an array a of n elements (indices 0..n-1):
  for i from n − 1 downto 1 do
       j ← random integer with 0 ≤ j ≤ i
       exchange a[j] and a[i]

  \endverbatim

  \link http://en.wikipedia.org/wiki/Fisher-Yates_shuffle#The_modern_algorithm

  Sidenote: In what universe is that kind of pseudocode "universal?"
  I haven't the foggiest idea what's going on up there.

  \param[in] cardSet Array of Card structs. Array forms basis for a deck. Each
  player has a full "deck" of 52 struct cards, but only certain cards are revealed.

*/

void shuffle(Card cardSet[])
{

	/* Yeah... we're just going to do away with the old algorithm.
	 * Use the Knuth shuffle.
	 *
	 * for ( int i = DECK_SIZE ; i < 0 ; i--)
	 * {
	 * 		j = rand() % i;
	 * 		Card temp = cardSet[i];
	 * 		cardSet[i] = cardSet[j];
	 * 		cardSet[j] = temp;
	 * }
	 *
	 */

} // void shuffleDeck( )

/**
 *
 * Displays a card in the deck. Takes the position in the array
 * (determined by the suit and card integers passed), and displays
 * the appropriate card. The Ace and 2-9 cases are simpler and
 * require fewer switches. 10-K require nested switches.
 *
 * @param cardDeck 2D array that holds the cards
 * @param suit Specifies the suit, 0-3
 * @param card Specifies the card, 0-12
 */

void displayCard(int cardDeck[][NUM_SUIT_CARDS] , int suit, int card)
{

	if( cardDeck[suit][card] == 0) /* Ace */
	{
		cout << "A";
		switch(suit)
		{
			case 0: /* spades */
				cout << "S";
				break;
			case 1: /* hearts */
				cout << "H";
				break;
			case 2: /* diamonds */
				cout << "D";
				break;
			case 3: /* clubs */
				cout << "C";
				break;
			default: /* what did you do? */
				cout << "?";
				break;

		}
	}

	if( cardDeck[suit][card] >= 1 && cardDeck[suit][card] <=8) /* 2-9 */
	{
		cout << (cardDeck[suit][card] + 1); /* Without plus one you're just printing the index */
		switch(suit)
		{
			case 0: /* spades */
				cout << "S";
				break;
			case 1: /* hearts */
				cout << "H";
				break;
			case 2: /* diamonds */
				cout << "D";
				break;
			case 3: /* clubs */
				cout << "C";
				break;
			default: /* what did you do? */
				cout << "?";
				break;

		}
	}

	if( cardDeck[suit][card] >=9) /* 10-K */
	{
		switch(suit)
		{
			case 0: /* spades */
				switch(cardDeck[suit][card])
				{
					case 9: /* 10 */
						cout << "10";
						break;
					case 10: /* Jack */
						cout << "J";
						break;
					case 11: /* Queen */
						cout << "Q";
						break;
					case 12: /* King */
						cout << "K";
						break;
					default: /* what did you do? */
						cout << "?";
						break;
				}
				cout << "S";
				break; /* end spades */

			case 1: /* hearts */
				switch(cardDeck[suit][card])
				{
					case 9: /* 10 */
						cout << "10";
						break;
					case 10: /* Jack */
						cout << "J";
						break;
					case 11: /* Queen */
						cout << "Q";
						break;
					case 12: /* King */
						cout << "K";
						break;
					default: /* what did you do? */
						cout << "?";
						break;
				}
				cout << "H";
				break; /* end hearts */

			case 2: /* diamonds */
				switch(cardDeck[suit][card])
				{
					case 9: /* 10 */
						cout << "10";
						break;
					case 10: /* Jack */
						cout << "J";
						break;
					case 11: /* Queen */
						cout << "Q";
						break;
					case 12: /* King */
						cout << "K";
						break;
					default: /* what did you do? */
						cout << "?";
						break;
				}
				cout << "D";
				break; /* End Diamonds */

			case 3: /* clubs */
				switch(cardDeck[suit][card])
				{
					case 9: /* 10 */
						cout << "10";
						break;
					case 10: /* Jack */
						cout << "J";
						break;
					case 11: /* Queen */
						cout << "Q";
						break;
					case 12: /* King */
						cout << "K";
						break;
					default: /* what did you do? */
						cout << "?";
						break;
				}
				cout << "C";
				break; /* End Clubs */

			default: /* what did you do? */
				cout << "?";
				break;

		} /* end suit switch */

	} /* end if 10-K */

}



