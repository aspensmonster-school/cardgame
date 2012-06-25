/** \file A01234567_cards3Tests.cpp
  \brief Contains functions that dictate the actions of the test suite. Test suite
  interfaces with various Deck object member functions.
  \author Preston Maness
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

#ifndef CARDS3TESTS_H_
#define CARDS3TESTS_H_

#include "A01234567_Deck.h"
#include "A01234567_Card.h"

using namespace std;

/* Test Suite */
void testCardSet(Deck, string, bool);
void testDisplay(Deck);

#endif /* CARDS3TESTS_H_ */
