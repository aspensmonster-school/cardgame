/*
 * A01234567_AcesUp.cpp
 *
 *  Created on: Jul 5, 2012
 *      Author: preston
 */

#include "A01234567_AcesUp.h"
#include <iostream>

AcesUp::AcesUp()
{

	/*
	 * Fill the vector of vectors with six vectors. One for the deck, four
	 * for the stacks of cards, and one for trash.
	 *
	 */

	stax.resize(6);

	/*
	 * Initialize the deck.
	 */

	for (int i = 0 ; i < NUM_SUITS ; i++)
	{
		for (int j = 0 ; j < NUM_SUIT_CARDS ; j++)
		{
			Card temp((i*NUM_SUIT_CARDS + j),i,j,true);
			stax[0].push_back(temp);
		}
	}

	/*
	 * Shuffle the deck using Knuth shuffle
	 */

	for ( int i = 0 ; i < 3 ; i++)
	{

		for ( int j = DECK_SIZE - 1 ; j > 0 ; j--)
		{
			int k = rand() % j;
			Card temp = stax[0][j];
			stax[0][j] = stax[0][k];
			stax[0][k] = temp;
		}

	}

}

AcesUp::~AcesUp()
{



}

