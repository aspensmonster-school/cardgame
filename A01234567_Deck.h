/*
 * DeckClass.h
 *
 *  Created on: Jun 23, 2012
 *      Author: preston
 */

#ifndef DECK_H_
#define DECK_H_

#include "A01234567_cards3Utils.h"
#include "A01234567_Card.h" /* Have to include here since we're keeping a local array of Card objects in the deck */

using namespace std;

/*Basically, the "Deck" object is behaving as a container. */

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

	void takeCard(int card, bool up = false) { cardSet[card].pickUp(up); }
	void putCard(int card, bool up = false) { cardSet[card].play(up); }

};

#endif /* DECK_H_ */
