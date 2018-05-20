/* gas_consume.c -- 以公里升数或英里加仑数显示油耗 */
#include <stdio.h>
const float LITRE_PER_GALLON = 3.785;
const float KILOMETER_PER_MILE = 1.609;
int main(void)
{
    float mile, gallon;
    printf("Input mile and gallon:");
    scanf("%f %f", &mile, &gallon);
    printf("Your gas consume is %.1f miles/gallon, or %.6f litres/100 kilometers",
        mile / gallon, gallon * LITRE_PER_GALLON  * 1.0/ (100.0 * mile * KILOMETER_PER_MILE));
    return 0;
    
}