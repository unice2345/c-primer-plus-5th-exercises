/* pe14-5.c -- student */
#include <stdio.h>
#define CSIZE 4
struct name {
    char first[20];
    char last[20];
};

struct student {
    struct name st_name;
    float grades[3];
    float average;
};

void print_student(struct student * pstudent);
int main(void)
{
    struct student students[CSIZE];
    float average_grades[3] = {0, 0, 0};
    int i;
    
    for (i = 0; i < CSIZE; i++) {
        printf("Enter student name: ");
        scanf("%s %s", students[i].st_name.first, students[i].st_name.last);
        printf("Enter grades:");
        scanf("%f %f %f", &students[i].grades[0], &students[i].grades[1], &students[i].grades[2]);
        while (getchar() != '\n')
            continue;
        students[i].average = (students[i].grades[0] + students[i].grades[1] + students[i].grades[2]) / 3;
    }
    
    for (i = 0; i < CSIZE; i++) {
        average_grades[0] += students[i].grades[0];
        average_grades[1] += students[i].grades[1];
        average_grades[2] += students[i].grades[2];
    }
    
    for (i = 0; i < CSIZE; i++) {
        print_student(&students[i]);
    }
    
    for (i = 0; i < 3; i++)
        printf("%.2f ", average_grades[i]/CSIZE);
    return 0;
}

void print_student(struct student * pstudent)
{
    printf("Student name: %s %s\n", pstudent->st_name.first, pstudent->st_name.last);
    printf("Grades: %.2f %.2f %.2f\n", pstudent->grades[0], pstudent->grades[1], pstudent->grades[2]);
    printf("Average grade: %.2f\n", pstudent->average);
}