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

    // Seed the random number generator with unsigned system time
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

	for ( int i = 0 ; i < NUM_SUITS ; i++)
	{
		for ( int j = 0 ; j < NUM_SUIT_CARDS ; j++)
		{
			cardSet[i] = initialize(j+(i*NUM_SUIT_CARDS),i,j,inSet);
		}
	}

} // void fresh( )

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

	for ( int i = 0 ; i < DECK_SIZE ; i++)
	{
		displayCard(cardSet[i],debugging);
	}

} // void display( )

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

  \param[in] cardSet Array of Card structs. Array forms basis for a deck. Each
  player has a full "deck" of 52 struct cards, but only certain cards are revealed.

*/

void shuffle(Card cardSet[])
{

	/* Knuth Shuffle */

	for ( int i = DECK_SIZE ; i > 0 ; i--)
	{
		int j = rand() % i;
		Card temp = cardSet[i];
		cardSet[i] = cardSet[j];
		cardSet[j] = temp;
	}

} // void shuffle( )

/**
 *
 * Displays a card in the deck. Depending on the debugging
 * flag and the flags in the struct (isHeld, isVisible).
 *
 * \param card a single Card struct.
 * \param debugging a flag that specifies whether or not to
 * spit out the entire array.
 */

void displayCard(Card card, bool debugging)
{

	if ( debugging == true)
	{
		cout << card.vSymbol << card.sSymbol;
	}
	else
	if ( card.isHeld == true && card.isVisible == true )
	{
		cout << card.vSymbol << card.sSymbol;
	}
	else
	{
		return;
	}

}

Card initialize(int thisIndex, int thisSuit, int thisValue, bool isHere)
{

	Card thisCard;

	thisCard.suit = thisSuit;
	thisCard.faceValue = thisValue;

	thisCard.sSymbol = suitSymbol[thisSuit];
	thisCard.vSymbol = valueSymbol[thisValue];

	thisCard.isHeld = isHere;
	thisCard.isVisible = true;

	thisCard.initIndex = thisIndex;

	return thisCard;

}

/**
 *
 * \warn Does not update state of other arrays or reset
 * the changes made to the passed array.
 *
 */

Card pickUp(Card cardSet [ ] , int thisCard )
{

	/* Arrays are passed by reference. Why are we
	 * "returning" the card? The test suit will pick
	 * up 10 random cards, but doesn't put them back.
	 * The spec doesn't say anything about updating the
	 * state of the other decks. I.e., you can "pick up"
	 * the ace of spades in the player's hand but the
	 * deck will still have the ace of spades according
	 * to the spec.
	 */

	cardSet[thisCard].isHeld = true;
	cardSet[thisCard].isVisible = true;
	return cardSet[thisCard];

}

/**
 *
 * \warn Does not update state of other arrays.
 * Sets isVisible incorrectly. If you "play" a card,
 * it is no longer in your hand. isHeld is obviously
 * false, but isVisible should also be false for your hand,
 * and either true or false for the "table/pot" array that
 * you should also be updating.
 *
 */

Card play(Card cardSet[], int thisCard, bool faceUp)
{

	/* Same pass by reference issue here as in
	 * pickUp.
	 */

	cardSet[thisCard].isHeld = false;
	cardSet[thisCard].isVisible = faceUp;
	return cardSet[thisCard];

}

void deal(Card cardSet[], int numCards)
{
	for ( int i = 0 ; i < numCards ; i++)
	{
		Card temp = play(cardSet,i);
		cout << temp.vSymbol << temp.sSymbol << ", ";
	}
	cout << endl;
}
