#include "pe12-3a.h"
#include <stdio.h>

static char* modes[2] = {
    "metric",
    "US"
};

int set_mode(int mode)
{
    static int g_mode;
    if (0 != mode && 1 != mode) {
        printf("Invalie mode specified. Mode %d (%s) used.\n", g_mode, modes[g_mode]);
        return g_mode;
    }
    
    g_mode = mode;
    return g_mode;
}

void get_info(int mode)
{
    //static int mode;
    float g_distance, g_fuel;
    
    // get info
    if (0 == mode) {
        printf("Enter distance traveldd in kilometers: ");
        scanf("%f", &g_distance);
        printf("Enter fuel consumed in liters:");
        scanf("%f", &g_fuel);
    } else if (1 == mode) {
        printf("Enter distance traveldd in miles: ");
        scanf("%f", &g_distance);
        printf("Enter fuel consumed in gallons:");
        scanf("%f", &g_fuel);
    } 
    
    // show info
    show_info(g_distance, g_fuel, mode);
}

void show_info(float distance, float fuel, int mode)
{
    if (0 == mode) {
        printf("Fuel consumption is %.2f liters per 100 km.\n", fuel * 100 / distance);
    } else if (1 == mode) {
        printf("Fuel consumption is %.1f miles per gallon.\n", distance / fuel);
    }
}