#include "pe12-2a.h"
#include <stdio.h>

static int g_mode;
static float g_distance;
static float g_fuel;
static char* modes[2] = {
    "metric",
    "US"
};

void set_mode(int mode)
{
    if (0 != mode && 1 != mode) {
        printf("Invalie mode specified. Mode %d (%s) used.\n", g_mode, modes[g_mode]);
        return ;
    }

    g_mode = mode;
}

void get_info()
{
    if (0 == g_mode) {
        printf("Enter distance traveldd in kilometers: ");
        scanf("%f", &g_distance);
        printf("Enter fuel consumed in liters:");
        scanf("%f", &g_fuel);
    } else if (1 == g_mode) {
        printf("Enter distance traveldd in miles: ");
        scanf("%f", &g_distance);
        printf("Enter fuel consumed in gallons:");
        scanf("%f", &g_fuel);
    } 
}

void show_info()
{
    if (0 == g_mode) {
        printf("Fuel consumption is %.2f liters per 100 km.\n", g_fuel * 100 / g_distance);
    } else if (1 == g_mode) {
        printf("Fuel consumption is %.1f miles per gallon.\n", g_distance / g_fuel);
    }
}