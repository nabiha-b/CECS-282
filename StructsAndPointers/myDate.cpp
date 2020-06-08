//
//  myDate.cpp
//  structuresAndPointers
//
//  Created by Nabiha Bashir on 3/10/20.
//  Copyright © 2020 Nabiha Bashir. All rights reserved.
//

#include "myDate.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

//pass in Month, Day, Year and return Julian number
int Greg2Julian(int month, int day, int year){
    int I = year;
    int J = month;
    int K = day;
    int temp = K - 32075 + 1461 * (I + 4800 + (J-14)/12)/4+367*(J-2-(J-14)/12*12)/12-3*((I+4900+(J-14)/12)/100)/4;
    return temp;
}

//pass in Julian Date & get the correct Month, Day and Year through the parameter list-pass by reference
void Julian2Greg(int JD, int &month, int &day, int &year){
    
    int L = JD + 68569;
    int N = 4 * L / 146097;
    L = L - (146097 * N + 3)/4;
    int I = 4000 * (L+1)/1461001;
    L = L - 1461 * I / 4 + 31;
    int J = 80 * L/2447;
    int K = L - 2447 * J / 80;
    L = J / 11;
    J = J + 2 - 12 * L;
    I = 100 * (N - 49) + I + L;
    
    year = I;
    month = J;
    day = K;
    
}

int myDate::Greg2Julian(int month, int day, int year){
    int I = year;
    int J = month;
    int K = day;
    int temp = K - 32075 + 1461 * (I + 4800 + (J-14)/12)/4+367*(J-2-(J-14)/12*12)/12-3*((I+4900+(J-14)/12)/100)/4;
    return temp;
}

//default constructor
myDate::myDate(){
    month = 5;
    day = 11;
    year = 1959;
    monthName = "May";
    theDate = "May 11, 1959";
}

//overloaded constructor
myDate::myDate(int M, int D, int Y){
    if (M > 12 || M < 1 || D > 31 || D < 1 || Y < 1){
        month = 5;
        day = 11;
        year = 1959;
        monthName = "May";
    }
    else {
        if (M == 2 && D > 29){
            month = 5;
            day = 11;
            year = 1959;
            monthName = "May";
        }
        else if ((M == 4 || M == 6 || M == 9 || M == 11 ) && D > 30){
            month = 5;
            day = 11;
            year = 1959;
            monthName = "May";
        }
        
        else{
        
        month = M;
        day = D;
        year = Y;
        }
    }
    
}

//display date in format: May 11, 1959
void myDate::display(){
    if (month == 1){
        monthName = "Jan";
    }
    else if (month == 2){
        monthName = "Feb";
    }
    else if(month == 3){
        monthName = "Mar";
    }
    else if(month == 4){
        monthName = "Apr";
    }
    else if(month == 5){
        monthName = "May";
    }
    else if (month == 6){
        monthName = "Jun";
    }
    else if (month == 7){
        monthName = "Jul";
    }
    else if (month == 8){
        monthName = "Aug";
    }
    else if (month == 9){
        monthName = "Sep";
    }
    else if (month == 10){
        monthName = "Oct";
    }
    else if (month == 11){
        monthName = "Nov";
    }
    else if (month == 12){
        monthName = "Dec";
    }
    else{
        monthName = "xxx";
        
    }
    
    cout<<monthName<<" "<<setw(2)<<day<<", "<<setw(12)<<year;
}

//increment date by N days
void myDate::increaseDate(int N){
    //returns Julian day
    int JD = Greg2Julian(month, day, year);
    JD += N;
    Julian2Greg(JD, month, day, year);

}

//decrement date by N days
void myDate::decreaseDate(int M){
    int JD = Greg2Julian(month, day, year);
    JD = JD - M;
    Julian2Greg(JD, month, day, year);
}

//return the number of days between this date and the date D
int myDate::daysBetween(myDate D){
    //Get julian date for the first date
    int JD1 = Greg2Julian(month, day, year);
    //Get julian date for date comparing to
    int JD2 = Greg2Julian(D.month, D.day, D.year);
    
    //positive = future date, negative = past date
    int daysBetween = JD2 - JD1;
    
    return daysBetween;
}

//return the month in integer form
int myDate::getMonth(){
    return month;
}

//return the day of the month
int myDate::getDay(){
    return day;
}

//return the year
int myDate::getYear(){
    return year;
}


//return the number of days since the current year began
int myDate::dayOfYear(){
    //get current date JD
    int JD = Greg2Julian(month, day, year);
    //get beginning of current year's JD
    int beginningJD = Greg2Julian(1, 0, year);
    
    //find difference between the two dates
    int dayOfYear = JD - beginningJD;
    
    return dayOfYear;
    
}

//returns full name of the day of the weel
string myDate::dayName(){
    int JD = Greg2Julian(month, day, year);
    int mod = JD%7;
    string day;
    
    if (mod == 0){
        day = "Monday";
    }
    else if (mod == 1){
        day = "Tuesday";
    }
    else if (mod == 2){
        day = "Wednesday";
    }
    else if (mod == 3){
        day = "Thursday";
    }
    else if (mod == 4){
        day = "Friday";
    }
    else if (mod == 5){
        day = "Saturday";
    }
    else if (mod == 6){
        day = "Sunday";
    }
    return day;
}

