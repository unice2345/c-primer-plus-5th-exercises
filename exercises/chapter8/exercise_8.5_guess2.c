/* guess.c -- 一个低效且错误的猜数程序 */
#include <stdio.h>

int main(void) 
{
    char ch;
    int guess = 50;
    int min = 1, max = 100;
    printf("Pick an integer from 1 to 100. I will try to guess it.\n");
    printf("Response with 'y' if my guess is right and with 'n' if it is wrong.\n");
    printf("Uh...is your number is %d?\n", guess);
 
    while ((ch = getchar()) != 'y') {
    
        while (getchar() != '\n') {
            continue;
        }
        
        if (ch == 'b') {
            max = guess;
        }
        if (ch == 's') {
            min = guess;
        }
        guess = (min + max) / 2;
        printf("Well, then, is it %d?\n", guess);
    }
    printf("I knew  could do it.\n");
    printf("\n---------------------------------------------\n");
    return 0;
}