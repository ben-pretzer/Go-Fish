//
// Created by Ben on 11/2/2019.
//

#include "player.h"
#include <vector>
#include <ctime>


using namespace std;
int count = 0;
int index = 0;
Player::Player() {
    numOfPlayers++;
}

Player::Player(string name) {
    myName = name;
    numOfPlayers++;
    srand(time(0));
};

void Player::addCard(Card c) {
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);
    removeCardFromHand(c1);
    removeCardFromHand(c2);
}

bool Player::checkHandForPair(Card &c1, Card &c2) {
    for (int i = 0; i < myHand.size(); i++) {
        for (int j = 1; j < myHand.size(); j++) {
            if (myHand.at(i).getRank() == myHand.at(j).getRank() && (i != j)) {
                c1 = myHand.at(i);
                c2 = myHand.at(j);
                return true;
            }
        }
    }
    return false;
}

Card Player::chooseCardFromHand() const {

    int randomNum = (rand() % myHand.size());
    Card card = myHand.at(randomNum);
    return card;
}

string Player::showHand() const {
    string total = "";
    for (int i = 0; i < myHand.size(); i++) {
        total = total + myHand.at(i).toString() + ' ';
    }
    return total;
}

string Player::showBooks() const {
    cout << "Book is as follows: " << endl;
    for (int i = 0; i < myBook.size(); i++) {
        cout << myBook.at(i) << endl;
    }
}

bool Player::cardInHand(Card c) const {
    for (int i = 0; i < myHand.size(); i++) {
        if ((myHand.at(i)).getRank() == c.getRank()) {
            return true;
        }
    }
    return false;
}

Card Player::removeCardFromHand(Card c) {
    for (int i = 0; i < myHand.size(); i++) {
        if (c.getRank() == myHand.at(i).getRank()) {
            Card returnedCard;
            returnedCard = myHand.at(i);
            myHand.erase(myHand.begin() + i);
            return returnedCard;
        }
    }
}

int Player::getBookSize() const {
    return (myBook.size() / 2);
}

int Player::getHandSize() const {
    return (myHand.size());
}
