//
//  upDate.cpp
//  operatorOverloading
//
//  Created by Nabiha Bashir on 4/12/20.
//  Copyright © 2020 Nabiha Bashir. All rights reserved.
//

#include "upDate.hpp"
using namespace std;

//pass in month, day, year and return julian date
int Greg2Julian(int month, int day, int year){
    int I = year;
    int J = month;
    int K = day;
    int temp = K - 32075 + 1461 * (I + 4800 + (J-14)/12)/4+367*(J-2-(J-14)/12*12)/12-3*((I+4900+(J-14)/12)/100)/4;
    return temp;
}

//pass in Julian Date & get the correct month, day and year through the parameter list-pass by reference
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

//returns julian date
int upDate::julian(){
    int JD = Greg2Julian(dptr[0], dptr[1], dptr[2]);
    return JD;
}

//initialize the counter
int upDate::counter = 0;

//default constructor, sets date to default date May 11, 1959
upDate::upDate(){
    dptr = new int [3];
    dptr[0] = 5;
    dptr[1] = 11;
    dptr[2] = 1959;
    counter++;
}

//overloaded constructor; if any parameter is out of range, the date will be set to the default date May 11, 1959
upDate::upDate(int M, int D, int Y){
    // if any parameter is out of range, the date is set to the default date
    if (M > 12 || M < 0 || D > 31 || D < 0 ){
        dptr = new int [3];
        dptr[0] = 5;
        dptr[1] = 11;
        dptr[2] = 1959;
        counter++;
    }
    else{
        if (M == 2 && D > 29){
            dptr = new int [3];
            dptr[0] = 5;
            dptr[1] = 11;
            dptr[2] = 1959;
            counter++;

        }
        else if ((M == 4 || M == 6 || M == 9 || M == 11 ) && D > 30){
            dptr = new int [3];
            dptr[0] = 5;
            dptr[1] = 11;
            dptr[2] = 1959;
            counter++;

        }
        else{
            dptr = new int [3];
            dptr[0] = M;
            dptr[1] = D;
            dptr[2] = Y;
            counter++;
        }
    }
}

//contructor with julian date as parameter; if julian date is negative, the date will be set to the default date May 11, 1959
upDate::upDate(int J){
    if (J < 0){
        dptr = new int [3];
        dptr[0] = 5;
        dptr[1] = 11;
        dptr[2] = 1959;
        counter++;
    }
    else{
        int M1, D1, Y1;
        Julian2Greg(J, M1, D1, Y1);
        dptr = new int [3];
        dptr[0] = M1;
        dptr[1] = D1;
        dptr[2] = Y1;
        counter++;
    }
}

//copy constructor
upDate::upDate(upDate const &D){
    dptr = new int[3];
    dptr[0] = D.dptr[0];
    dptr[1] = D.dptr[1];
    dptr[2] = D.dptr[2];
    counter++;

}

//destructor
upDate::~upDate(){
    delete [] dptr;
    counter--;

}

//upDate setter
void upDate::setDate(int M, int D, int Y){
    dptr[0] = M;
    dptr[1] = D;
    dptr[2] = Y;
}

//returns the month
int upDate::getMonth(){
    return dptr[0];
}

//returns the day
int upDate::getDay(){
    return dptr[1];
}

//returns the year
int upDate::getYear(){
    return dptr[2];
}

//returns the name of the month
string upDate::getMonthName(){
    string monthName;
    if (getMonth() == 1){
        monthName = "Jan";
    }
    else if (getMonth() == 2){
        monthName = "Feb";
    }
    else if(getMonth() == 3){
        monthName = "Mar";
    }
    else if(getMonth() == 4){
        monthName = "Apr";
    }
    else if(getMonth() == 5){
        monthName = "May";
    }
    else if (getMonth() == 6){
        monthName = "Jun";
    }
    else if (getMonth() == 7){
        monthName = "Jul";
    }
    else if (getMonth() == 8){
        monthName = "Aug";
    }
    else if (getMonth() == 9){
        monthName = "Sep";
    }
    else if (getMonth() == 10){
        monthName = "Oct";
    }
    else if (getMonth() == 11){
        monthName = "Nov";
    }
    else if (getMonth() == 12){;
        monthName = "Dec";
    }
    return monthName;
}

//returns the number of upDate objects that exist
int upDate::GetDateCount(){
    return counter;
}

//------Operators------

//assignment operator
upDate upDate::operator=(upDate D){
    dptr[0] = D.dptr[0];
    dptr[1] = D.dptr[1];
    dptr[2] = D.dptr[2];
    return upDate(dptr[0], dptr[1], dptr[3]);
}

//+= operator
upDate upDate::operator+=(int x){
    int M1, D1, Y1;
    int JD = Greg2Julian(dptr[0], dptr[1], dptr[2]);
    JD += x;
    Julian2Greg(JD, M1, D1, Y1);
    
    dptr[0] = M1;
    dptr[1] = D1;
    dptr[2] = Y1;
    return upDate(dptr[0], dptr[1], dptr[3]);
}

//-= operator
upDate upDate::operator-=(int x){
    int M1, D1, Y1;
    int JD = Greg2Julian(dptr[0], dptr[1], dptr[2]);
    JD -= x;
    Julian2Greg(JD, M1, D1, Y1);
    
    dptr[0] = M1;
    dptr[1] = D1;
    dptr[2] = Y1;
    return upDate(dptr[0], dptr[1], dptr[3]);
}

//+ operator
upDate upDate::operator+(int x){
    int M1, D1, Y1;
    int JD = Greg2Julian(dptr[0], dptr[1], dptr[2]);
    JD += x;
    Julian2Greg(JD, M1, D1, Y1);
    upDate temp(M1, D1, Y1);
    return temp;
}

//non-member + operator
upDate operator+(int x, upDate D){
    int M1, D1, Y1;
    int JD = Greg2Julian(D.dptr[0], D.dptr[1], D.dptr[2]);
    JD += x;
    Julian2Greg(JD, M1, D1, Y1);
    upDate temp(M1, D1, Y1);
    return temp;
}

//- operator
upDate upDate::operator-(int x){
    int M1, D1, Y1;
    int JD = Greg2Julian(dptr[0], dptr[1], dptr[2]);
    JD -= x;
    Julian2Greg(JD, M1, D1, Y1);
    upDate temp(M1, D1, Y1);
    return temp;
}

//returns the number of days between two dates
int upDate::operator-(upDate D){
    //convert both dates to Julian dates
    int JD1 = Greg2Julian(dptr[0], dptr[1], dptr[2]);
    int JD2 = Greg2Julian(D.dptr[0], D.dptr[1], D.dptr[2]);
    
    //find difference between two julian dates
    int daysBetween = JD1 - JD2;
    
    return daysBetween;
}


//stream insertion operator
ostream & operator<<(ostream & cout, const upDate &D){
    return cout << D.dptr[0] << "/" << D.dptr[1] << "/" << D.dptr[2];
}


//postfix increment operator
upDate upDate::operator++(int){
    upDate temp(*this);
    
    //convert date to Julian & increment date
    int JD = this -> julian() + 1;
    
    //convert date back to Greg
    Julian2Greg(JD, dptr[0], dptr[1], dptr[2]);
    return temp;
}

//prefix increment operator
upDate upDate::operator++(){
    //convert date to Julian & increment date
    int JD = this -> julian() + 1;
    
    //convert date back to Greg
    int M1, D1, Y1;
    Julian2Greg(JD, M1, D1, Y1);
    upDate temp = upDate(M1, D1, Y1);
    return temp;
}

//postfix decrement operator
upDate upDate::operator--(int){
    upDate temp(*this);
    
    //convert date to Julian & decrement date
    int JD = this->julian() - 1;
    
    //convert date back to Greg
    Julian2Greg(JD, dptr[0], dptr[1], dptr[2]);
    return temp;
}

//prefix decrement operator
upDate upDate::operator--(){
    //convert date to Julian & decrement date
    int JD = this -> julian() - 1;
    
    //convert date back to Greg
    int M1, D1, Y1;
    Julian2Greg(JD, M1, D1, Y1);
    upDate temp = upDate(M1, D1, Y1);
    return temp;
}

//returns true if both dates are equal
bool upDate::operator==(upDate D){
    //convert both dates to julian
    int JD1 = Greg2Julian(dptr[0], dptr[1], dptr[2]);
    int JD2 = Greg2Julian(D.dptr[0], D.dptr[1], D.dptr[2]);
    
    //compare both julian dates
    if (JD1 == JD2){
        return true;
    }
    else {
        return false;
    }
}

//returns true if the date is less than the date passed in the parameter
bool upDate::operator<(upDate D){
    //convert both dates to julian
    int JD1 = Greg2Julian(dptr[0], dptr[1], dptr[2]);
    int JD2 = Greg2Julian(D.dptr[0], D.dptr[1], D.dptr[2]);
    
    //compare both julian dates
    if (JD1 < JD2){
        return true;
    }
    else {
        return false;
    }
}

//returns true if the date is greater than the date passed in the parameter
bool upDate::operator>(upDate D){
    //convert both dates to julian
    int JD1 = Greg2Julian(dptr[0], dptr[1], dptr[2]);
    int JD2 = Greg2Julian(D.dptr[0], D.dptr[1], D.dptr[2]);
    
    //compare both julian dates
    if (JD1 > JD2){
        return true;
    }
    else {
        return false;
    }
}




