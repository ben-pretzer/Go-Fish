//
// Created by Ben on 11/2/2019.
//

#include "card.h"

Card::Card() {
    mySuit = spades;
    myRank = 1;                     // what are aces coded as?
}

Card::Card(int rank, Card::Suit s) {
    mySuit = s;
    myRank = rank;
}

string Card::toString() const {                       // return string version e.g. Ac 4h Js            ???
   return (suitString(mySuit) + rankString(myRank));
}


bool Card::sameSuitAs(const Card &c) const {          // true if suit same as c
    if (mySuit == c.mySuit) {
        return true;
    } else {
        return false;
    }
};


int  Card::getRank() const {                         // return rank, 1..13
    return myRank;
};

string Card::suitString(Card::Suit s) const {                     // return "s", "h",...
           if (s == spades) {
        return "s";
    } else if (s == hearts) {
        return "h";
    } else if (s == clubs) {
        return "c";
    } else if (s == diamonds) {
        return "d";
    }
           return "";
};

string Card::rankString(int r) const {                  // return "A", "2", ..."Q"      finish later!
    if (r == 1) {
        return ("A");
    } else if (r == 2) {
        return ("2");
    } else if (r == 3) {
        return ("3");
    } else if (r == 4) {
        return ("4");
    } else if (r == 5) {
        return ("5");
    } else if (r == 6) {
        return ("6");
    } else if (r == 7) {
        return ("7");
    } else if (r == 8) {
        return ("8");
    } else if (r == 9) {
        return ("9");
    } else if (r == 10) {
        return ("10");
    } else if (r == 11) {
        return ("J");
    } else if (r == 12) {
        return ("Q");
    } else if (r == 13) {
        return ("K");
    }
    return "";
};


bool Card::operator == (const Card &rhs) const {
    return (mySuit == rhs.mySuit &&
            myRank == rhs.myRank);
}

bool Card::operator != (const Card &rhs) const {
    return (mySuit != rhs.mySuit &&
            myRank != rhs.myRank);
};

void Card::operator = (const Card &rhs) {
    mySuit = rhs.mySuit;
    myRank = rhs.myRank;
    return;
}

ostream& operator<<(ostream& out, const Card& c) {
    out << "Suit: " << c.suitString(c.mySuit) << ", rank: " << c.rankString(c.myRank) << endl;
    return out;
}