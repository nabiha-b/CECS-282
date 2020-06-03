//
//  main.cpp
//  structuresAndPointers
//
//  Created by Nabiha Bashir on 3/10/20.
//  Copyright © 2020 Nabiha Bashir. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "myDate.hpp"
#include <cstdio>


//displays menu
string menu(){
    string menu = "";
    menu += "1) Display list sorted by Name\n";
    menu += "2) Display list sorted by Student ID\n";
    menu += "3) Display list sorted by Grade\n";
    menu += "4) Display list sorted by Birthday\n";
    menu += "5) Display list sorted Home Town\n";
    menu += "6) Exit\n";
    
    return menu;
}

//student structure
struct student{
    //string name;
    char name[20];
    int SID ;
    char grade;
    myDate bday;
    string homeTown;
};
    
//swap method for sorting
void swap(student **A, student **B){
    student *temp;
    temp = *A;
    *A = *B;
    *B = temp;
}

//sort by name
void sortByName(student *theNames[]){
    for (int i = 0; i < 10; i++){
        for (int j = 1; j < 10 - i; j++){
            if (strcmp (&*theNames[j]->name, &*theNames[j+1]->name) > 0){
                swap(&theNames[j], &theNames[j+1]);
            }
        }
    }
}

//sort by SID
void sortBySID(student *theSIDs[]){
    for (int i = 0; i < 10; i++){
        for (int j = 1; j < 10 - i; j++){
            if (theSIDs[j]->SID > theSIDs[j+1]->SID) {
                swap(&theSIDs[j], &theSIDs[j+1]);
            }
        }
    }
}

//sort by grade
void sortByGrade(student *theGrades[]){
    for (int i = 0; i < 10; i++){
        for (int j = 1; j < 10 - i; j++){
            if (theGrades[j]->grade > theGrades[j+1]->grade) {
                swap(&theGrades[j], &theGrades[j+1]);
            }
        }
    }
}

//sort by bday
void sortByBday(student *theBdays[]){
    for (int i = 0; i < 10; i++){
        for (int j = 1; j < 10 - i; j++){
            int month1 = theBdays[j]->bday.getMonth();
            int day1 = theBdays[j]->bday.getDay();
            int year1 = theBdays[j]->bday.getYear();
            int month2 = theBdays[j + 1]->bday.getMonth();
            int day2 = theBdays[j + 1]->bday.getDay();
            int year2 = theBdays[j + 1]->bday.getYear();
            
            if (theBdays[j]->bday.Greg2Julian(month1, day1, year1) > theBdays[j]->bday.Greg2Julian(month2, day2, year2)){
                swap(theBdays[j], theBdays[j+1]);
            }
            
        }
    }
}

//sort by home town
void sortByHometown(student *theHometowns[]){
    for (int i = 0; i < 10; i++){
        for (int j = 1; j < 10 - i; j++){
            if (theHometowns[j]->homeTown.compare(theHometowns[j+1]->homeTown) > 0) {
                swap(&theHometowns[j], &theHometowns[j+1]);
            }
        }
    }
}
//returns a date between a range of 2 dates
myDate dateBetween(myDate date1, myDate date2){
    int range = date1.daysBetween(date2);
    int x = rand()%range;
    myDate D = date1;
    date1.increaseDate(x);
    return date1;
}

int randomSID(){
    int SID = (rand()% (9999 - 1000 + 1)) + 1000;
    return SID;
}


//populates an array of pointers to students with 10 students
void populate(student *A[]){
    string names[10] = {"Sponge Bob", "Fred Flinstone", "Tom Thumb", "Johnny Bravo", "Johnny Test", "Shaggy Rogers", "Timmy Turner", "Phineas Flynn", "Arthur Read", "Bonnie Rockwaller"};
    char grades[5] = {'A', 'B', 'C', 'D', 'F'};
    string homeTowns[10] = {"Bikini Bottom", "Bedrock", "Small Ville", "Aron City", "Porkbelly", "Coolsville", "Dimmsdale", "Danville", "Elwood City", "Middleton"};

for (int i = 0; i < 11; i++){
    A[i+1] = new student;
    strcpy(A[i+1]->name, names[i].c_str());
    A[i+1]->SID = randomSID();
    A[i+1]->homeTown = homeTowns[i];
    A[i+1]->bday = dateBetween(myDate(1,1,1999), myDate(12,31,2004));
    A[i+1]->grade = grades[(rand()%5)];
}
}


//neatly displays students
void display(student *X[]){
    
    cout<<left<<setw(19)<<"Name"<<setw(19)<<"Student ID"<<setw(19)<<"Grade"<<setw(24)<<"Birthday"<<setw(19)<<"Home Town"<<endl;

    
    
    for (int i = 0; i < 10; i++){
        cout<<setw(19)<< X[i+1]->name<<setw(19)<<X[i+1]->SID<<setw(19)<<X[i+1]->grade;
        X[i+1]->bday.display();
        cout<<X[i+1]->homeTown.c_str()<<endl;
    }

}

int main() {
    //create an array of pointers to students of size 10
    student *S[11];
    
    //add students to array
       populate(S);
    
    //create arrays to sort by different features
    student *Name[11];
    student *SID[11];
    student *Grade[11];
    student *Hometown[11];
    student *Birthday[11];
    //copy data of S array to new arrays
    for(int i = 0; i < 11; i++){
        Name[i] = &*S[i];
        SID[i] = &*S[i];
        Grade[i] = &*S[i];
        Hometown[i] = &*S[i];
        Birthday[i] = &*S[i];
    }
    
    
    //display menu
    cout<< menu()<<endl;
    int userChoice;
    cin>>userChoice;
    
    do{
        
        if (userChoice == 0){
            display(S);
        }
        else if (userChoice == 1){
            sortByName(Name);
            display(Name);
        }
        else if (userChoice == 2){
            sortBySID(SID);
            display(SID);
                
            }
        else if (userChoice == 3){
            sortByGrade(Grade);
            display(Grade);
        }
        else if (userChoice == 4){
            sortByBday(Birthday);
            display(Birthday);
        }
        else if (userChoice == 5){
            sortByHometown(Hometown);
            display(Hometown);
        }
        
        cout<<endl;
        cout<< menu()<<endl;
        cin>>userChoice;
    }
    
    while(userChoice!=6);
    
    
}
