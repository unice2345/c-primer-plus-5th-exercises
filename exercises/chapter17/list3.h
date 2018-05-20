#ifndef LIST3_H_
#define LIST3_H_
#include <stdbool.h>

/* 特定程序的声明 */
#define TSIZE 45
struct film {
    char title[TSIZE];
    int rating;
};

typedef struct film Item;

typedef struct node {
    Item item;
    struct node * next;
} Node;

#define MAXSIZE 100
typedef struct list {
    Item entries[MAXSIZE];
    int items;
} List;

/**
 * @brief 初始化列表
 * @param plist 待初始化的列表
 */
void InitializeList(List * plist);

/**
 * @brief 判断列表是否为空
 * @param plist 列表
 * @return 列表是否为空
 */
bool ListIsEmpty(const List * plist);

/**
 * @brief 判断列表是否为满
 * @param plist 列表
 * @return 列表是否为满
 */
bool ListIsFull(const List * plist);

/**
 * @brief 求列表中项目的个数
 * @param plist 列表
 * @return 列表中项目的个数
 */
unsigned int ListItemCount(const List * plist);

/**
 * @brief 向列表中添加项目
 * @param item 项目
 * @param plist 列表
 * @return 是否添加成功
 */
bool AddItem(Item item, List * plist);

/**
 * @brief 遍历列表
 * @param plist 列表
 * @param pfun 对列表中的项目进行操作的函数
 */
void Traverse(const List * plist, void (*pfun)(Item item));

/**
 * @brief 清空列表
 * @param plist 列表 
 */
void EmptyList(List * plist);

#endif