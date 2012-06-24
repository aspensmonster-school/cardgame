/*
 * A01234567_Card.cpp
 *
 *  Created on: Jun 23, 2012
 *      Author: preston
 */

#include "A01234567_Card.h"
#include <iostream>

Card::Card()
{

}

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
 * \param[in] cardSet Array of Card objects. Array forms basis for a deck. Each
 * player has a full "deck" of 52 card objects, but only certain cards are revealed.
 * \param[in] thisCard specifies the index of the card to be picked up. When
 * initialized, each card is "in order" in the deck. If shuffled, thisCard must be
 * the index of the card with the desired initIndex (you have to search the array
 * to get that)
 *
 * \return The card located at cardSet[thisCard].
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
 * \param[in] cardSet Array of Card objects. Array forms basis for a deck. Each
 * player has a full "deck" of 52 card objects, but only certain cards are revealed.
 * \param[in] thisCard specifies the index of the card to be picked up. When
 * initialized, each card is "in order" in the deck. If shuffled, thisCard must be
 * the index of the card with the desired initIndex (you have to search the array
 * to get that)
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

void Card::display()
{

	if ( debugging == true)
	{
		cout << faceSymbol << suitSymbol << ",";
	}
	else
	if ( /*isHeld == true && */ isVisible == true )
	{
		cout << faceSymbol << suitSymbol << ",";
	}
	else
	{
		return;
	}

}
