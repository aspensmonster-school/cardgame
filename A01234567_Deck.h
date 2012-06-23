/*
 * DeckClass.h
 *
 *  Created on: Jun 23, 2012
 *      Author: preston
 */

#ifndef DECKCLASS_H_
#define DECKCLASS_H_

#include <string>
#include "A01234567_Card.h"

using namespace std;

struct Card{

	/* Sensible naming scheme

	int suit;
	int value;
	string valueSymbol;
	char suitSymbol;
	bool held;
	bool visible;
	int initIndex;

	*/

	/* Required naming scheme */

	int suit;
	int faceValue;
	string vSymbol;
	char sSymbol;
	bool isHeld;
	bool isVisible;
	int initIndex;

};

void refresh(Card[], bool inSet = true);
void display(Card[], bool debugging = false);
void shuffle(Card[]);
void displayCard(Card, bool debugging = false);
void deal(Card[], int);

#endif /* DECKCLASS_H_ */
