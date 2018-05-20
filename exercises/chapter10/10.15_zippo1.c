/* zippo1.c -- 指向多维数组的指针 */
#include <stdio.h>

int main(void) 
{
    int zippo[4][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};

    printf("zippo = %p, zippo + 1 = %p\n", zippo, zippo + 1);
    printf("*zippo = %p, *zippo + 1 = %p\n", *zippo, *zippo + 1);
    printf("**zippo = %d, **(zippo+1) = %d, *(*zippo+1) = %d\n", 
        **zippo, **(zippo+1), *(*zippo+1));
    printf("zippo's value is %x, *zippo's value is %x\n", zippo, *zippo);
//    printf("**zippo = %p, **(zippo+1) = %p, *(*zippo+1) = %p\n", 
//        **zippo, **(zippo+1), *(*zippo+1));
    
    
    printf("\n---------------------------------------------\n");
    return 0;
}