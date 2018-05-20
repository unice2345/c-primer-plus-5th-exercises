/* show_salary.c -- 根据工时打印工资总额，税金和净工资 */
#include <stdio.h>
#define EXTRA_WORK_TIME_RATE 1.5
#define TAX_RATE_1 0.15
#define TAX_RATE_2 0.20
#define TAX_RATE_3 0.25
#define TAX_VALUE_1 300
#define TAX_VALUE_2 ((TAX_VALUE_1) + 150)
#define BASE_WORK_HOURS 40
int main(void) 
{
    float work_hours;
    float pay_rate = 10.0;
    float total_work_hours;
    float salary, tax, net_salary;
    printf("Enter your work_hour of the week:");
    scanf("%f", &work_hours);
    
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
    printf("\n---------------------------------------------\n");
    return 0;
}