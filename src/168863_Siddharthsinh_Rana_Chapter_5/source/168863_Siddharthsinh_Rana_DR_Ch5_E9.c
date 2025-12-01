/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 29/10/2025
 * Chapter: 5
 * Exercise: 5.9
 * Description: Rewrite the routines day_of_year and month_day with pointers instead of indexing.
 */

#include <stdio.h>
#include <stdint.h>
#include "chapter5func.h"

char daytab[2][13] = {
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};


int32_t day_of_year_9(int32_t year, int32_t month, int32_t day){
    int32_t leap;
    char *p;
    if (year <= 0) {
        printf("Enter positive year only \n");
        return -1;
    }

    leap = (year%4 == 0 && year%100 != 0) || (year%400 == 0);
    
    /* Invalid Month */
    if(month < 1 || month > 12){
        printf("Invalid month(Must be between 1 & 12) \n");
        return -1;
    }

    /* Invalid Day */
    if(day < 1 || day > *(daytab + leap*13 + month)){
        printf("Enter day between 1 and (365 for non leap and 366 for leap year) \n");
        return -1;
    }

    p = *(daytab + leap);
    for(int32_t i = 1; i < month; i++){
        day += *(p + i);
    }
    return day;
}

void month_day_9(int32_t year, int32_t yearday, int32_t *pmonth, int32_t *pday){
    int32_t leap;
    char *p;

    if(year <= 0){
        printf("Enter Positive year only \n");
        *pmonth = -1;
        *pday = -1;
        return;
    }

    leap = (year%4 == 0 && year%100 != 0) || (year%400 == 0);

    /* Invalid Yearday */
    if((leap && (yearday < 1 || yearday > 366)) || (!leap && (yearday < 1 || yearday > 365))){
        printf("Enter yearday between 1 and (365 for non leap and 366 for leap year) \n");
        *pmonth = -1;
        *pday = -1;
        return;
    }

    p = *(daytab + leap);
    for(int32_t i = 1; yearday > *(p + i); i++){
        yearday -= *(p + i);
        *pmonth = i + 1;
    }
    *pday = yearday;
}

int32_t exercise5_9(){
    int32_t choice;
    printf("Choose operation:\n 1. day_of_year\n 2. month_day\n> ");
    scanf("%d", &choice);
    switch(choice){
        case 1:{
            int32_t year, month, day;
            printf("Enter date in this format (year month day)");
            scanf("%d %d %d", &year, &month, &day);

            int32_t yearday = day_of_year_9(year, month, day);
            if(yearday != -1)
                printf("day of year is  -> %d \n", yearday);
            
            break;
        }

        case 2:{
            int32_t year, yearday, month = 0, day = 0;
            printf("Enter year and yearday.\n");
            scanf("%d %d", &year, &yearday);
            month_day_9(year, yearday, &month, &day);

            if(month != -1 && day != -1)
                printf("Month -> %d Day -> %d \n", month, day);
            
            break;
        }

        default:
            printf("Invalid Choice! \n");
    }
    return 0;
}
