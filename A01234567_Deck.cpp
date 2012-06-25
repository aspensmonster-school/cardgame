/**\file A01234567_Card.cpp
 * \brief Contains the methods that describe a Deck (container) object.
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

#include <iostream>
#include "A01234567_Deck.h"

Deck::Deck() {
}

Deck::~Deck() {
}

/**

  Essentially re-constructs the array of Card objects in cardSet[].

  \pre The array of Card objects is filled with uninitialized objects,
  or else needs to be "reset" to its initial, ordered state.

  \post Each object is initialized with appropriate values. And "reset" to
  an initial, ordered state.

  \param[in] inSet A boolean value that determines the value of isHeld for the Card object.

*/

void Deck::refresh(bool inSet)
{

	for ( int i = 0 ; i < NUM_SUITS ; i++)
	{
		for ( int j = 0 ; j < NUM_SUIT_CARDS ; j++)
		{
			cardSet[j+(i*NUM_SUIT_CARDS)].initialize(j+(i*NUM_SUIT_CARDS),i,j,inSet);
		}
	}

} // void fresh( )

/**

  This function performs bounds checking, and then hands the actual displaying off
  to Deck::displayCard(), which then performs the necessary debugging parameter passing
  and calls Card::display to actually output the card values and symbols.

  This function will output newlines every 13 interations of the loop that calls
  Deck::displayCard().

  \param[in] numCards specifies number of cards to display from the cardSet[] array
  of Card objects. Bounds checking ensure this will be between 0 and \c DECK_SIZE .

*/

void Deck::display(int numCards)
{

	if (numCards > DECK_SIZE)
	{
		numCards = DECK_SIZE;
	}
	else
	if (numCards < 0)
	{
		numCards = 0;
	}

	for(int i = 0 ; i < numCards ; i++)
	{

		displayCard(i);

		if( (i+1) % NUM_SUIT_CARDS == 0 )
        {
                cout << endl;
        }

	}


} // void display( )

/**
 *
 * This function is typically called from Deck::display(). It will display
 * a specific Card object. This Card object will essentially inherit the
 * debugging properties of the Deck object for the duration of display, and
 * then have its debugging properties reset once displayed. This permits us
 * to pass a debugging parameter to Deck objects only, and not work about
 * dipping our hand into the Card objects too much.
 *
 * This passing is typically performed in the test suite: i.e.,
 * " Deck::cardSet.setDebugFlag(true/false) "
 * So that when we then say
 * " Deck::cardSet.display(DECK_SIZE) "
 * and display then calls this function (Deck::displayCard), the line
 * " cardSet[index].setDebugFlag(debugging) "
 * works as intended.
 *
 * \param index specifies the index of the cardSet[] array. cardSet[index]
 * is the card to be displayed.
 */

void Deck::displayCard(int index)
{
	bool temp = cardSet[index].getDebugFlag();
	cardSet[index].setDebugFlag(debugging);
	cardSet[index].display();
	cardSet[index].setDebugFlag(temp);
}

/**

  Randomly swaps card values in the array of Card objects.
  Uses the Knuth Shuffle algorithm to do so. Performs the Knuth
  shuffle \c numSwaps times.

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

  \param[in] numSwaps Array of Card objects. Array forms basis for a deck. Each
  player has a full "deck" of 52 card objects, but only certain cards are revealed.

*/

void Deck::shuffle(int numSwaps)
{

	/* Knuth Shuffle, performed 'numSwaps' times */

	for ( int i = 0 ; i < numSwaps ; i++)
	{

		for ( int j = DECK_SIZE - 1 ; j > 0 ; j--)
		{
			int k = rand() % j;
			Card temp = cardSet[j];
			cardSet[j] = cardSet[k];
			cardSet[k] = temp;

		}

	}

} // void shuffle( )

void Deck::revealAll()
{

	for ( int i = 0 ; i < DECK_SIZE ; i++)
	{
		revealCard(i);
	}

}

void Deck::hideAll()
{

	for ( int i = 0 ; i < DECK_SIZE ; i++)
	{
		hideCard(i);
	}

}

/**
 *
 * This function will "deal" the first <tt> numCards </tt>
 * from the start of <tt> cardSet[] </tt> .
 *
 * \warning Does not update state of other cardSet arrays or reset
 * the changes made. "Dealing" assumes
 * that we are working with the deck. Nothing in the spec provides
 * any manner of distinguishing between different "Deck" objects (really just Container
 * objects). So we can have players and the pot/trash "dealing."
 * Not to mention, naming the container class one of the things to
 * be contained is... a questionable practice at best.
 *
 * \pre \c the cardSet[] array's first \c numCards members have
 * their \c isHeld and \c isVisible set to some value.
 * \post \c the cardSet[] array's first \c numCards members have
 * \c isHeld set to \c false and \c isVisible set to \c true.
 *
 * \param[in] numCards Specifies the number of cards to take off the top
 * of the \c cardSet[] array.
 * \param[in] faceUp Ultimately sets the value of isVisible for the card
 * being dealt.
 *
 */

void Deck::deal(int numCards, bool faceUp)
{

	for ( int i = 0 ; i < numCards ; i++)
	{
		cout << cardSet[i].getFaceSymbol() << cardSet[i].getSuitSymbol() << ",";

		if( (i+1) % NUM_SUIT_CARDS == 0 && numCards != 13)
		{
			cout << endl;
		}

		putCard(i,debugging);
	}

	cout << endl;

}

/**
 *
 * Simulates taking a card from another deck (though the spec says nothing about
 * how to perform such a process). The function calls the Card object's member function
 * \c pickUp() , which sets \c isHeld for the Card object to true and \c isVisible to
 * \c up.
 *
 * \warning Does not update state of other cardSet arrays ("Deck" container objects).
 * For example, you can "take" a card from one "deck," (container) but presumably
 * you're wanting to give it to another "deck" (another container).
 *
 * \warning If the cardSet[] (from Deck object) has been shuffled, <tt> card </tt>
 * will be meaningless. You'd have to search the shuffled cardSet array for the
 * relevant initIndex value and THEN pass the index that has that initValue to this function.
 *
 * \param[in] card index for a card in the cardSet array.
 * \param[in] up
 */

void Deck::takeCard(int card, bool up)
{
	cardSet[card].pickUp(up);
}

/**
 *
 * Simulates putting onto another deck (though the spec says nothing about
 * how to perform such a process). The function calls the Card object's member function
 * \c play() , which sets \c isHeld for the Card object to false and \c isVisible to
 * \c up.
 *
 * \warning Does not update state of other cardSet arrays ("Deck" container objects).
 * For example, you can "take" a card from one "deck," (container) but presumably
 * you're wanting to give it to another "deck" (another container).
 *
 * \warning If the cardSet[] (from Deck object) has been shuffled, <tt> card </tt>
 * will be meaningless. You'd have to search the shuffled cardSet array for the
 * relevant initIndex value and THEN pass the index that has that initValue to this function.
 *
 * \param[in] card index for a card in the cardSet array.
 * \param[in] up specifies value of isVisible for cardSet[card]
 */

void Deck::putCard(int card, bool up)
{

	cardSet[card].play(up);
}
