/* escape.c -- 使用转义字符 */
#include <stdio.h>

int main(void)
{
    float salary;
    printf("\aEnter your desired monthily salary: ");
    printf("$______\b\b\b\b\b\b");
    scanf("%f", &salary);
    printf("\t%.2f a month is %.2f a year.", salary, salary * 12.0);
    printf("\rGee!\n");
    return 0;
}