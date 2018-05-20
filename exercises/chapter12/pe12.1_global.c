/* global.c -- 不使用全局变量 */
#include <stdio.h>
int critic(void);
int main(void) 
{
    int units;
    
    printf("How many?\n");
    scanf("%d", &units);
    while (units != 56)
        units = critic();
    printf("You must have looked it up!\n");
    printf("\n---------------------------------------------\n");
    return 0;
}

int critic(void)
{
    int units;
    printf("No luck. Try again.\n");
    scanf("%d", &units);
    return units;
}