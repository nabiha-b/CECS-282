//
//  myDate.hpp
//  myDate
//
//  Created by Nabiha Bashir on 2/19/20.
//  Copyright © 2020 Nabiha Bashir. All rights reserved.
//

#ifndef myDate_hpp
#define myDate_hpp
#include <iostream>
using namespace std;

class myDate{
    
private:
    int month;
    int day;
    int year;
    string monthName;
    string theDate;

    
    
public:
    myDate();
    myDate(int M, int D, int Y);
    void display();
    void increaseDate(int N);
    void decreaseDate(int M);
    int daysBetween(myDate D);
    int getMonth();
    int getDay();
    int getYear();
    int dayOfYear();
    string dayName();
    
};


#endif /* myDate_hpp */
