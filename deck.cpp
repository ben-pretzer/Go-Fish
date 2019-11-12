//
// Created by Ben on 11/2/2019.
//

#include "deck.h"
#include "card.h"
#include <ctime>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int myIndex = 0;

Deck::Deck() {
    int k = 0;                                  // this is just a pointer for the number of cards to put into the deck - 52
    srand(time(0));
    myIndex = 0;                                // setting index to 0, meaning ace of spades is gonna be on the top
    for (int i = 0; i < 4; i++) {               // 13 ranks
        for (int j = 1; j < 14; j++) {          // 4 suits
            Card c(j, (Card::Suit) i);
            if (k > 51) {                       // once k = 52, jump out
                return;
            }
            myCards[k] = c;
            k++;
        }
    }
}

void Deck::shuffle() {
    for (int i = 0; i < 260; i++) {
        int randomNumber1 = (rand() % 52);
        int randomNumber2 = (rand() % 52);
        Card temp = myCards[randomNumber1];
        myCards[randomNumber1] = myCards[randomNumber2];
        myCards[randomNumber2] = temp;
    }
}

int Deck::size() {
    int counter = 0;
    for (int i = myIndex; i < SIZE; i++) {
        counter++;
    }
    return counter;
}

Card Deck::dealCard() {
    if (myIndex < 52) {
       Card dealtCard = myCards[myIndex];
       myIndex++;
       return dealtCard;
   }
}