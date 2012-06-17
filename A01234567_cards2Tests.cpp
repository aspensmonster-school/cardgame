/** \file A01234567_cards2Tests.cpp
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
#include "A01234567_cards2.h"

using namespace std;

/**
 *
 * \warning The way debugging output is set up, it is useless for actual debugging.
 * All it ever does is spit out the contents of the array, which, according to our
 * models, will ALWAYS have the same cards, even if they are in a different order.
 * The output showing the state of the cards as seen by the players is all one really
 * needs to see, with perhaps a sentence preceeding the out that explains the desired
 * outcome.
 *
 * \param cardSet
 * \param arrayName
 */

void testCardSet(Card cardSet[], string arrayName)
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

	refresh(cardSet); /* use default value of true for inSet */
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
		int random = rand() % DECK_SIZE;
		Card temp = pickUp(cardSet, random);
		displayCard(temp,true); /*always true here for sake of showing cards picked */
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
		int random = rand() % DECK_SIZE;
		Card temp = play(cardSet, random);
		displayCard(temp,true); /*always true here for sake of showing cards picked */
	}
	cout << "\n";

	testDisplay(cardSet);

	cout << "\n  +-------+";
	cout << "\n  |DEAL 13|";
	cout << "\n  +-------+";
	cout << "\n\n";



}

void testDisplay(Card cardSet[])
{

	cout << "\nDEBUG:\n";
	display(cardSet,true);

	cout << "\nRELEASE:\n";
	display(cardSet,false);

}

void reveal(Card cardSet[])
{

	for(int i = 0 ; i < DECK_SIZE ; i++)
	{
		cardSet[i].isVisible = true;
	}

}

void hide(Card cardSet[])
{

	for(int i = 0 ; i < DECK_SIZE ; i++)
	{
		cardSet[i].isVisible = false;
	}

}


