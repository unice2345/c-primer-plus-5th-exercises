/* calc_tax.c -- 计算税金 */
#include <stdio.h>
void show_menu(void);
void starbar(void);
int get_int(void);


#define TAX_RATE_1 0.15
#define TAX_RATE_2 0.28
int main(void) 
{
    float tax;
    int type, earnings, earning_base;
    
    show_menu();
    while (scanf("%d", &type) && type != 5) {
        switch (type) {
            case 1: earning_base = 17850; break;
            case 2: earning_base = 23900; break;
            case 3: earning_base = 29750; break;
            case 4: earning_base = 14875; break;
            default: earning_base = 0; break;
        }
        
        if (earning_base > 0) {
            earnings = get_int();
            if (earnings > earning_base) 
                tax = earning_base * TAX_RATE_1 * 1.0 + (earnings - earning_base) * TAX_RATE_2;
            else
                tax = earnings * TAX_RATE_1 * 1.0;
                
            printf("Tax is %.2f\n", tax);
        } else {
            printf("Invalid type.\n");
        }
        
        show_menu();
    }
    printf("Done.\n");
    printf("\n---------------------------------------------\n");
    return 0;
}

void show_menu(void)
{
    starbar();
    printf("Enter tax type:\n");
    printf("1) single             2) master\n");
    printf("3) married            4) divorsed\n");
    printf("5) quit\n");
    starbar();
}

void starbar(void)
{
    printf("*****************************************************************\n");
}

int get_int(void)
{
    int x;
    printf("Enter an integer value:");
    while (scanf("%d", &x) == 0) {
        while (getchar() != '\n')
            continue;
        printf("Enter an integer value:");
    } 
    
    while (getchar() != '\n')
            continue;
            
    return x;
}