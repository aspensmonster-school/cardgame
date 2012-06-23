/*
 * A01234567_Card.cpp
 *
 *  Created on: Jun 23, 2012
 *      Author: preston
 */

#include "A01234567_Card.h"

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
