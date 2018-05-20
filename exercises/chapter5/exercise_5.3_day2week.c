/* day2week.c -- */
#include <stdio.h>

int main(void)
{
    int days, weeks, left_days;
    printf("Input days: ");
    scanf("%d", &days);
    
    weeks = days / 7;
    left_days = days % 7;
    printf("%d days are %d weeks, % days\n", days, weeks, left_days);
    return 0;
}