#include <iostream>
#include <string>
#include <vector>
#include "card.h"
#include "deck.h"
#include "player.h"
#include <fstream>


using namespace std;

int winner = 1;
int main() {

    ofstream oFile;
    oFile.open("gofish_results.txt");
    Deck d;

    int size = d.size();
    oFile << "The size of this deck is " << size << endl;                   // for every cout, need to change to oFile
    d.shuffle();

    Player (Kyle);
    numOfPlayers++;
    Player (stewie);
    numOfPlayers++;
    if (numOfPlayers == 2) {
        for (int i = 0; i < 7; i++) {
            Kyle.addCard(d.dealCard());
        }
        for (int i = 0; i < 7; i++) {
            stewie.addCard(d.dealCard());
        }
    }

    Card x,y;
    if (Kyle.checkHandForPair(x,y) == true) {
        Kyle.bookCards(x,y);
    };
    if (stewie.checkHandForPair(x, y) == true) {
        stewie.bookCards(x,y);
    };
                                                                            // both players have 7 shuffled cards
    while (Kyle.getBookSize() + stewie.getBookSize() < 26) {                // encompassing while loop to run the game

        while ((Kyle.checkHandForPair(x,y) == true)) {
            Kyle.bookCards(x,y);
        };
        while ((stewie.checkHandForPair(x,y) == true)) {
            stewie.bookCards(x,y);
        };

        winner = 1;
        while (winner == 1) {
            if (Kyle.getHandSize() == 0) {
                Kyle.addCard(d.dealCard());
            }

            Card chosenCard = Kyle.chooseCardFromHand();
            oFile << "Kyle asked about the card:" << endl << chosenCard << endl;

            if (stewie.cardInHand(chosenCard) == true) {

                Kyle.addCard(chosenCard);
                if (Kyle.checkHandForPair(x,y)) {
                    Kyle.bookCards(x,y);
                }
                oFile << "Stewie had the card and gave it to Kyle." << endl;
                oFile << "Kyle's hand is as follows: " << Kyle.showHand() << endl;
                oFile << "Kyle gets to go again!" << endl;
                winner = 1;
            } else {
                oFile << "Stewie said Go Fish!" << endl;
                Kyle.addCard(d.dealCard());
                winner = 0;
            }
        }

        winner = 1;
        while (winner == 1) {
            if (stewie.getHandSize() == 0) {
                stewie.addCard(d.dealCard());
            }

            Card chosenCard2 = stewie.chooseCardFromHand();
            oFile << "Stewie asked about the card:" << endl << chosenCard2 << endl;

            if (Kyle.cardInHand(chosenCard2) == true) {
                stewie.addCard(chosenCard2);
                if (stewie.checkHandForPair(x,y)) {
                    stewie.bookCards(x, y);
                }
                oFile << "Kyle had the card and gave it to Stewie." << endl;
                oFile << "Stewie's hand is as follows: " << stewie.showHand() << endl;
                oFile << "Stewie gets to go again!" << endl;
                winner = 1;
            } else {
                oFile << "Kyle said Go Fish!" << endl;
                stewie.addCard(d.dealCard());
                winner = 0;
            }
        }
    }

    if (Kyle.getBookSize() > stewie.getBookSize()) {
        oFile << "Kyle is the winner!" << endl;
    } else if (stewie.getBookSize() > Kyle.getBookSize()) {
        oFile << "Stewie is the winner!" << endl;
    } else {
        oFile << "The game has ended in a tie!" << endl;
    }
    oFile.close();
    return EXIT_SUCCESS;
    };