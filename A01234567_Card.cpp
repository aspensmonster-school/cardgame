/**\file A01234567_Card.cpp
 * \brief Contains the methods that describe a Card object.
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

#include "A01234567_Card.h"
#include <iostream>

Card::Card()
{

}

/**
 *
 * This is the construct for the card object. It calls initialize,
 * which does the actual constructing for now. Right now, the
 * constructor is not being used directly. Instead, the Deck object
 * is calling initialize for each Card object in cardSet.
 *
 * \param[in] thisIndex specifies the initial index of the card being
 * inserted.
 * \param[in] thisSuit Specifies the suit, 0-3.
 * \param[in] thisValue Specifies the value, A-K.
 * \param[in] isHere Determines the value of \c isHeld .
 */

Card::Card(int thisIndex, int thisSuit, int thisValue, bool isHere)
{
	initialize(thisIndex,thisSuit,thisValue,isHere);
}

Card::~Card() {
}

/**
 *
 * This function serves as the functional constructor for the Card class.
 * Card(int,int,int,bool) just calls this function and sets the parameters
 * appropriately.
 *
 * \warning The spec requires isVisible to be true for all Card objects.
 * This is not an accurate depiction of different types of collections of Cards.
 *
 * \pre memory has been allocated for an array of Card objects,
 * and they have been default initialized, but not properly initialized.
 * \post the Card object is fully initialized.
 *
 * \param thisIndex marks the cards original location in the array. This
 * initial location can also serve as a unique identifier, assuming that
 * all arrays of Card objects are initialized in the same manner (they are).
 * \param thisSuit specifies the suit of the Card to be returned...
 * \param thisValue ...and its value.
 * \param isHere a flag that specifies whether the deck being filled is the
 * shoe, a players hand, or the trash/pot.
 *
 */

void Card::initialize(int thisIndex, int thisSuit, int thisValue, bool isHere)
{

	suitValue = thisSuit;
	suitSymbol = suitTable[thisSuit];
	faceValue = thisValue;
	faceSymbol = valueTable[thisValue];
	isHeld = isHere;
	isVisible = true;
	initIndex = thisIndex;

}

/**
 *
 * This function carries out the act of picking up a card,
 * either from the deck/shoe or the pot/trash. Presumably, a player
 * will select a card from either of those decks.
 *
 * \pre \c isHeld is false. It wouldn't make sense to "pickUp" a
 * card you already have.
 * \post \c isHeld is true, since you've picked it up. \c isVisible
 * is determined by \c faceUp .
 *
 * \param[in] faceUp specifies whether the used-up card is visible or not. Presumably
 * it would be "visible" if going to a pot and perhaps "not visible" if going to
 * a trash pile.
 *
 */

void Card::pickUp(bool faceUp)
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

	isHeld = true;
	isVisible = faceUp;

}

/**
 *
 * This function attempts to mimic the concept of "playing"
 * a card onto the table. If a card is played it is no longer
 * "held" so \c isHeld is set to false.
 *
 * \pre \c isHeld is true, as it is being held by another player or
 * some other Deck object.
 * \post \c isHeld is set to false and \c isVisible
 * is determined by \c faceUp .
 *
 * \param[in] faceUp specifies whether the used-up card is visible or not. Presumably
 * it would be "visible" if going to a pot and perhaps "not visible" if going to
 * a trash pile.
 *
 */

void Card::play(bool faceUp)
{

	/* Same pass by reference issue here as in
	 * pickUp.
	 */

	isHeld = false;
	isVisible = faceUp;

}

/**
 *
 * This is the function that performs the display of any given card.
 * A typical call-chain is:
 *
 * deckObject.display(int) -> deckObject.displayCard(int) -> cardOjbect.display()
 *
 * The indentical names for different objects can lead to confusion
 * if you're not careful with context.
 *
 * \warning Previous versions of the spec dictated both that isHeld AND isVisible
 * needed to be true, and also that only isVisible needed to be true, in order for
 * Card::display() to cout the relevant symbols. For this assignment, I am leaving
 * it as requiring both. I'm assuming that, at some point, we'll either flesh out
 * the Deck object to be a proper container, or else use an STL container and at that
 * point we can worry about updating state.
 *
 * \warning The current \c sampleOutput.txt on TRACS presents the exact same output
 * behaviour for each Deck object called. This behaviour indicates that only
 * isVisible need be true (since we "refresh" and "reveal" prior to most actions in the
 * test suite). However, requiring both to be true is closer to, though not exactly, the
 * expected state-dependent output. Indeed it makes no sense for all cards everywhere
 * to be visible, much less for a card to be visible but not held.
 *
 */

void Card::display()
{

	if ( debugging == true)
	{
		cout << faceSymbol << suitSymbol << ",";
	}
	else
	if ( isHeld == true && isVisible == true ) /* Depending on the version of spec, this can be different. */
	{
		cout << faceSymbol << suitSymbol << ",";
	}
	else
	{
		return;
	}

}
