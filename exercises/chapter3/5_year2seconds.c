/* year2seconds -- 将年龄转换为秒 */
#include <stdio.h>

int main(void)
{
    int age;
    float seconds_per_year = 3.156E7;
    printf("Please input your age:");
    scanf("%d", &age);
    printf("You have spent %f or %e seconds in your past life.\n", age * seconds_per_year, age * seconds_per_year);
    return 0;
}