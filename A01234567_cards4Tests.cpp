/** \file A01234567_cards4Tests.cpp
 * \brief Contains functions for a testing suite. Currently does not use
 * preprocessor DEBUG macro, but might in the future.
 *
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

#include <iostream> /* cout */
#include <cstdlib>
#include "A01234567_cards4Tests.h"

using namespace std;

/**
 *
 * This function performs various tests on a given Deck container object. Refreshing,
 * revealing, hiding, shuffling, playing and dealing are all performed on the deck as
 * per the specification.
 *
 * \warning Please see A01234567_Deck.h (and other files) for documentation on conflicting
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
 * A01234567_Deck.h and A01234567_Deck.cpp don't obviously manifest themselves here, which
 * throws into question the utility of the test suite in its current spec'd form
 * for anything other than bugs that will already obviously manifest at runtime.
 * Or maybe I'm just being a cynical, contrarian bastard.
 *
 * \param[in] cardSet A Deck object. The Deck object holds an array of Card objects that
 * forms basis for a deck. Each Deck object has a full "deck" of 52 Card objects, but only
 * certain cards are revealed.
 * \param[in] arrayName A string that identifies the nature of the Deck object.
 * \param[in] inSet A bool that specifies the Deck's Card's initial \c isHeld
 * parameter. This is passed onto Deck::refresh, which then passes it onto Card::initialize.
 *
 */

void testCardSet(Deck cardSet, string arrayName, bool inSet)
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

	cardSet.refresh(inSet); /* use default value of true for inSet */
	testDisplay(cardSet);

	cout << "\n  +------------+";
	cout << "\n  |REVEALED SET|";
	cout << "\n  +------------+";
	cout << "\n";

	cardSet.revealAll();
	testDisplay(cardSet);

	cout << "\n  +----------+";
	cout << "\n  |HIDDEN SET|";
	cout << "\n  +----------+";
	cout << "\n";

	cardSet.hideAll();
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
		cardSet.setDebugFlag(true);
		cardSet.displayCard(i);
		cardSet.setDebugFlag(false);
	}
	cout << "\n";

	testDisplay(cardSet);

	cout << "\n  +------+";
	cout << "\n  |PLAYED|";
	cout << "\n  +------+";
	cout << "\n\n";

	cardSet.revealAll();

	for (int i = 0 ; i < 10 ; i++)
	{
		int random = rand() % DECK_SIZE; /* MIGHT BE SAME NUMBER MULTIPLE TIMES */

		/*
		Card temp = play(cardSet, random);
		displayCard(temp,true); //always true here for sake of showing cards picked
		*/

		cardSet.setDebugFlag(true);
		cardSet.displayCard(i);
		cardSet.setDebugFlag(false);

	}
	cout << "\n";

	testDisplay(cardSet);

	cout << "\n  +-------+";
	cout << "\n  |DEAL 13|";
	cout << "\n  +-------+";
	cout << "\n\n";

	cardSet.revealAll();
	cardSet.dealCards(13,inSet);
	testDisplay(cardSet);

	cout << "\n  +--------+";
	cout << "\n  |DEAL ALL|";
	cout << "\n  +--------+";
	cout << "\n\n";

	cardSet.dealCards(DECK_SIZE,inSet);
	testDisplay(cardSet);

	cout << "\n  +-------+";
	cout << "\n  |SHUFFLE|";
	cout << "\n  +-------+";
	cout << "\n\n";

	cardSet.refresh(inSet);
	cardSet.revealAll();
	cardSet.shuffle(1);
	testDisplay(cardSet);

	cout << "\n  +------+";
	cout << "\n  |DEAL 5|";
	cout << "\n  +------+";
	cout << "\n\n";

	cardSet.revealAll();
	cardSet.dealCards(5,inSet);
	testDisplay(cardSet);

	cout << "\n  +--------+";
	cout << "\n  |DEAL ALL|";
	cout << "\n  +--------+";
	cout << "\n\n";

	cardSet.dealCards(DECK_SIZE,inSet);
	testDisplay(cardSet);

	cout << "\n  +-------+";
	cout << "\n  |SHUFFLE|";
	cout << "\n  +-------+";
	cout << "\n\n";

	cardSet.refresh(inSet);
	cardSet.shuffle(1);
	testDisplay(cardSet);

	cout << "\n  +--------------+";
	cout << "\n  |Selection Sort|";
	cout << "\n  +--------------+";
	cout << "\n\n";

	cardSet.selectionSort();
	testDisplay(cardSet);

	cout << "\n  +-------+";
	cout << "\n  |SHUFFLE|";
	cout << "\n  +-------+";
	cout << "\n\n";

	cardSet.refresh(inSet);
	cardSet.shuffle(1);
	testDisplay(cardSet);


	cout << "\n  +-----------+";
	cout << "\n  |Bubble Sort|";
	cout << "\n  +-----------+";
	cout << "\n\n";

	cardSet.bubbleSort();
	testDisplay(cardSet);

	cout << "\n  +-------+";
	cout << "\n  |SHUFFLE|";
	cout << "\n  +-------+";
	cout << "\n\n";

	cardSet.refresh(inSet);
	cardSet.shuffle(1);
	testDisplay(cardSet);

	cout << "\n  +----------------+";
	cout << "\n  |Linear Search 14|";
	cout << "\n  +----------------+";
	cout << "\n\n";

	Card temp1 = cardSet.linearSearch(14);
	if( temp1.getInitIndex() == -1)
	{
		cout << "\n That card is in another castle!" << endl;
	}
	else
	{
		cout << "\n Here it is!" << endl;
		cout << temp1.getFaceSymbol() << temp1.getSuitSymbol() << endl;
	}

	cout << "\n  +----------------+";
	cout << "\n  |Binary Search 14|";
	cout << "\n  +----------------+";
	cout << "\n\n";

	/* Binary search only works on a sorted deck */
	cardSet.selectionSort();

	Card temp2 = cardSet.linearSearch(14);
	if( temp2.getInitIndex() == -1)
	{
		cout << "\n That card is in another castle!" << endl;
	}
	else
	{
		cout << "\n Here it is!" << endl;
		cout << temp2.getFaceSymbol() << temp2.getSuitSymbol() << endl;
	}

}

/**
 *
 * This function is called from testCardSet, and then goes on to call the actual
 * \c display function. It will display both in debug mode and release mode.
 *
 * \param[in] cardSet A Deck object. The Deck object holds an array of Card objects that
 * forms basis for a deck. Each Deck object has a full "deck" of 52 Card objects, but only
 * certain cards are revealed.
 *
 */

void testDisplay(Deck cardSet)
{

	cout << "\nDEBUG:\n";
	cardSet.setDebugFlag(true);
	cardSet.display(DECK_SIZE);

	cout << "\nRELEASE:\n";
	cardSet.setDebugFlag(false);
	cardSet.display(DECK_SIZE);

}
