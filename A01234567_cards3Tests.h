/*
 * cards3Tests.h
 *
 *  Created on: Jun 23, 2012
 *      Author: preston
 */

#ifndef CARDS3TESTS_H_
#define CARDS3TESTS_H_

#include "A01234567_Deck.h"

using namespace std;

/* Test Suite */
void testCardSet(Card[], string, bool);
void testDisplay(Card[]);
void reveal(Card[]);
void hide(Card[]);

#endif /* CARDS3TESTS_H_ */
