//
//  Card.hpp
//  SolitairePrime
//
//  Created by Nabiha Bashir on 2/5/20.
//  Copyright © 2020 Nabiha Bashir. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

class Card{
    
private:
    char suit, rank;

public:
    
    //constructors
    Card();
    Card(char r, char s);
    
    
    void setCard(char r, char s);
    
    //display card using characters (rank, suit)
    void display();
    
    //assign values to ranks
    int getValue();
    
    //returns rank of card (1-10)
    char getRank();
    
    //returns suit of card (S,D,H,C)
    char getSuit();    

};

#endif /* Card_hpp */
