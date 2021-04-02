/*
ID: ltjosh22
LANG: C++
TASK: friday
*/
#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");

    int years;
    fin >> years; int lastYear = 1900 + years - 1;

    int monthDays [] = {31,28,31,30,31,30,31,31,30,31,30,31}; // jan to dec

    int day = 2;
    int day13Count[7] = {}; // sat -> fri (for final count)

    int yearCountForLeap = 0; bool leapYear = false;

    for (int year = 1900; year <= lastYear; year++) // years
    {
        if (yearCountForLeap == 4) // if leap year, reset count and adjust calculations
        {
            yearCountForLeap = 0;
            leapYear = true;

            if ((year % 400 != 0) && (year % 100 == 0)) // if year is not divisible by 400 and is a century, is not a leap
            {
                leapYear = false;
            }
        }
        else
        {
            leapYear = false;
        }




        for (int month = 0; month < 12; month++) // goes through months
        {
            if ((month == 1) && (leapYear == true)) // if leap year and feburary
            {
                for (int currentDay = 1; currentDay <= monthDays[month]+1; currentDay++) // goes through days in leap feb
                {
                    if (currentDay == 13)
                    {
                        day13Count[day]++;
                    }

                    day = (day + 1) % 7; // advances day
                }
            }

            else
            {
                for (int currentDay = 1; currentDay <= monthDays[month]; currentDay++) // goes through days in month
                {
                    if (currentDay == 13)
                    {
                        day13Count[day]++;
                    }

                    day = (day + 1) % 7; // advances day
                }
            }
        }
        yearCountForLeap++;
    }

    for (int i = 0; i < 7; i++)
    {
        if (i != 6)
        {
            fout << day13Count[i] << " ";
        }

        if (i == 6)
        {
            fout << day13Count[i] << endl;
        }
    }
}