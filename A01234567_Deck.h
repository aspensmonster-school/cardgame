/**\file A01234567_Card.cpp
 * \brief Describes a Deck object, which really just acts as an ad hoc container.
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

#ifndef DECK_H_
#define DECK_H_

#include "A01234567_cards3Utils.h"
#include "A01234567_Card.h" /* Have to include here since we're keeping a local array of Card objects in the deck */

using namespace std;

/* Basically, the "Deck" object is behaving as a container. */

class Deck

{

private:

	Card cardSet[DECK_SIZE];
	bool debugging;

public:

	Deck();
	~Deck();

	bool getDebugFlag() const { return debugging; }
	void setDebugFlag(bool flag) { debugging = flag; }

	void revealCard(int thisCard) { cardSet[thisCard].show(); }
	void revealAll();
	void hideCard(int thisCard) { cardSet[thisCard].hide(); }
	void hideAll();

	void refresh(bool inSet = false);
	void display(int);
	void shuffle(int);
	void displayCard(int numCards = 0);
	void deal(int numCards = 0 , bool faceUp = false);

	void takeCard(int card, bool up = false);
	void putCard(int card, bool up = false);

};

#endif /* DECK_H_ */
