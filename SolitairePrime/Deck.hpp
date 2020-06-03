//
//  Deck.hpp
//  SolitairePrime
//
//  Created by Nabiha Bashir on 2/5/20.
//  Copyright © 2020 Nabiha Bashir. All rights reserved.
//

#ifndef Deck_hpp
#define Deck_hpp

#include "Card.hpp"

class Deck{
    
private:
    //the next card to deal with
    int top;
    //an array of cards
    Card storage[52];


public:
    Deck();
    
    void display();
    void shuffle();
    Card deal();
    int cardsLeft();

};

#endif /* Deck_hpp */
