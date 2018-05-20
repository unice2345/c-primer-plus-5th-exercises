/* pe16-4.c -- sleep */
#include <stdio.h>
#include <time.h>

void sleep(double secs);

int main(void) 
{
    sleep(5);
    printf("\n---------------------------------------------\n");
    return 0;
}

void sleep(double secs)
{
    clock_t start = clock();
    clock_t end;
    
    while (1) {
        end = clock();
        if ((end - start) * 1.0 / CLOCKS_PER_SEC > secs)
            break;
    }
}