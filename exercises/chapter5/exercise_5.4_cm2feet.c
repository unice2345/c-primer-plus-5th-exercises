/* cm2feet.c --  将厘米转换为英寸英尺 */
#include <stdio.h>

int main(void)
{
    const float CM_PER_FEET = 30.48;
    const int INCH_PER_FEET = 12;
    
    float cm, inch;
    float feet;
    int int_feet;
    
    printf("Enter a height in centimeters: ");
    scanf("%f", &cm);
    while (cm > 0) {
        feet = cm / CM_PER_FEET;
        int_feet = (int)feet;
        inch = (feet - int_feet) * INCH_PER_FEET;
        printf("%.1f cm = %d feet, %.1f inches\n", cm, int_feet, inch);
        printf("Enter a height in centimeters: ");
        scanf("%f", &cm);
    }
    printf("bye\n");
    return 0;
}