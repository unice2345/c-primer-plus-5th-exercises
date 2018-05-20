/* water_count.c -- 计算输入的夸脱水中游多少个水分子 */
#include <stdio.h>

int main(void)
{
    double water_mass = 3E-23;
    double mass_per_kuatuo = 950.0;
    int kuatuo;
    float water_count;
    printf("Please input kuotuo number:");
    scanf("%d", &kuatuo);
    water_count = mass_per_kuatuo * kuatuo / water_mass;
    printf("%d kuotuo water contains %f or %e water module.\n", kuatuo, water_count, water_count);
    return 0;
}