//
//  upDate.hpp
//  operatorOverloading
//
//  Created by Nabiha Bashir on 4/12/20.
//  Copyright © 2020 Nabiha Bashir. All rights reserved.
//

#ifndef upDate_hpp
#define upDate_hpp
#include <iostream>
#include <stdio.h>
using namespace std;


class upDate{
private:
    int *dptr; //pointer that points to an integer array where month, day, year will be stored
    static int counter;
        
public:
    upDate();
    upDate(int M, int D, int Y);
    upDate(int J);
    upDate(upDate const &D); //copy constructor
    ~upDate(); //destructor
    void setDate(int M, int D, int Y); //upDate setter
    int getMonth();
    int getDay();
    int getYear();
    string getMonthName();
    int static GetDateCount();
    int julian();
    upDate operator=(upDate); //assignment operator
    upDate operator+=(int);
    upDate operator-=(int);
    upDate operator+(int);
    friend upDate operator+(int, upDate); //this is a non-member method which will have access to upDate's private methods and variables
    upDate operator-(int);
    int operator-(upDate);
    //returns the number of upDate objects that currently exist
  
    //stream insertion operator
    friend ostream &operator<<(ostream & cout, const upDate&);
        
    //postfix increment operator
    upDate operator++(int);
    
    //prefix increment operator
    upDate operator++();

    //postfix decrement operator
    upDate operator--(int);
    
    //prefix decrement operator
    upDate operator--();
    
    //comparison operators
    bool operator==(upDate);
    bool operator<(upDate);
    bool operator>(upDate);

};

#endif /* upDate_hpp */
