/* roll.c -- 掷骰子 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_n_dices(int dices, int sides);
int main(void) 
{
    int set;
    int sides, dice;
    int i;
    
    srand((unsigned int)time(0));
    printf("Enter the number of sets: enter q to stop.\n");
    while (scanf("%d", &set) != 0) {
        printf("How many sides and how many dice?\n");
        scanf("%d %d", &sides, &dice);
        printf("Here are %d sets of %d %d-sided throws.\n\t", set, dice, sides);
        for (i = 0; i < set; i++) {
            printf("%d ", roll_n_dices(dice, sides));
            if ((i+1) % 16 == 0)
                printf("\n\t");
        }
        printf("\nHow many sets? Enter q to stop.\n");
    }
    printf("\n---------------------------------------------\n");
    return 0;
}

int roll_n_dices(int dices, int sides)
{
    int total = 0;
    int i;
    int rand_num;
    
    
    for (i = 0; i < dices; i++) {
        rand_num = rand();
        //printf("rand is %d\n", rand_num);
        total += rand_num % sides + 1;
    }
   // printf("total = %d\n", total);
    return total;
}