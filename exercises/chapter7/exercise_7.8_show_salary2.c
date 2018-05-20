/* show_salary2.c -- 根据工时打印工资总额，税金和净工资 */
#include <stdio.h>
#define EXTRA_WORK_TIME_RATE 1.5
#define TAX_RATE_1 0.15
#define TAX_RATE_2 0.20
#define TAX_RATE_3 0.25
#define TAX_VALUE_1 300
#define TAX_VALUE_2 ((TAX_VALUE_1) + 150)
#define BASE_WORK_HOURS 40
void show_salary(float work_hours, float pay_rate);
void show_menu(void);
void starbar(void);
int main(void) 
{
    float work_hours;
    float pay_rate = 10.0;
    int choice;
    
    show_menu();
    while( scanf("%d", &choice) ) {
        switch (choice) 
        {
            case 1: pay_rate = 8.75; break;
            case 2: pay_rate = 9.33; break;
            case 3: pay_rate = 10.00; break;
            case 4: pay_rate = 11.20; break;
            case 5: pay_rate = -1; break;
            default: 
                pay_rate = 0;
                printf("Unknown choice. Please Enter value from 1 to 5:");
                break;
        }
        
        if (pay_rate > 0) {
            printf("Enter your work_hour of the week:");
            scanf("%f", &work_hours);
    
            show_salary(work_hours, pay_rate);
            show_menu();
        } else if (pay_rate < 0) {
            break;
        } 
    }
    
    printf("Done.\n");

    printf("\n---------------------------------------------\n");
    return 0;
}

void show_salary(float work_hours, float pay_rate)
{
    float total_work_hours;
    float salary, tax, net_salary;
    
    // 计算工时，包括加班
    if (work_hours > BASE_WORK_HOURS)
        total_work_hours = BASE_WORK_HOURS + (work_hours - BASE_WORK_HOURS) * EXTRA_WORK_TIME_RATE;
    else
        total_work_hours = work_hours;
        
    // 计算工资
    salary = total_work_hours * pay_rate;
    
    // 计算税金
    if (salary <= TAX_VALUE_1)
        tax = salary * TAX_RATE_1;
    else if (salary <= TAX_VALUE_2) 
        tax = TAX_VALUE_1 * TAX_RATE_1 + (salary - TAX_VALUE_1) * TAX_RATE_2;
    else
        tax = TAX_VALUE_1 * TAX_RATE_1 + (TAX_VALUE_2 - TAX_VALUE_1) * TAX_RATE_2 + (salary - TAX_VALUE_2) * TAX_RATE_3;
    
    // 计算净工资
    net_salary = salary - tax;
    
    printf("salary is %.2f, tax is %.2f, net_salary is %.2f\n", salary, tax, net_salary);
}

void show_menu(void)
{
    starbar();
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("1) $8.75/hr                   2) $9.33/hr\n");
    printf("3) $10.00/hr                  4) $11.20/hr\n");
    printf("5) quit\n");
    starbar();
}

void starbar(void)
{
    printf("*****************************************************************\n");
}