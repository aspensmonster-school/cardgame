/*
 * A01234567_AcesUp.cpp
 *
 *  Created on: Jul 5, 2012
 *      Author: preston
 */

#include "A01234567_AcesUp.h"
#include <iostream>
#include <iomanip>

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
	 * Shuffle the deck using Knuth shuffle. Shuffle 3 times.
	 * Every day I'm shufflin...
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

void AcesUp::intro()
{

	system("clear");

	cout << "===============================================================================" << endl;
	cout << endl;
	cout << "Welcome to this CLI version of the Solitaire-based card-game known \n"
			"as Aces Up. It is assumed that the player already understands the rules.\n";
	cout << endl;
	cout << "===============================================================================" << endl;
	cout << endl;
	cout <<	"There are a few commands, listed below:\n\n" << left
			<< setw(8) << "Quit: " << setw(15) << " 'q' " << setw(10) << " immediately exit to shell \n"
			<< setw(8) << "Move: " << setw(15) << " 'm(from)(to)' " << setw(10) << " e.g. \'m12\' moves top card on stack 1 onto empty stack 2.\n"
			<< setw(8) << "Remove: " << setw(15) << " 'r(from)' " << setw(10) << " e.g. \'r3\' removes the top card from stack 3. \n"
			<< setw(8) << "Deal: " << setw(15) << " 'd' " << setw(10) << " will deal new layer of cards onto stacks."

		<< endl << endl;

	cout << "Press enter to continue: " ;
	cin.get();
}

void AcesUp::parseCommand(string input)
{

}

/* The renderer basically processes output line by line. It analyzes the current state of the
 * stax variable and outputs the state given by that analysis (which cards in which stacks, etc).
 * Since we render based on the state of the stax variable, the rendering is independent of any particular
 * user command. */

void AcesUp::render()
{

	bool finished = false;
	int layer = 0; /* Tracks which "layer" of cards is being displayed */
	int trash = stax[5].size();

	system("clear"); /* I know using "system" calls is incredibly bad practice from a security standpoint,
						but I'll come back and reimplement the functionality later */

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


