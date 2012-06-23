/*
 * A01234567_Deck.cpp
 *
 *  Created on: Jun 23, 2012
 *      Author: preston
 */

#include "A01234567_Deck.h"

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


