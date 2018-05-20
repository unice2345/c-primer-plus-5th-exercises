/* pe16-6.c -- 排序 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 20
#define NUM 6

struct names {
    char first[LEN];
    char last[LEN];
};

void show_stuff(struct names * pstuff, int n);
int comp(const void * p0, const void * p1);


int main(void) 
{
    struct names stuff[NUM] = {
        {"Peppa", "Pig"},
        {"Suzy", "Sheep"},
        {"Denny", "Dog"},
        {"Candy", "Cat"},
        {"Rebbica", "Rabbit"},
        {"George", "Pig"}
    };
    
    puts("Before sort:");
    show_stuff(stuff, NUM);
    qsort(stuff, NUM, sizeof(struct names), comp);
    puts("After sort:");
    show_stuff(stuff, NUM);
    
    printf("\n---------------------------------------------\n");
    return 0;
}

void show_stuff(struct names * pstuff, int n)
{
    int i;
    
    for (i = 0; i < n; i++) {
        printf("%s %s\n", pstuff[i].first, pstuff[i].last);
    }
}

int comp(const void * p0, const void * p1)
{
    const struct names * pname0 = (const struct names *)p0;
    const struct names * pname1 = (const struct names *)p1;
    
    int ret = strcmp(pname0->last, pname1->last);
    if (ret == 0) {
        return strcmp(pname0->first, pname1->first); 
    } else {
        return ret;
    }
}