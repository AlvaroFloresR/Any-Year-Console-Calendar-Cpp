/*  Custom Calendar Application
            By: Alvaro Flores-Romero
    C++ 20
    Developed in VsCode
*/

#include <iostream>
#include<string>
#include<cmath>
#include <iomanip>
#include<time.h>

int weakDayOfYearBegin(int year)
{
    std::tm t {};
    t.tm_year = year - 1900;
    t.tm_mday = 1;
    std::mktime(&t);
    if(t.tm_wday == 0)
    {
        return 7;
    }
    else
    {
        return t.tm_wday;
    }

}

bool is_leap_year(int year)
{
    // leap year if perfectly divisible by 400
    if (year % 400 == 0) {
        return true;
    }
    // not a leap year if divisible by 100
    // but not divisible by 400
    else if (year % 100 == 0) {
        return false;
    }
    // leap year if not divisible by 100
    // but divisible by 4
    else if (year % 4 == 0) {
        return true;
    }
    // all other years are not leap years
    else {
        return false;
    }

}

int creat_montly_calendar(std::string month, int year, int number_days, int starting_day)
{   
    // Get Day offset based on desired starting day
    int day_offset;
    if(starting_day > 7)
    {
        day_offset = 0;
    }
    else{
        day_offset = starting_day - 1;
    }

    std::cout << "--"<<month<<" "<< year <<"--"<< "\n";

    // Print Week Header
    std::string myNumbers[7] = {"Mon", "Tue", "Wed","Thu" , "Fri","Sat","Sun"};
    for (std::string i : myNumbers)
    {
        std::cout << std::setw(5) << i;
    }
    std::cout << "\n";

    // Print Days
    int current_weekday_number{1};
    //std::cout << std::setw(5) << current_weekday_number;
    for(size_t k{0}; k < (number_days + day_offset);k++)
    {   
        // We Skip Offset Days first Writing Blank
        if(k<day_offset)
        {
            std::cout << std::setw(5) << ' ';
            current_weekday_number++;
            continue;
        }

        if(current_weekday_number <= 7)
        {
            std::cout << std::setw(5) << k + 1 - day_offset;
            current_weekday_number++;
        }
        else
        {
            std::cout << "\n";
            current_weekday_number = 1;
            k--;
        }
    }
    std::cout << "\n\n";
    return current_weekday_number;
}

int main()
{
    // Variable Declaration
    unsigned short year;
    int weekDay;
    
    std::cout << "Enter a year: \n"; 
    std::cin >> year;

    weekDay =  weakDayOfYearBegin(year); // Monday is 1
    bool isLeapYear = is_leap_year(year);

    weekDay = creat_montly_calendar("January",year, 31, weekDay);

    if(isLeapYear == true)
    {
        weekDay = creat_montly_calendar("February",year, 29, weekDay);
    }
    else if(isLeapYear == false)
    {
        weekDay = creat_montly_calendar("February",year, 28, weekDay);
    }
    
    weekDay = creat_montly_calendar("March",year, 31, weekDay);
    weekDay = creat_montly_calendar("April",year, 30, weekDay);
    weekDay = creat_montly_calendar("May",year, 31, weekDay);
    weekDay = creat_montly_calendar("June",year, 30, weekDay);
    weekDay = creat_montly_calendar("July",year, 31, weekDay);
    weekDay = creat_montly_calendar("August",year, 31, weekDay);
    weekDay = creat_montly_calendar("September",year, 30, weekDay);
    weekDay = creat_montly_calendar("October",year, 31, weekDay);
    weekDay = creat_montly_calendar("November",year, 30, weekDay);
    weekDay = creat_montly_calendar("December",year, 31, weekDay);

    system("pause");

    return 0;
}