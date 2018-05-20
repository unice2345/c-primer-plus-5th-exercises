/* pe13-13.c -- smooth_image */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM 30
#define LINE 20

void smooth_image(int image[][NUM], int smooth[][NUM]);

int main(void) 
{
    FILE* fp;
    int num[LINE][NUM];
    int smooth[LINE][NUM];
    //char chars[LINE][NUM];
    int i, j;
    char toChars[10] = " .':~*= %#";
    
    
    fp = fopen("image.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Cannot open file\n");
        exit(1);
    }
    
    // 读取数据
    for (i = 0; i < LINE; i++) {
        for (j = 0; j < NUM; j++) {
            fscanf(fp, "%d", &num[i][j]);
            //chars[i][j] = toChars[num[i][j]];
        }
    }
    
    // 平滑
    smooth_image(num, smooth);
    
    // 打印数字
    for (i = 0; i < LINE; i++) {
        for (j = 0; j < NUM; j++) {
            printf("%d ", num[i][j]);
        }
        putchar('\n');
    }
    
    puts("----------------------------------------------------------------");
    // 打印数字
    for (i = 0; i < LINE; i++) {
        for (j = 0; j < NUM; j++) {
            printf("%d ", smooth[i][j]);
        }
        putchar('\n');
    }
    puts("----------------------------------------------------------------");
    // 打印图像
    for (i = 0; i < LINE; i++) {
        for (j = 0; j < NUM; j++) {
            putchar(toChars[num[i][j]]);
        }
        putchar('\n');
    }
    puts("----------------------------------------------------------------");
    // 打印图像
    for (i = 0; i < LINE; i++) {
        for (j = 0; j < NUM; j++) {
            putchar(toChars[smooth[i][j]]);
        }
        putchar('\n');
    }
    
    fclose(fp);
    
    printf("\n---------------------------------------------\n");
    return 0;
}

void smooth_image(int image[][NUM], int smooth[][NUM])
{
    int i, j;
    
    for (i = 1; i < LINE-1; i++) {
        for (j = 1; j < NUM-1; j++) {
            if (fabs(image[i][j] - image[i-1][j]) > 1
            && fabs(image[i][j] - image[i+1][j]) > 1
            && fabs(image[i][j] - image[i][j-1]) > 1
            && fabs(image[i][j] - image[i][j+1]) > 1) {
                smooth[i][j] = (image[i-1][j] + image[i+1][j] + image[i][j-1] + image[i][j+1]) / 4;
            } else {
                smooth[i][j] = image[i][j];
            }
        }
    }
    
    // 特殊处理
    // 第一行
    i = 0;
    for (j = 1; j < NUM-1; j++) {
        if (fabs(image[i][j] - image[i+1][j]) > 1
            && fabs(image[i][j] - image[i][j-1]) > 1
            && fabs(image[i][j] - image[i][j+1]) > 1) {
                smooth[i][j] = (image[i+1][j] + image[i][j-1] + image[i][j+1]) / 3;
            } else {
                smooth[i][j] = image[i][j];
            }
    }
    
    // 最后一行
    i = LINE - 1;
    for (j = 1; j < NUM-1; j++) {
        if (fabs(image[i][j] - image[i-1][j]) > 1
        && fabs(image[i][j] - image[i][j-1]) > 1
        && fabs(image[i][j] - image[i][j+1]) > 1) {
            smooth[i][j] = (image[i-1][j] + image[i][j-1] + image[i][j+1]) / 3;
        } else {
            smooth[i][j] = image[i][j];
        }
    }
    
    // 第一列
    j = 0;
    for (i = 1; i < LINE-1; i++) {
        if (fabs(image[i][j] - image[i-1][j]) > 1
            && fabs(image[i][j] - image[i+1][j]) > 1
            && fabs(image[i][j] - image[i][j+1]) > 1) {
            smooth[i][j] = (image[i-1][j] + image[i+1][j] + image[i][j+1]) / 3;
        } else {
            smooth[i][j] = image[i][j];
        }
    }
    
    // 最后一列
    j = NUM - 1;
    for (i = 1; i < LINE-1; i++) {
        if (fabs(image[i][j] - image[i-1][j]) > 1
            && fabs(image[i][j] - image[i+1][j]) > 1
            && fabs(image[i][j] - image[i][j-1]) > 1) {
            smooth[i][j] = (image[i-1][j] + image[i+1][j] + image[i][j-1]) / 3;
        } else {
            smooth[i][j] = image[i][j];
        }
    }
    
    // 左上角点
    i = 0;
    j = 0;
    if ( fabs(image[i][j] - image[i+1][j]) > 1
        && fabs(image[i][j] - image[i][j+1]) > 1) {
            smooth[i][j] = (image[i+1][j] + image[i][j+1]) / 2;
        } else {
            smooth[i][j] = image[i][j];
        }
        
    // 右上角点
    i = 0;
    j = NUM - 1;
    if (fabs(image[i][j] - image[i+1][j]) > 1
        && fabs(image[i][j] - image[i][j-1]) > 1) {
            smooth[i][j] = (image[i+1][j] + image[i][j-1]) / 2;
        } else {
            smooth[i][j] = image[i][j];
        }
        
    // 左下角点
    i = LINE - 1;
    j = 0;
    if (fabs(image[i][j] - image[i-1][j]) > 1
        && fabs(image[i][j] - image[i][j+1]) > 1) {
            smooth[i][j] = (image[i-1][j] + image[i][j+1]) / 2;
        } else {
            smooth[i][j] = image[i][j];
        }
        
    // 右下角点
    i = LINE - 1;
    j = NUM - 1;
    if (fabs(image[i][j] - image[i-1][j]) > 1
        && fabs(image[i][j] - image[i][j-1]) > 1) {
            smooth[i][j] = (image[i-1][j] + image[i][j-1]) / 2;
        } else {
            smooth[i][j] = image[i][j];
        }
}