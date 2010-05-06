#include "Date.h"


Date::Date(unsigned short day = 1 , unsigned short month = 1, int year = 2000): _day(day), _month(month), _year(year){
    if(!isValid()) throw "Date isn`t valid";
}


Date::~Date(void){
}

bool Date::isValid()
{
    if(_month < 1 || _month > 12) return false;
    short d;
    switch(_month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            d = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            d = 30;
            break;
        case 2:
            if(isLeapYear(_year)) d=29;
            else d=28;
    }
    if(_day < 1 || _day > d) return false;
    return true;
}

bool Date::isLeapYear(int year)const{
    if ((year % 400 == 0) || ( (year % 4 == 0) && (year % 100 != 0) ))
        return true;
    return false;
}

int Date::operator- (const Date& other){
    int counter = 0;
    int year = other._year;
    int z = 1;
    if(_year < other._year) z = -1;

    while(year!=_year){
        if(isLeapYear(year+= z)) counter+=366;
        else counter+=365;
    }
    counter += dayOfYear()*z;
    counter -= other.dayOfYear()*z;
    return counter*z;
}

bool Date::operator< (const Date& other){
    if(_year * 10000 + _month * 100 + _day < other._year * 10000 + other._month * 100 + other._day) return true;
    return false;
}

bool Date::operator> (const Date& other){
    if(_year * 10000 + _month * 100 + _day > other._year * 10000 + other._month * 100 + other._day) return true;
    return false;
}

int Date::dayOfYear()const{
    int day = 0;
    for(int i = 1; i < _month; i++){
        switch(i){
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                day += 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                day += 30;
                break;
            case 2:
                if(isLeapYear(_year)) day += 29;
                else day += 28;            
        }
       
    }
    return _day + day;
}