/** \file A01234567_cards1Functions.cpp
  \brief Contains various functions used by the program to do tasks.

  Original Author: Carl Gregory

  Date: 05/06/12 13:24
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

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>   // rand and srand
#include <ctime>     // For the time function

#include "A01234567_cards1.h"

using namespace std;

/**

  Seeds the random number generator.

  Original Author: Carl Gregory

  Date: 21/05/12 14:07

*/

void setupRand()
{
    // Set up pseusorandom numbers

    // Get the system time.
    unsigned seed = time(0);

    // Seed the random number generator with unsidned system time
    srand(seed);

} //

/**

  Assigns all suit and number values to the card deck (2D array)

  Creates a fresh deck made from a 2D array.

  Original Author: Carl Gregory

  Date: 25/04/12 13:48

  Modified by: Preston Maness

  Date: 09/06/12

  \param[in] cardDeck 2D array that contains the deck. Rows are suits,
  	  columns are cards.
  \param[in] suits Number of card suits. NUM_SUITS is usually passed here.
  \param[in] cards Size of each card suit. NUM_SUIT_CARDS is usually passed here.

*/

void freshDeck(int cardDeck[][NUM_SUIT_CARDS] , int suits , int cards)
{
 	 // just assign each element its own index
 	 for (int i = 0 ; i < suits ; i++)
 	 {
 		 for (int j = 0 ; j < cards ; j++)
 		 {
 			 cardDeck[i][j] = j;
 		 }
	 }
 	 
} // void freshDeck( )

/**

  Displays the full card deck (2D) in its current state.
  Iterates over the deck using nested for loop, passing
  each cell of the array to displayCard.

  Original Author: Carl Gregory

  Date: 25/04/12 13:48

  Modified by: Preston Maness

  Date: 09/06/12

  \param[in] cardDeck 2D array that contains the deck. Rows are suits,
  	  columns are cards.
  \param[in] suits Number of card suits. NUM_SUITS is usually passed here.
  \param[in] cards Size of each card suit. NUM_SUIT_CARDS is usually passed here.

*/

void displayDeck(int cardDeck[][NUM_SUIT_CARDS] , int suits, int cards)
{

	for (int i = 0 ; i < suits ; i++)
	{
		for (int j = 0 ; j < cards ; j++)
		{
			displayCard(cardDeck,i,j);
			cout << ", ";
		}
		cout << "\n";
	}

} // void displayDeck( )

/**

  Randomly swaps card values in random suits
  in the card deck (4 parallel arrays).

\warning This doesn't actually "shuffle" the deck from what I can tell. It swaps up card values
but not suits. You still have all spades, then all hearts, then all diamonds,
then all clubs being displayed. A better design would just be to define a
card object and make a vector full of those. Much easier to do and what I'll
be adding later this weekend.

\pre The deck is initialized and the cards are in any particular order.
Typically this function is called from main right after creating a deck,
as the created deck is in order and needs to be shuffled.

\post The deck is shuffled.

  Original Author: Carl Gregory

  Date: 25/04/12 13:48

\verbatim
  Algorithm:

	  for the chosen number of swaps:

		generate two random numbers (from and to) for the card value

		generate two random numbers (from and to) for the suit

		time-tested swap technique:

			set a temp value to (to suit)[ (to card) ]

			set (to   suit)[ (to   card) ] to

				(from suit)[ (from card) ]

			set (from suit)[ (from card) ] to the temp value
\endverbatim

Sidenote: In what universe is that kind of pseudocode "universal?"
I haven't the foggiest idea what's going on up there.

  \param[in] spades Contains number values of spades cards
  \param[in] hearts Contains number values of hearts cards
  \param[in] diamonds Contains number values of diamonds cards
  \param[in] clubs Contains number values of clubs cards
  \param[in] size Size of each card suite, typically 13.

*/

void shuffleDeck(int cardDeck[][NUM_SUIT_CARDS], int suits , int cards)
{

 	 const int NUM_SWAPS = cards;
 	 
 	 int fromSuit, toSuit;
 	 int fromCard, toCard;
 	 int swap, temp;
 	 
 	 bool noProblem = true;
 	 
 	 /*
 	   I think there are actual statistics on such things as "after three normal
 	   shuffles the deck is effectively back to its starting point", none of
 	   which I really trust, but clearly the number of swaps makes a difference
 	   here.
 	   
 	   To allow a "fudge factor", I don't check for duplicates, that is, I allow
 	   a card to be swapped with itself.  This makes each shuffle involve a
 	   different number of cards each time.
 	   
 	   I have no idea whatsoever whether this makes any difference, or whether
 	   that difference is desirable or not.
 	 */
  	 noProblem = true;
 	 for (swap = 0; ( (swap < NUM_SWAPS) && noProblem ); ++swap)
 	 {
	  	 /*
		    We know it's 4 suits because there are four array parameters;
			couldn't be more general using a defined constant NUM_SUITS here
			because we would have to change the parameter list each time we
			change the value of the constant
			
			This wouldn't be the case with, say, a 2-D array --
			in that case we would HAVE to use something like NUM_SUITS instead
			of the literal 4
	  	 */
	  	 fromSuit = rand() % NUM_SUITS;
	  	 toSuit = rand() % NUM_SUITS;
	  	 fromCard = rand() % NUM_SUIT_CARDS;
	  	 toCard = rand() % NUM_SUIT_CARDS;
	  	 
		 /*
		  time-tested swap technique, but a bit awkward with separate arrays
				set a temp value to (to suit)[ (to card) ]
				set (to   suit)[ (to   card) ] to
					(from suit)[ (from card) ]
				set (from suit)[ (from card) ] to the temp value
		 */
	  	 switch (fromSuit)
	  	 {
		  	 case 0:		// from spades
				switch (toSuit)
				{
				 case 0:	// to spades
					  temp = cardDeck[0][toCard];
					  cardDeck[0][toCard] = cardDeck[0][fromCard];
					  cardDeck[0][fromCard] = temp;
					 /*temp = spades[toCard];
				 	  temp = spades[toCard] = spades[fromCard];
				 	  spades[fromCard] = temp;*/
				 	  break;
				 case 1:	// to hearts
					  temp = cardDeck[1][toCard];
					  cardDeck[1][toCard] = cardDeck[0][fromCard];
					  cardDeck[0][fromCard] = temp;
				 	  /*temp = hearts[toCard];
				 	  temp = hearts[toCard] = spades[fromCard];
				 	  spades[fromCard] = temp;
				 	  */
				 	  break;
				 case 2:	// to diamonds
					  temp = cardDeck[2][toCard];
					  cardDeck[2][toCard] = cardDeck[0][fromCard];
					  cardDeck[0][fromCard] = temp;
				 	  /*temp = diamonds[toCard];
				 	  temp = diamonds[toCard] = spades[fromCard];
				 	  spades[fromCard] = temp;*/
				 	  break;
				 case 3:	// to clubs
					  temp = cardDeck[3][toCard];
					  cardDeck[3][toCard] = cardDeck[0][fromCard];
					  cardDeck[0][fromCard] = temp;
				 	  /*temp = clubs[toCard];
				 	  temp = clubs[toCard] = spades[fromCard];
				 	  spades[fromCard] = temp;*/
				 	  break;
				 default:
				 	  noProblem = false;
				 	  break;
				}; // switch (toSuit) from spades
				break;
		  	 case 1:		// from to hearts
				switch (toSuit)
				{
				 case 0:	// to spades
					  temp = cardDeck[0][toCard];
					  cardDeck[0][toCard] = cardDeck[1][fromCard];
					  cardDeck[1][fromCard] = temp;
				 	  /*temp = spades[toCard];
				 	  temp = spades[toCard] = hearts[fromCard];
				 	  hearts[fromCard] = temp;*/
				 	  break;
				 case 1:	// to hearts
					  temp = cardDeck[1][toCard];
					  cardDeck[1][toCard] = cardDeck[1][fromCard];
					  cardDeck[1][fromCard] = temp;
				 	  /*temp = hearts[toCard];
				 	  temp = hearts[toCard] = hearts[fromCard];
				 	  hearts[fromCard] = temp;*/
				 	  break;
				 case 2:	// to diamonds
					  temp = cardDeck[2][toCard];
					  cardDeck[2][toCard] = cardDeck[1][fromCard];
					  cardDeck[1][fromCard] = temp;
				 	  /*temp = diamonds[toCard];
				 	  temp = diamonds[toCard] = hearts[fromCard];
				 	  hearts[fromCard] = temp;*/
				 	  break;
				 case 3:	// to clubs
					  temp = cardDeck[3][toCard];
					  cardDeck[3][toCard] = cardDeck[1][fromCard];
					  cardDeck[1][fromCard] = temp;
				 	  /*temp = clubs[toCard];
				 	  temp = clubs[toCard] = hearts[fromCard];
				 	  hearts[fromCard] = temp;*/
				 	  break;
				 default:
				 	  noProblem = false;
				 	  break;
				}; // switch (toSuit) from hearts
				break;
		  	 case 2:		// from diamonds
				switch (toSuit)
				{
				 case 0:	// to spades
					  temp = cardDeck[0][toCard];
					  cardDeck[0][toCard] = cardDeck[2][fromCard];
					  cardDeck[2][fromCard] = temp;
				 	  /*temp = spades[toCard];
				 	  temp = spades[toCard] = diamonds[fromCard];
				 	  diamonds[fromCard] = temp;*/
				 	  break;
				 case 1:	// to hearts
					  temp = cardDeck[1][toCard];
					  cardDeck[1][toCard] = cardDeck[2][fromCard];
					  cardDeck[2][fromCard] = temp;
					  /*temp = hearts[toCard];
				 	  temp = hearts[toCard] = diamonds[fromCard];
				 	  diamonds[fromCard] = temp;*/
				 	  break;
				 case 2:	// to diamonds
					  temp = cardDeck[2][toCard];
					  cardDeck[2][toCard] = cardDeck[2][fromCard];
					  cardDeck[2][fromCard] = temp;
				 	  /*temp = diamonds[toCard];
				 	  temp = diamonds[toCard] = diamonds[fromCard];
				 	  diamonds[fromCard] = temp;*/
				 	  break;
				 case 3:	// to clubs
					  temp = cardDeck[3][toCard];
					  cardDeck[3][toCard] = cardDeck[2][fromCard];
					  cardDeck[2][fromCard] = temp;
				 	  /*temp = clubs[toCard];
				 	  temp = clubs[toCard] = diamonds[fromCard];
				 	  diamonds[fromCard] = temp;*/
				 	  break;
				 default:
				 	  noProblem = false;
				 	  break;
				}; // switch (toSuit) from diamonds
				break;
		  	 case 3:		// from clubs
				switch (toSuit)
				{
				 case 0:	// to spades
					  temp = cardDeck[0][toCard];
					  cardDeck[0][toCard] = cardDeck[3][fromCard];
					  cardDeck[3][fromCard] = temp;
				 	 /* temp = spades[toCard];
				 	  temp = spades[toCard] = clubs[fromCard];
				 	  clubs[fromCard] = temp;*/
				 	  break;
				 case 1:	// to hearts
					  temp = cardDeck[1][toCard];
					  cardDeck[1][toCard] = cardDeck[3][fromCard];
					  cardDeck[3][fromCard] = temp;
				 	  /*temp = hearts[toCard];
				 	  temp = hearts[toCard] = clubs[fromCard];
				 	  clubs[fromCard] = temp;*/
				 	  break;
				 case 2:	// to diamonds
					  temp = cardDeck[2][toCard];
					  cardDeck[2][toCard] = cardDeck[3][fromCard];
					  cardDeck[3][fromCard] = temp;
				 	  /*temp = diamonds[toCard];
				 	  temp = diamonds[toCard] = clubs[fromCard];
				 	  clubs[fromCard] = temp;*/
				 	  break;
				 case 3:	// to clubs
					  temp = cardDeck[3][toCard];
					  cardDeck[3][toCard] = cardDeck[3][fromCard];
					  cardDeck[3][fromCard] = temp;
				 	  /*temp = clubs[toCard];
				 	  temp = clubs[toCard] = clubs[fromCard];
				 	  clubs[fromCard] = temp;*/
				 	  break;
				 default:
				 	  noProblem = false;
				 	  break;
				}; // switch (toSuit) from clubs
				break;
		  	 default:
			 	  noProblem = false;
			 	  break;
 		 }; // switch (fromSuit)
	  	 
	 } // for (swap = 0; swap < NUM_SWAPS; ++swap)
} // void shuffleDeck( )

/**
 *
 * Displays a card in the deck. Takes the position in the array
 * (determined by the suit and card integers passed), and displays
 * the appropriate card. The Ace and 2-9 cases are simpler and
 * require fewer switches. 10-K require nested switches.
 *
 * @param cardDeck 2D array that holds the cards
 * @param suit Specifies the suit, 0-3
 * @param card Specifies the card, 0-12
 */

void displayCard(int cardDeck[][NUM_SUIT_CARDS] , int suit, int card)
{

	if( cardDeck[suit][card] == 0) /* Ace */
	{
		cout << "A";
		switch(suit)
		{
			case 0: /* spades */
				cout << "S";
				break;
			case 1: /* hearts */
				cout << "H";
				break;
			case 2: /* diamonds */
				cout << "D";
				break;
			case 3: /* clubs */
				cout << "C";
				break;
			default: /* what did you do? */
				cout << "?";
				break;

		}
	}

	if( cardDeck[suit][card] >= 1 && cardDeck[suit][card] <=8) /* 2-9 */
	{
		cout << (cardDeck[suit][card] + 1); /* Without plus one you're just printing the index */
		switch(suit)
		{
			case 0: /* spades */
				cout << "S";
				break;
			case 1: /* hearts */
				cout << "H";
				break;
			case 2: /* diamonds */
				cout << "D";
				break;
			case 3: /* clubs */
				cout << "C";
				break;
			default: /* what did you do? */
				cout << "?";
				break;

		}
	}

	if( cardDeck[suit][card] >=9) /* 10-K */
	{
		switch(suit)
		{
			case 0: /* spades */
				switch(cardDeck[suit][card])
				{
					case 9: /* 10 */
						cout << "10";
						break;
					case 10: /* Jack */
						cout << "J";
						break;
					case 11: /* Queen */
						cout << "Q";
						break;
					case 12: /* King */
						cout << "K";
						break;
					default: /* what did you do? */
						cout << "?";
						break;
				}
				cout << "S";
				break; /* end spades */

			case 1: /* hearts */
				switch(cardDeck[suit][card])
				{
					case 9: /* 10 */
						cout << "10";
						break;
					case 10: /* Jack */
						cout << "J";
						break;
					case 11: /* Queen */
						cout << "Q";
						break;
					case 12: /* King */
						cout << "K";
						break;
					default: /* what did you do? */
						cout << "?";
						break;
				}
				cout << "H";
				break; /* end hearts */

			case 2: /* diamonds */
				switch(cardDeck[suit][card])
				{
					case 9: /* 10 */
						cout << "10";
						break;
					case 10: /* Jack */
						cout << "J";
						break;
					case 11: /* Queen */
						cout << "Q";
						break;
					case 12: /* King */
						cout << "K";
						break;
					default: /* what did you do? */
						cout << "?";
						break;
				}
				cout << "D";
				break; /* End Diamonds */

			case 3: /* clubs */
				switch(cardDeck[suit][card])
				{
					case 9: /* 10 */
						cout << "10";
						break;
					case 10: /* Jack */
						cout << "J";
						break;
					case 11: /* Queen */
						cout << "Q";
						break;
					case 12: /* King */
						cout << "K";
						break;
					default: /* what did you do? */
						cout << "?";
						break;
				}
				cout << "C";
				break; /* End Clubs */

			default: /* what did you do? */
				cout << "?";
				break;

		} /* end suit switch */

	} /* end if 10-K */

}



