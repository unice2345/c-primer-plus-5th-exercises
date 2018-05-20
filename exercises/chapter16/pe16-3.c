/* pe16-3.c -- 极坐标转换直角坐标 */
#include <stdio.h>
#include <math.h>

#define DEG_TO_RAD (4 * atan(1) / 180)
typedef struct {
    double magnitude;
    double angle;
} POLAR_V;

typedef struct {
    double x;
    double y;
} RECT_V;

RECT_V polar2rect(POLAR_V polar);

int main(void) 
{
    POLAR_V polar = {sqrt(2), 45};
    RECT_V rect;
    
    rect = polar2rect(polar); 
    printf("rect: %.2f, %.2f\n", rect.x, rect.y);
    printf("\n---------------------------------------------\n");
    return 0;
}

RECT_V polar2rect(POLAR_V polar)
{
    RECT_V rect;
    
    rect.x = polar.magnitude * cos(polar.angle * DEG_TO_RAD);
    rect.y = polar.magnitude * sin(polar.angle * DEG_TO_RAD);
    return rect;
}