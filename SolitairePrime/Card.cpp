//
//  Card.cpp
//  SolitairePrime
//
//  Created by Nabiha Bashir on 2/5/20.
//  Copyright © 2020 Nabiha Bashir. All rights reserved.
//

#include "Card.hpp"
#include <iostream>
using namespace std;

//constructors
Card::Card(){
    rank = 'X';
    suit = 'X';
}

Card::Card(char r, char s){
    rank = r;
    suit = s;
}

//sets value rank and suit for a card
void Card::setCard(char r, char s){
    rank = r;
    suit = s;;
}

//display card using characters (rank, suit)
void Card::display(){
    if (rank != 'T') {
        cout<<rank<<suit<<" ";}
    else{
        cout<<10<<suit<<" ";}
    }
    
//assign values to ranks
int Card::getValue(){
    int value = 0;
        
    if (rank == 'A'){
        value = 1;}
        
    else if (rank == '2'){
        value = 2;}

    else if (rank == '3'){
        value = 3;}

    else if (rank == '4'){
        value = 4;}

    else if (rank == '5'){
        value = 5;}

    else if (rank == '6'){
        value = 6;}

    else if (rank == '7'){
        value = 7;}

    else if (rank == '8'){
        value = 8;}

    else if (rank == '9'){
        value = 9;}

    else if (rank == 't'){
        value = 10;}

    else if (rank == 'J'){
        value = 10;}

    else if (rank == 'Q'){
        value = 10;}

    else if (rank == 'K'){
        value = 10;}
        
    return value;
}

//returns rank of card (1-10)
char Card::getRank(){
    return rank;
}
    
//returns suit of card (S,D,H,C)
char Card::getSuit(){
    return suit;
}

    


