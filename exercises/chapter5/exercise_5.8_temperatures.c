/* temperatures.c -- 打印华氏温度，摄氏温度和绝对温度 */
#include <stdio.h>

void temperatures(double fahrenheit)
{
    const double a = 1.8;
    const double b = 32.0;
    const double c = 273.16;

    double celsius = a * fahrenheit + b;
    double kelvin = celsius + c;
    
    printf("F is %.2f, c is %.2f, k is %.2f\n"
        , fahrenheit, celsius, kelvin);
    
}

int main(void)
{
    double fahrenheit;
    printf("Enter Fahrenheit:");
    while(scanf("%lf", &fahrenheit)) {
        temperatures(fahrenheit);
        printf("Enter Fahrenheit:");
    }
    printf("finished.\n");
}
