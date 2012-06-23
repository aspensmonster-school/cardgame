/*
 * CardClass.h
 *
 *  Created on: Jun 23, 2012
 *      Author: preston
 */

#ifndef CARDCLASS_H_
#define CARDCLASS_H_

#include "A01234567_cards2.h"

Card initialize(int, int, int, bool isHere = true);
Card pickUp(Card[], int);
Card play(Card[], int, bool faceUp = false);


#endif /* CARDCLASS_H_ */
