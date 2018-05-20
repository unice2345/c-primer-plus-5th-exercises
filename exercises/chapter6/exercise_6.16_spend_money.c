/* spend_money.c -- 计算多长时间将钱花完 */
#include <stdio.h>

int main(void) 
{
    float total_money = 1000000;
    float interest = 0.08;
    float spend_money = 100000;
    
    int years = 1;
    
    while (total_money > 0) {
        total_money = total_money * (1 + interest) - spend_money;
        years++;
    }
    
    printf("After %d years, you spend all your money.", years);
    printf("\n---------------------------------------------\n");
    return 0;
}