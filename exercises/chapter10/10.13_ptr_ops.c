/* ptr_ops.c -- 指针操作 */
#include <stdio.h>

int main(void) 
{
    int arr[5] = {100, 200, 300, 400, 500};
    int * ptr1, * ptr2, * ptr3;
    
    ptr1 = arr;     // 赋值(assignment)
    ptr2 = &arr[2]; // 赋值(assignment)
    
    printf("pointer value, dereferenced pointer, pointer address:\n");
    printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n", 
        ptr1, 
        *ptr1,      // 取值(derefrencing)
        &ptr1);     // 取指针的地址
    
    printf("\nadding an int to a pointer:\n");
    printf("ptr1 + 4 = %p, *(ptr1 + 4) = %d\n",
        ptr1 + 4,   // 指针加一个整数
        *(ptr1 + 4) 
    );
    
    ptr1++;         // 递增指针
    printf("\nvalues after ptr++\n");
    printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n", 
        ptr1, 
        *ptr1,      
        &ptr1);     
    
    printf("\nsubtracting one pointer from another:\n");
    printf("ptr2 = %p, ptr1 = %p, ptr2 - ptr1 = %d\n",
        ptr2,
        ptr1,
        ptr2 - ptr1 // 两个指针相减 
    );
    printf("\n---------------------------------------------\n");
    return 0;
}