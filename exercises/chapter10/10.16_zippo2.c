/* zippo2.c -- 指向多维数组的指针 */
#include <stdio.h>

int main(void) 
{
    int zippo[4][3] = {
        {1, 2, 12}, 
        {3, 4, 34}, 
        {5, 6, 56}, 
        {7, 8, 78}
    };
    int (*pz)[3];  // pz是一个数组，其中的每个元素是int arr[2]类型
    
    pz = zippo;
    
    printf("p[0][1] = %d\n", pz[0][1]);
    printf("p[0][1] = %d\n", *(*pz + 1));
    printf("p[1][2] = %d\n", pz[1][2]);
    printf("p[1][2] = %d\n", *(*(pz + 1) + 2));
    
    
    printf("\n---------------------------------------------\n");
    return 0;
}