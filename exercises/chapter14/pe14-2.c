/* pe14-2.c -- days count */
#include <stdio.h>

struct month {
 char name[10];
 char abbrev[4];
 int days;
 int monumb;
};

struct month months[12] =
{
 {"January", "jan", 31, 1},
 {"February", "feb", 28, 2},
 {"March", "mar", 31, 3},
 {"April", "apr", 30, 4},
 {"May", "may", 31, 5},
 {"June", "jun", 30, 6},
 {"July", "jul", 31, 7},
 {"August", "aug", 31, 8},
 {"September", "sep", 30, 9},
 {"October", "oct", 31, 10},
 {"November", "nov", 30, 11},
 {"December", "dec", 31, 12}
};

int main(int argc, char * argv[]) 
{
    int month, day;
    int total_days = 0;
    int i;
    
    printf("Enter month and day:");
    scanf("%d %d", &month, &day);
    
    for (i = 0; i < month-1; i++) {
        total_days += months[i].days;
    }
    total_days += day;
    
    printf("total days is %d to %d %s\n", total_days, day, months[month-1].name);
    
    return 0;
}

