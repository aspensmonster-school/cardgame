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

  I really don't think \c refresh is a good name for what amounts to a constructor
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
			cardSet[j+(i*NUM_SUIT_CARDS)] = initialize(j+(i*NUM_SUIT_CARDS),i,j,inSet);
		}
	}

} // void fresh( )

/**
 * This function is typically called from the \c refresh function.
 * It returns a fully initialized Card struct based on the parameters
 * passed.
 *
 *
 * \pre memory has been allocated for an array of Card structs,
 * but the structs themselves have yet to be initialized.
 * \post the Card struct is initialized and returned, typically
 * to the \c refresh function that assigns it to an index in an array
 * of Card structs.
 *
 * \param thisIndex marks the cards original location in the array. This
 * initial location can also serve as a unique identifier, assuming that
 * all arrays of Card structs are initialized in the same manner (they are).
 * \param thisSuit specifies the suit of the Card to be returned...
 * \param thisValue ...and its value.
 * \param isHere a flag that specifies whether the deck being filled is the
 * shoe, a players hand, or the trash/pot.
 *
 * \return A fully initialized Card struct.
 */

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

  This function takes an array of Card structs and then proceeds to
  call another function to actually do the job...? Lolwut?
  I can understand wanting the freedom to pass either the whole deck
  or a card. So why not just take advantage of polymorphism here?

 * \warning [See displayCard] There are two mutually exclusive requirements
 * in the spec regarding these two methods. The spec states that \c display
 * shall "[pass] on" the \c debugging flag to \c displayCard, implying
 * that actual display is performed from \c displayCard. In the requirements
 * for display, if \c debugging is \c false , then the program shall only
 * display the cards in cardSet whose \c isVisible parameters are set to
 * \c true. HOWEVER, the requirements for \c displayCard state that BOTH
 * \c isVisible AND \c isHeld must be true for a card to be displayed.
 *
 * \warning The sample file appears to operate on the first principle (only
 * \c isVisible needs to be set to \c true in order for display to occur).
 * However, it's still a conflict that has yet to be caught as far as I know.

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

		/* Print out 13 cards per line */
		if( (i+1) % NUM_SUIT_CARDS == 0 )
		{
			cout << endl;
		}
	}

} // void display( )

/**
 *
 * Displays a card in the deck depending on the debugging
 * flag and the flags in the struct (\c isHeld , \c isVisible ).
 * If debugging is true, all cards are shown. Otherwise,
 * a card is only shown if it is both held by the array and
 * marked as visible.
 *
 * \warning [See display] There are two mutually exclusive requirements
 * in the spec regarding these two methods. The spec states that \c display
 * shall "[pass] on" the \c debugging flag to \c displayCard, implying
 * that actual display is performed from \c displayCard. In the requirements
 * for display, if \c debugging is \c false , then the program shall only
 * display the cards in cardSet whose \c isVisible parameters are set to
 * \c true. HOWEVER, the requirements for \c displayCard state that BOTH
 * \c isVisible AND \c isHeld must be true for a card to be displayed.
 *
 * \warning The sample file appears to operate on the first principle (only
 * \c isVisible needs to be set to \c true in order for display to occur).
 * However, it's still a conflict that has yet to be caught as far as I know.
 *
 * \param card a single Card struct.
 * \param debugging a flag that specifies whether or not to
 * spit out the entire array.
 */

void displayCard(Card card, bool debugging)
{

	if ( debugging == true)
	{
		cout << card.vSymbol << card.sSymbol << ",";
	}
	else
	if ( card.isHeld == true && card.isVisible == true )
	{
		cout << card.vSymbol << card.sSymbol << ",";
	}
	else
	{
		return;
	}

}

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

  http://en.wikipedia.org/wiki/Fisher-Yates_shuffle#The_modern_algorithm

  \param[in] cardSet Array of Card structs. Array forms basis for a deck. Each
  player has a full "deck" of 52 struct cards, but only certain cards are revealed.

*/

void shuffle(Card cardSet[])
{

	/* Knuth Shuffle */

	for ( int i = DECK_SIZE - 1 ; i > 0 ; i--)
	{
		int j = rand() % i;
		Card temp = cardSet[i];
		cardSet[i] = cardSet[j];
		cardSet[j] = temp;
	}

} // void shuffle( )

/**
 *
 * This function carries out the act of picking up a card,
 * either from the shoe or the pot/trash. Presumably, a player
 * will select a card from either of those decks; we pass the
 * player's hand to this function, which will then set that
 * particular card to isHeld and isVisible.
 *
 * \warning Does not update state of other arrays or reset
 * the changes made to the passed array.
 *
 * \warning If the cardSet array has been shuffled, <tt>int thisCard</tt>
 * will be meaningless. You'd have to search the shuffled cardSet array for the
 * relevant initIndex value to THEN pass to this function.
 *
 * \pre <tt> cardSet[thisCard] </tt> is in an initialized state.
 * \post  <tt> cardSet[thisCard] </tt> is set to held and visible.
 *
 * \param[in] cardSet Array of Card structs. Array forms basis for a deck. Each
 * player has a full "deck" of 52 struct cards, but only certain cards are revealed.
 * \param[in] thisCard specifies the index of the card to be picked up. When
 * initialized, each card is "in order" in the deck. If shuffled, thisCard must be
 * the index of the card with the desired initIndex (you have to search the array
 * to get that)
 *
 * \return The card located at cardSet[thisCard].
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
 * This function will "deal" the first <tt> numCards </tt>
 * from the start of <tt> cardSet[] </tt> .
 *
 * \warning Does not update state of other arrays or reset
 * the changes made to the passed array.
 *
 * \pre \c the cardSet[] array's first \c numCards members have
 * their \c isHeld and \c isVisible set to some value.
 * \post \c the cardSet[] array's first \c numCards members have
 * \c isHeld set to \c false and \c isVisible set to \c true.
 *
 * \param cardSet
 * \param numCards
 */

void deal(Card cardSet[], int numCards)
{
	for ( int i = 0 ; i < numCards ; i++)
	{
		Card temp = play(cardSet,i);
		cout << temp.vSymbol << temp.sSymbol << ",";

		/* Print out 13 cards per line */
		if( (i+1) % NUM_SUIT_CARDS == 0 && numCards != 13)
		{
			cout << endl;
		}
	}
	cout << endl;
}

/**
 *
 * This function attempts to mimic the concept of "playing"
 * a card onto the table.
 *
 * \warning Does not update state of other arrays.
 * Sets isVisible incorrectly. If you "play" a card,
 * it is no longer in your hand. isHeld is obviously
 * false, but isVisible should also be false for your hand,
 * and either true or false for the "table/pot" array that
 * you should also be updating (but aren't).
 *
 * \warning If the cardSet array has been shuffled, <tt> int thisCard </tt>
 * will be meaningless. You'd have to search the shuffled cardSet array for the
 * relevant initIndex value to THEN pass to this function.
 *
 * \pre \c cardSet[thisCard].isHeld is true, as it is being held by a player or
 * some other deck array.
 * \post \c cardSet[thisCard].isHeld is set to false and \c cardSet[thisCard].isVisible
 * is determined by \c faceUp .
 *
 * \param[in] cardSet Array of Card structs. Array forms basis for a deck. Each
 * player has a full "deck" of 52 struct cards, but only certain cards are revealed.
 * \param[in] thisCard specifies the index of the card to be picked up. When
 * initialized, each card is "in order" in the deck. If shuffled, thisCard must be
 * the index of the card with the desired initIndex (you have to search the array
 * to get that)
 * \param[in] faceUp specifies whether the used-up card is visible or not. Presumably
 * it would be "visible" if going to a pot and perhaps "not visible" if going to
 * a trash pile.
 *
 * \return Returns the altered card.
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
