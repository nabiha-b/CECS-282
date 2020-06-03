//
//  solitairePrime.cpp
//  SolitairePrime
//
//  Created by Nabiha Bashir on 2/6/20.
//  Copyright © 2020 Nabiha Bashir. All rights reserved.
//

#include "Card.hpp"
#include "Deck.hpp"
#include <iostream>
using namespace std;

int menu(){
    //display menu
    cout<<"Menu"<<endl;
    cout<<"1) New Deck"<<endl;
    cout<<"2) Display Deck"<<endl;
    cout<<"3) Shuffle Deck"<<endl;
    cout<<"4) Play Solitaire Prime"<<endl;
    cout<<"5) Exit"<<endl;
    
    //Get user input for menu selection
    int userChoice;
    cout<<" "<<endl;
    cout<<"Menu Selection: ";
    cin>>userChoice;
    return userChoice;
};

bool isPrime(int num){
    
    //'1' is not prime
    if (num == 1){
        return false;
    }
    for (int i = 2; i <= num/2; i++){
        if (num%i == 0){
            return false;
        }
    }
    return true;
};

static void solitarePrime(Deck newDeck){
    int sumValues = 0;
    int numPiles = 0;
    
    //use for loop to iterate over cards in storage
    for (int i = 0; i < 52; i++){
        //take top card
        Card C = newDeck.deal();
        //calculate sum
        sumValues += C.getValue();
        //display card
        C.display();
        
        //check if sum is prime
        if (isPrime(sumValues)){
            cout<<",Prime: "<<sumValues<<endl;;
            //restart sum
            sumValues = 0;
            numPiles++;
        }
    }
    
    //Declare win
    if(sumValues == 0){
        cout <<"\nWinner in "<<numPiles<<" piles! \n";
    }
    else{
    //Declare loss
    cout<<", Loser.\n";
    cout<<"\n";
    }
     
}

int main(){
    int userChoice;
    Deck newDeck;
    
    cout<<"Welcome to Solitaire Prime!"<<endl;
    
    do{
        
        userChoice = menu();
        
        if (userChoice == 1){
            cout<<"A new deck has been created.\n";
            newDeck = Deck();
        }
         
        else if (userChoice == 2){
            //display entire deck
            newDeck.display();
        }
        else if (userChoice == 3){
            newDeck.shuffle();
            cout<<"Deck has been shuffled.\n";
        }
        
        else if(userChoice == 4){
            cout<<"\n";
            cout<<"Solitaire Prime:\n";
            solitarePrime(newDeck);
        }
        else if(userChoice == 5){
            cout<< "You have chosen to exit the game. Goodbye! \n";
        }
    //if incorrect input, repeat the menu
        else{
            cout<<"Please select menu choices from 1-5.";
            menu();
         
        }
         }
             while (userChoice != 5);    
    return 0;
             
         };
         
   
    


