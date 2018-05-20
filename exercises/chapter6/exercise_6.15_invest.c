/* invest.c -- 计算投资收益 */
#include <stdio.h>

float simple_interest(float invest, float interest, int years);
float compound_interest(float invest, float interest, int years);
int main(void) 
{
    float invest = 100, interest = 0.15;
    int years;
    
    while (simple_interest(invest, interest, years) > compound_interest(invest, interest, years))
        years++;
        
        
        
    printf("simple interest invest is %.2f, compound interest earnings is %.2f at %d years.\n",
        simple_interest(invest, interest, years), compound_interest(invest, interest, years), years);
    printf("\n---------------------------------------------\n");
    return 0;
}

float simple_interest(float invest, float interest, int years)
{
    return invest * (1 + interest * years);
}

float compound_interest(float invest, float interest, int years)
{
    int i;
    
    for (i = 1; i <= years; i++) {
        invest = invest * (1 + interest);
    }
    return invest;
}