/* cm2inch.c -- 将厘米转为英寸 */
#include <stdio.h>

int main(void)
{
    float cm_per_inch = 2.45f;
    float height;
    
    printf("Please input you height in cm:");
    scanf("%f", &height);
    printf("Your height is %f cm, %f inch.\n", height, height / cm_per_inch);
    return 0;
    
}



