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

	/* temporary for testing ; simulating dealing function here for now */

	/* add back of deck to stack one */
	stax[1].push_back(stax[0].back());

	cout << stax[1].size();

	/* Remove back card of deck */
	stax[0].pop_back();


	/* add back of deck to stack one */
	stax[2].push_back(stax[0].back());

	/* Remove back card of deck */
	stax[0].pop_back();

	/* add back of deck to stack one */
	stax[3].push_back(stax[0].back());

	/* Remove back card of deck */
	stax[0].pop_back();

	/* add back of deck to stack one */
	stax[4].push_back(stax[0].back());

	/* Remove back card of deck */
	stax[0].pop_back();

}

AcesUp::~AcesUp()
{



}

void AcesUp::display()
{

	bool finished = false;
	int count = 0; /* Tracks number of stacks completely displayed */
	int layer = 0; /* Tracks which "layer" of cards is being displayed */

	system("clear");

	while( !finished )
	{


		for (int i = 1 ; i < 5 ;i++)
		{
			if( stax[i].size() > layer )
			{
				cout << stax[i][layer].getFaceSymbol() << stax[i][layer].getSuitSymbol() << "\t";
			}
			else
			{
				cout << "\t";
				count++;
			}
		}

		layer++;

		if(count == 4) /* we have iterated through all cards in each play stack. Stop display loop. */
		{
			finished = true;
		}

		cout << endl;
	}

}


