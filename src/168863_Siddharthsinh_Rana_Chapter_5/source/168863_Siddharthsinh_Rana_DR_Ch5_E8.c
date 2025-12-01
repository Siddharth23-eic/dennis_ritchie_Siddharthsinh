/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 29/10/2025
 * Chapter: 5
 * Exercise: 5.8
 * Description: There is no error checking in day_of_year or month_day. Remedy this defect.
 */

#include <stdio.h>
#include <stdint.h>
#include "chapter5func.h"

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

/* day_of_year: convert month/day into day of year */
int32_t day_of_year(int32_t year, int32_t month, int32_t day){
    int32_t i, leap;

    if (year <= 0){
        printf("Invalid year(Year must be positive)\n");
        return -1;
    }

    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    if (month < 1 || month > 12){
        printf("Invalid month.(Enter between 1 to 12 only)\n");
        return -1;
    }

    if (day < 1 || day > daytab[leap][month]){
        printf("Invalid day(Enter according to month of leap or non-leap)\n");
        return -1;
    }

    for (i = 1; i < month; i++)
        day += daytab[leap][i];

    return day;
}

/* month_day: convert day of year into month/day */
void month_day(int32_t year, int32_t yearday, int32_t *pmonth, int32_t *pday){
    int32_t i, leap;

    if (year <= 0){
        printf("Invalid year.(Year must be positive)\n");
        *pmonth = -1;
        *pday = -1;
        return;
    }

    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    if((leap && (yearday < 1 || yearday > 366)) || (!leap && (yearday < 1 || yearday > 365))){
        printf("Invalid yearday.(enter between 1 to (365 for non-leap and 366 for leap year)\n");
        *pmonth = -1;
        *pday = -1;
        return;
    }

    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];

    *pmonth = i;
    *pday = yearday;
}

int32_t exercise5_8(){
    int32_t choice;
    printf("\nChoose operation:\n 1. day_of_year\n 2. month_day\n");
    if (scanf("%d", &choice) != 1)
        return 1;

    switch (choice){
    case 1:{
        int32_t year, month, day;
        printf("Enter date (year month day): ");
        scanf("%d %d %d", &year, &month, &day);
        int32_t yearday = day_of_year(year, month, day);
        if (yearday != -1)
            printf("Day of year: %d\n", yearday);
        break;
    }

    case 2:{
        int32_t year, yearday, month, day;
        printf("Enter (year yearday): ");
        scanf("%d %d", &year, &yearday);
        month_day(year, yearday, &month, &day);
        if (month != -1 && day != -1)
            printf("Month: %d, Day: %d\n", month, day);
        break;
    }

    default:
        printf("Invalid choice.\n");
    }
    return 0;
}
