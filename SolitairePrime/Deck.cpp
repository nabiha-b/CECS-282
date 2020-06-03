//
//  Deck.cpp
//  SolitairePrime
//
//  Created by Nabiha Bashir on 2/5/20.
//  Copyright © 2020 Nabiha Bashir. All rights reserved.
//

#include "Deck.hpp"
#include "Card.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;

Deck::Deck(){
    char suits[] = {'H', 'D', 'S', 'C'};
    char ranks[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    top = 0;
    int x = 0;
        
    //use for loop to create cards
    for (int s = 0; s < 4; s++){
        for (int r = 0; r < 13; r++){
            storage[x++].setCard(ranks[r], suits[s]);
        }
    }
};

void Deck::display(){
    
    int i = 0;
    cout <<"Deck of Cards: \n";
    while (i < 52) {
        storage[i++].display();
        cout << " ";
        
        if(i%13 == 0){
            cout<<" \n";
        }
    }
}

//shuffles deck of cards
void Deck::shuffle(){
    
    srand(time(0));
    
    for (int i = 0; i < 1000; i++){
        int x = rand()%52;
        int y = rand()%52;
        
        Card temp = storage[x];
        storage[x] = storage[y];
        storage[y] = temp;
    }
}

Card Deck::deal(){
    return storage[top++];
}

int Deck::cardsLeft(){
    int cardsLeft = 52 - top;
    return cardsLeft;
}



