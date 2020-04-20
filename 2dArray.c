#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int day, int yearday, int *pmonth, int *pday);
int day_of_year_pointer(int year,int month, int day);
void month_day_pointer(int year, int yearday, int *pmonth, int *pday);


struct Date
{
    int year;
    int month;
    int day;
};

int main()
{
    struct Date date;
    date.year = 1999;
    date.day = 178;
    
    int *pmonth = &date.month;
    int *pday = &date.day;

    month_day_pointer(date.year, date.day, pmonth, pday);

    printf("month: %d \t day: %d\n", *pmonth, *pday);
    printf("day of year: %d\n", day_of_year_pointer(date.year, date.month, date.day));
}

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

/* pointer versions */

int day_of_year_pointer(int year,int month, int day)
{
    int i, leap;
    char *p;

    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
    p = &daytab[leap][1];

    for (i = 1; i < month; i++)
        day += *p++;
    return day;
}

void month_day_pointer(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    char *p;

    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
    p = &daytab[leap][1];
    for (i = 1; yearday > *p; i++)
        yearday -= *p++;
    
    *pmonth = i;
    *pday = yearday;
}
