#pragma once
class Date
    {
    private:
        unsigned short _day;
        unsigned short _month;
        int _year;
        bool isLeapYear(int year)const;
        bool isValid();
        int dayOfYear()const;
        int monthDays(int month, int year)const;        
    public:
        Date(unsigned short day, unsigned short month, int year);
        ~Date(void);
        int operator- (const Date& other);
        Date operator- (int );
        bool operator< (const Date& other);
        bool operator> (const Date& other);
    };

