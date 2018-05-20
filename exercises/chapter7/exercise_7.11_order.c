/* order.c -- 订单系统 */
#include <stdio.h>
float transport_fee(int pounds);
void show_menu(void);
void starbar(void);
int get_int(void);

int main(void) 
{
    const float ARTICHOKE_PRICE = 1.25;
    const float BEETROOT_PRICE = 0.65;
    const float CARROT_PRICE = 0.89;
    const float DISCOUNT = 0.05;
    const float DISCOUNT_BREAK = 100;
    
    int artichoke_pounds = 0, beetroot_pounds = 0, carrot_pounds = 0;
    float order_fee, discount, transport_fees, total_fee;
    char type;
    int invalid = 0;
    
    show_menu();
    while ((type = getchar()) != 'q') {
        switch (type) {
            case 'a': artichoke_pounds = get_int(); break;
            case 'b': beetroot_pounds = get_int(); break;
            case 'c': carrot_pounds = get_int(); break;
            default: invalid = 1; break; 
        }
        
        if (!invalid) {
            order_fee = artichoke_pounds * ARTICHOKE_PRICE + beetroot_pounds * BEETROOT_PRICE + carrot_pounds * CARROT_PRICE;
            discount = (int)(order_fee / DISCOUNT_BREAK) * DISCOUNT;
            transport_fees = transport_fee(artichoke_pounds + beetroot_pounds + carrot_pounds);
            total_fee = order_fee - discount + transport_fees;
            printf("Artichoke: price %.2f, pounds %d, fee %.2f\n", ARTICHOKE_PRICE, artichoke_pounds, artichoke_pounds * ARTICHOKE_PRICE);
            printf("Beetroot: price %.2f, pounds %d, fee %.2f\n", BEETROOT_PRICE, beetroot_pounds, beetroot_pounds * BEETROOT_PRICE);
            printf("Carrot: price %.2f, pounds %d, fee %.2f\n", CARROT_PRICE, carrot_pounds, carrot_pounds * CARROT_PRICE);
            printf("order fee: %.2f, discount %.2f, transport fee %.2f, total fee %.2f\n", order_fee, discount, transport_fees, total_fee);
        } else {
            printf("Invalid type.\n");
        }
        
        show_menu();
    }
    printf("Done.\n");
    
    printf("\n---------------------------------------------\n");
    return 0;
}

float transport_fee(int pounds)
{
    float fee;
    
    if (pounds <= 5) 
        fee = 3.5;
    else if (pounds < 20) 
        fee = 10;
    else    
        fee = 8 + (pounds - 20) * 0.1;
        
    return fee;
}

void show_menu(void)
{
    starbar();
    printf("Choose vegetable type:\n");
    printf("a) artichoke         b) beetroot\n");
    printf("c) carrot            q) quit\n");
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