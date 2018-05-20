/* calculator.c -- 计算器 */
#include <stdio.h>
void show_menu(void);
void starbar(void);
float get_float(void);
void get_two_numbers(void);
void get_two_numbers_for_division(void);
void eat_line(void);

float first_num, second_num;
int main(void) 
{
    int choice;
    int quit = 0;
    
    show_menu();
    while( (choice = getchar()) != EOF ) {
        eat_line();
        
        switch (choice) 
        {
            case 'a': 
                get_two_numbers();
                printf("%.1f + %.1f = %.1f\n", first_num, second_num, first_num + second_num); 
                break;
            case 's': 
                get_two_numbers();
                printf("%.1f - %.1f = %.1f\n", first_num, second_num, first_num - second_num); 
                break;
            case 'm': 
                get_two_numbers();
                printf("%.1f * %.1f = %.1f\n", first_num, second_num, first_num * second_num); 
                break;
            case 'd': 
                get_two_numbers_for_division();
                printf("%.1f / %.1f = %.1f\n", first_num, second_num, first_num / second_num); 
                break;
            case 'q': 
                quit = 1;
                break;
            default: 
                printf("Invalid choice.\n");
                break;
        }
        
        if (quit)
            break;
        
        show_menu();
    }
    
    printf("Bye.\n");

    printf("\n---------------------------------------------\n");
    return 0;
}

void show_menu(void)
{
    starbar();
    printf("Enter the operation of your choice:\n");
    printf("a) add                   s) subtract\n");
    printf("m) multiply              d) divide\n");
    printf("q) quit\n");
    starbar();
}

void starbar(void)
{
    printf("*****************************************************************\n");
}

float get_float(void)
{
    float f;
    char content[128];
    
    while (scanf("%f", &f) != 1) {
        scanf("%s", content);
        printf("%s is not an number.\n", content);
        printf("Please enter a number, such as 2.5, -1.78E8, or 3:\n");
    }
    
    eat_line();
    return f;
}

void get_two_numbers(void)
{
    printf("Enter first number: ");
    first_num = get_float();
    printf("Enter second number: ");
    second_num = get_float();
}

void get_two_numbers_for_division(void)
{
    printf("Enter first number: ");
    first_num = get_float();
    printf("Enter second number: ");
    while (((int)(second_num = get_float()) == 0)) {
        printf("Enter a number other than 0: ");
    }
}

void eat_line(void)
{
    while (getchar() != '\n')
        continue;
}