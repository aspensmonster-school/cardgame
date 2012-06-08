#ifndef CARDS1
#define CARDS1

/*
  Name: cards1.h
  Author:Carl Gregory
  Date: 21/05/12 15:24
  Modified by: Preston Maness
  Date: 08/06/12 17:38
  Description:
        First stage of Card project for CS2308-501 Summer 2012
        - Simulates dealing a deck of cards to four players;
        - Uses four integer parallel arrays of "suits":
               represented by integers and must be displayed via switch statement
        - Uses random numbers
          	   (Gaddis ed. 7, pp. 129-130, example program 3-25)

*/
#include <string>

using namespace std;

const int NUM_SUIT_CARDS = 13;

void setupRand();
void freshDeck(int [] , int [] , int [] , int [] , int );
void displayDeck(int [] , int [] , int [] , int [] , int );
void shuffleDeck(int [] , int [] , int [] , int [] , int );

#endif
