/** \file A01234567_cards3Tests.cpp
 * \brief Contains functions for a testing suite. Currently does not use
 * preprocessor DEBUG macro, but might in the future.
 *
 * \author Preston Maness
 *
 * Created on: Jun 16, 2012
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

#include <iostream> /* cout */
#include <cstdlib>
#include "A01234567_cards3Tests.h"

using namespace std;

/**
 *
 * This function performs various tests on a given array of Card objects. Refreshing,
 * revealing, hiding, shuffling, playing and dealing are all performed on the deck as
 * per the specification.
 *
 * \warning Please see A01234567_Deck.cpp for documentation on conflicting
 * requirements in the specification regarding the \c display and \c displayCard functions.
 * These will have direct effect on the output of this test suite.
 *
 * \warning The way debugging output is set up, it is useless for actual debugging.
 * All it ever does is spit out the contents of the array, which, according to our
 * models, will ALWAYS have the same cards, even if they are in a different order.
 * The output showing the state of the cards as seen by the players is all one really
 * needs to see, with perhaps a sentence preceding the output that explains the desired
 * outcome.
 *
 * \warning The numerous design problems documented in the warning flags in
 * A01234567_Deck.cpp don't obviously manifest themselves here, which
 * throws into question the utility of the test suite in its current spec'd form
 * for anything other than bugs that will already obviously manifest at runtime.
 * Or maybe I'm just being a cynical, contrarian bastard.
 *
 * \param[in] cardSet Array of Card objects. Array forms basis for a deck. Each
 * player has a full "deck" of 52 card objects, but only certain cards are revealed.
 * \param[in] arrayName A string that identifies the nature of the cardSet array.
 * \param[in] inSet A string that specifies the array's Card's initial \c isHeld
 * parameter. This is passed onto refresh, which then passes it onto initialize.
 *
 */

void testCardSet(Card cardSet[], string arrayName, bool inSet)
{

	/* It's times like these when I really wish I knew ncurses */

	cout << "================================================================================";

	/*
	 * Find out how far to move over in order to center.
	 * The 80 is standard terminal width.
	 * The plus 8 is the length of "Testing ".
	 * Divide by two and cast to int to find out how far
	 * you need to move over.
	 */

	int pos=(int)( ( 80 - (arrayName.length() + 8 ) ) / 2 );
	for(int i=0;i<pos;i++)
	{
		cout<<" ";
	}

	cout << "Testing " << arrayName << endl;
	cout << "================================================================================";

	cout << "\n";
	cout << "\n  +---------+";
	cout << "\n  |FRESH SET|";
	cout << "\n  +---------+";
	cout << "\n";

	refresh(cardSet,inSet); /* use default value of true for inSet */
	testDisplay(cardSet);

	cout << "\n  +------------+";
	cout << "\n  |REVEALED SET|";
	cout << "\n  +------------+";
	cout << "\n";

	reveal(cardSet);
	testDisplay(cardSet);

	cout << "\n  +----------+";
	cout << "\n  |HIDDEN SET|";
	cout << "\n  +----------+";
	cout << "\n";

	hide(cardSet);
	testDisplay(cardSet);

	cout << "\n  +---------+";
	cout << "\n  |PICKED UP|";
	cout << "\n  +---------+";
	cout << "\n\n";

	/* Gonna start picking up ten random cards and showing them */
	for (int i = 0 ; i < 10 ; i++)
	{
		int random = rand() % DECK_SIZE; /* MIGHT BE SAME NUMBER MULTIPLE TIMES */

		/*
		Card temp = pickUp(cardSet, random);
		displayCard(temp,true); //always true here for sake of showing cards picked
		*/

		displayCard(cardSet[random],true);
	}
	cout << "\n";

	testDisplay(cardSet);

	cout << "\n  +------+";
	cout << "\n  |PLAYED|";
	cout << "\n  +------+";
	cout << "\n\n";

	reveal(cardSet);

	for (int i = 0 ; i < 10 ; i++)
	{
		int random = rand() % DECK_SIZE; /* MIGHT BE SAME NUMBER MULTIPLE TIMES */

		/*
		Card temp = play(cardSet, random);
		displayCard(temp,true); //always true here for sake of showing cards picked
		*/

		displayCard(cardSet[random],true);

	}
	cout << "\n";

	testDisplay(cardSet);

	cout << "\n  +-------+";
	cout << "\n  |DEAL 13|";
	cout << "\n  +-------+";
	cout << "\n\n";

	reveal(cardSet);
	deal(cardSet,13);
	testDisplay(cardSet);

	cout << "\n  +--------+";
	cout << "\n  |DEAL ALL|";
	cout << "\n  +--------+";
	cout << "\n\n";

	deal(cardSet,DECK_SIZE);
	testDisplay(cardSet);

	cout << "\n  +-------+";
	cout << "\n  |SHUFFLE|";
	cout << "\n  +-------+";
	cout << "\n\n";

	refresh(cardSet,inSet);
	reveal(cardSet);
	shuffle(cardSet);
	testDisplay(cardSet);

	cout << "\n  +------+";
	cout << "\n  |DEAL 5|";
	cout << "\n  +------+";
	cout << "\n\n";

	reveal(cardSet);
	deal(cardSet,5);
	testDisplay(cardSet);

	cout << "\n  +--------+";
	cout << "\n  |DEAL ALL|";
	cout << "\n  +--------+";
	cout << "\n\n";

	deal(cardSet,DECK_SIZE);
	testDisplay(cardSet);

}

/**
 *
 * This function is called from testCardSet, and then goes on to call the actual
 * \c display function. It will display both in debug mode and release mode.
 *
 * \param[in] cardSet Array of Card objects. Array forms basis for a deck. Each
 * player has a full "deck" of 52 card objects, but only certain cards are revealed.
 */

void testDisplay(Card cardSet[])
{

	cout << "\nDEBUG:\n";
	display(cardSet,true);

	cout << "\nRELEASE:\n";
	display(cardSet,false);

}
