//
//  main.cpp
//  goldRabbits
//
//  Created by Nabiha Bashir on 4/23/20.
//  Copyright © 2020 Nabiha Bashir. All rights reserved.
//

#include <iostream>
#include <vector>
#include <time.h>
#include <iterator>
#include <iomanip>
#include <map>
using namespace std;


class BigInt{
private:
    //to store digits/chars of BigInt
    vector<char> v;
    
public:
    //constructors
    BigInt();
    BigInt(int);
    BigInt(string);
    
    //overloading operators
    bool operator <(const BigInt &) const;
    bool operator ==(const BigInt &) const;
    bool operator ==(int);
    bool operator<=(const BigInt &) const;
    bool operator<=(int);
    BigInt operator++(int);
    BigInt operator+(BigInt) ;
    BigInt operator+(int);
    BigInt operator-(BigInt) ;
    BigInt operator-(int);
    
    friend ostream & operator << (ostream &, BigInt );
    void print();
};

BigInt goldRabbits(BigInt);
void pause();


int main() {
    BigInt B1("123456789123456789123456789123456789");
    BigInt B2(B1);
    BigInt MAX(INT_MAX);
    cout << "B1: " << B1 << "\nB2:" << B2 << "\nMAX: " << MAX << endl;
    pause();
    cout << "\nB1:";
    B1.print();
    cout << endl;
    pause();
    
    for(BigInt i=0 ; i <= 3000; i++){  //uncomment this
    //for(int i = 0; i <= 3000; i++) {     // comment this
        cout  <<"\ngoldRabbits(" << i << ") = " << goldRabbits(i);
    }
    pause();
    
    cout <<  "\nThis is the value of goldRabbits(3000)\n\n";
    BigInt gR3000 =  goldRabbits(BigInt(3000));
    gR3000.print();
    
    pause();
}

//default constructor
BigInt::BigInt(){
    v.push_back(0);
}

//constructor with int as parameter
BigInt::BigInt(int n){
    while (n/10 >= 1){
        int digit = n % 10;
        v.push_back(digit);
        n = n/10;
    }
    v.push_back(n);
}

//constructor with string as parameter
BigInt::BigInt(string n){
    for (int i = (int)n.length() - 1; i >= 0; i--){
        int digit = (n[i]);
        v.push_back(digit-'0');
    }
}

bool BigInt::operator < ( const BigInt &N) const{
    bool result = false;
    
    //if the first number is less than second, return true
    if (v.size() < N.v.size()){
        result = true;
    }
    //else, return false
    else if (v.size() > N.v.size()){
        result = false;
    }
    //if they are the same, return false
    else if (*this == N){
        return false;
    }
    else{
    //if they're the same length, compare first digit
    for (int i = (int)v.size() - 1; i > -1 ; i--){
        if (v[i] < N.v[i]){
            return true;
        }
        else if (v[i] > N.v[i]){
            return false;
        }
    }
    }
    return result;
}

//returns true if both BigInts are equal
bool BigInt::operator == (const BigInt &N) const {
    bool result = false;
    int length = (int)(v.size());
    
    if(v.size() == N.v.size()){
            //compare the numbers at each index
            for (int i = 0; i < length; i++){
            if (v[i] == N.v[i]) {
                result = true;
            }
            else{
                result = false;
                break;
            }
        }
    }
        return result;
}

bool BigInt::operator == (int n){
    BigInt N = BigInt(n);
    return (*this) == N;
}

bool BigInt::operator<=( const BigInt &N) const
{
    bool result = ((*this) == N || (*this) < N);
    return result;
}

bool BigInt::operator<=(int n){
    return (*this) <= (BigInt(n));
}

//operator that increments a BigInt
BigInt BigInt::operator++(int n){
    BigInt N = *this;
    *this = *this + 1;
    return N;
}

//the + operator with an BigInt in parameter
BigInt BigInt::operator+(BigInt N)  {
    BigInt result;
    BigInt top, bottom;
    int carry = 0;
    
    //determine which number goes on top and bottom
    if (v.size() > N.v.size()){
        top = (*this);
        bottom = N;
    }
    else{
        top = N;
        bottom = (*this);
    }
    //insert zeros to the top/bottom number when necessary
    while (top.v.size() != bottom.v.size()){
        bottom.v.push_back(0);
    }
    //now make result the same size as top
    while (result.v.size() != bottom.v.size()){
        result.v.push_back(0);}
    
    for (int i = 0; i < (int)top.v.size(); i++){
        //now add them
        int sumDigit = top.v[i] + bottom.v[i] + carry;
        //if sum is greater than or = to 10, use a carry
        if (sumDigit >= 10){
            carry = 1;
            result.v[i] = sumDigit%10;
        }
        else{
            result.v[i] = sumDigit;
            carry = 0;
        }}
        //add remaining carry if neccessary
        if (carry == 1){
            result.v.push_back(1);}
    return result;
    

}

//the + operator with an int in parameter
BigInt BigInt::operator+(int n){
    BigInt N = BigInt(n);
    return (*this) + N;

}

//the - operator with a BigInt in parameter
BigInt BigInt::operator-(BigInt N)  {
     BigInt top = (*this);
     BigInt bottom = N;
     BigInt difference = top; //we will edit this to store the difference
     int carry = 0;

     
     //insert zeros to the bottom number when necessary
     while (top.v.size() > bottom.v.size()){
         bottom.v.push_back(0);
     }
     
     for (int i = 0; i < top.v.size() ; i++){
     //if top number is smaller than bottom, use carry to subtract
     if (top.v[i] < bottom.v[i]){
         //add ten to the number that borrowed from carry
         top.v[i] = top.v[i] + 10;
         carry = 1;
         //subtract 1 from the number from which carry was taken
         top.v[i + 1] = top.v[i + 1] - carry;
     }
         //now subtract
         difference.v[i] = top.v[i] - bottom.v[i];

         //if both numbers are 0 at the end, you remove the zero from the result also
         if (top.v[i] == 0 && bottom.v[i] == 0 && i == top.v.size() -1){
             difference.v.erase(difference.v.end() -1);
         }
         }
     return difference;

}

//the - operator with an int in parameter
BigInt BigInt::operator-(int n){
    BigInt N = BigInt(n);
    return (*this) - N;
}

//displays the BigInt in scientific notation if it has more that 12 digits
ostream & operator<<(ostream & cout, BigInt  N){
    int length = (int)N.v.size();
    if (length > 12)
    {
        //in reverse order, iterate through the BigInt vector
        for (int i = length - 1; i >= length - 11; i--)
    {
        //convert digit to int
        int digit = (int)(N.v[i])  ;
        
        cout << (digit);
        //after the first digit, place a decimal point
        if (i == length - 1)
        {
            cout << ".";
        }
    }
    cout << "e" << length;
    }
    //if the number has less than 12 digits, print all of its digits
    else
    {
    N.print();
    }
    return cout;
}

//this will display all digits in the BigInt
void BigInt::print() {
    vector<char>::reverse_iterator rit;
    for(rit = v.rbegin(); rit != v.rend(); rit++){
        cout << int(*rit) ;
    }
}

BigInt goldRabbits(BigInt n){
    static map<BigInt, BigInt> myMap;
    
    if (n == 0 || n == 1){
        myMap.insert({n,BigInt(1)});
    }
    else{
        BigInt sum = myMap[n-1] + myMap[n-2];
        myMap.insert({n,sum});
    }
    return myMap[n];

}

void pause(){
    cout << "Press Enter to continue..."; getchar() ;
}
