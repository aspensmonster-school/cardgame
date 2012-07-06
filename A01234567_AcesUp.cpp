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

	/* temporary for testing ; simulating game functions here for now to make sure display works correctly*/

	/* add back of deck to stack one */
	stax[1].push_back(stax[0].back());

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

	/* add back of deck to stack one */
	stax[1].push_back(stax[0].back());

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

	/* Move stuff to trash */

	stax[5].push_back(stax[0].back());
	stax[0].pop_back();

	stax[5].push_back(stax[0].back());
	stax[0].pop_back();

	stax[5].push_back(stax[0].back());
	stax[0].pop_back();

	stax[5].push_back(stax[0].back());
	stax[0].pop_back();

	stax[5].push_back(stax[0].back());
	stax[0].pop_back();

	stax[5].push_back(stax[0].back());
	stax[0].pop_back();

	stax[5].push_back(stax[0].back());
	stax[0].pop_back();

	stax[5].push_back(stax[0].back());
	stax[0].pop_back();

	stax[5].push_back(stax[0].back());
	stax[0].pop_back();

	stax[5].push_back(stax[0].back());
	stax[0].pop_back();

	stax[5].push_back(stax[0].back());
	stax[0].pop_back();

	stax[5].push_back(stax[0].back());
	stax[0].pop_back();

	stax[5].push_back(stax[0].back());
	stax[0].pop_back();

	stax[5].push_back(stax[0].back());
	stax[0].pop_back();

	stax[5].push_back(stax[0].back());
	stax[0].pop_back();

	stax[5].push_back(stax[0].back());
	stax[0].pop_back();

}

AcesUp::~AcesUp()
{



}

/* The rendered basically processes output line by line. It analyzes the current state of the
 * stax variable and outputs the state given by that analysis (which cards in which stacks, etc).
 * Since we render based on the state of the stax variable, the rendering is independent of any particular
 * user command. */

void AcesUp::render()
{

	bool finished = false;
	int layer = 0; /* Tracks which "layer" of cards is being displayed */
	int trash = stax[5].size();

	system("clear");

	cout << "1: " << "\t" << "2: " << "\t" << "3: " << "\t" << "4: " << "\t" << "Trash: " << endl << endl;

	while( !finished )
	{

		int count = 0; /* Tracks number of stacks completely displayed */

		/* Display card stacks */

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

		/* Display garbage off to the right */

		int i = trash - 1; /* since trash is based off of the vector::size() function,
		 	 	 	 	 	  we want to ensure we call the right index */

		int j = trash -12; /* We also only want to display 12 cards on any given row of
						      screen output */

		for( ; i > j && trash !=0 ; i--)
		{
			cout << stax[5][i].getFaceSymbol() << stax[5][i].getSuitSymbol() << ",";
			trash--;
		}

		layer++;

		if(count == 4 && trash == 0) /* we have iterated through all cards in each play stack. Stop display loop. */
		{
			finished = true;
		}

		cout << endl;
	}

}


