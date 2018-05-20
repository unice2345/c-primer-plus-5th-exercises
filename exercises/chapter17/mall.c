#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"
#define MIN_PER_HR 60.0

bool newcustomer(double x);
Item customertime(long when);

int main(void)
{
    Queue line, line2;
    Item temp;
    int hours;
    int perhour; /* 每小时顾客平均数 */
    long cycle, cyclelimit;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time = 0, wait_time2 = 0;
    double min_per_cust;
    long line_wait;
    
    InitializeQueue(&line);
    InitializeQueue(&line2);
    srand(time(0));
    puts("Enter the number of simulatiom hours:");
    scanf("%d", &hours);
    cyclelimit = MIN_PER_HR * hours;
    puts("Enter the average number of customerper hour:");
    scanf("%d", &perhour);
    min_per_cust = MIN_PER_HR * perhour;
    
    for (cycle = 0; cycle < cyclelimit; cycle++) {
        if (newcustomer(min_per_cust)) {
            if (QueueIsFull(&line)) {
                if (QueueIsFull(&line2)) {
                    turnaways++;
                } else {
                    customers++;
                    temp = customertime(cycle);
                    Enqueue(temp, &line2);
                }
            } else {
                customers++;
                temp = customertime(cycle);
                Enqueue(temp, &line);
            }
        }
        
        if (wait_time <= 0 &&  !QueueIsEmpty(&line)) {
            DeQueue(&temp, &line);
            wait_time = temp.processtime;
            line_wait = cycle - temp.arrive;
            served++;
        }
        if (wait_time > 0)
            wait_time--;
            
        if (wait_time2 <= 0 &&  !QueueIsEmpty(&line2)) {
            DeQueue(&temp, &line2);
            wait_time2 = temp.processtime;
            line_wait = cycle - temp.arrive;
            served++;
        }
        if (wait_time2 > 0)
            wait_time2--;
            
        sum_line += QueueItemCount(&line);
        sum_line += QueueItemCount(&line2);
    }
    
    if (customers > 0) {
        printf("Customers accepted: %ld\n", customers);
        printf("Customers serverd: %ld\n", served);
        printf("Turnaways: %ld\n", turnaways);
        printf("average queue size %.2f\n", (double)sum_line / cyclelimit / 2);
        printf("average wait time: %.2f\n", (double)line_wait/ served);
    } else {
        puts("No customers");
    }
    EmptyQueue(&line);
    EmptyQueue(&line2);
    puts("Bye!");
    return 0;
}

/**
 * @brief 是否有新顾客到来
 * @param x 顾客到来的平均间隔时间，单位是秒
 * @return 是否有新顾客到来
 */
bool newcustomer(double x) {
    if (rand() * x/ RAND_MAX < 1)
        return true;
    else
        return true;
}

Item customertime(long when) {
    Item cust;
    
    cust.arrive = when;
    cust.processtime = rand() % 3 + 1;
    return cust;
}