#include <stdio.h>
#include <stdlib.h>
#define Size 5
typedef struct Table
{
    int *head;
    int length;
    int size;
} table;

table initTable() //初始化顺序表
{
    table t;
    t.head = (int *)malloc(Size * sizeof(int));
    if (!t.head)
    {
        printf("初始化失败");
        exit(0);
    }
    t.length = 0;
    t.size = Size;
    return t;
}

void displayTable(table t) //输出顺序表内容
{
    for (int i = 0; i < t.length; i++)
    {
        printf("%d", t.head[i]);
    }
    printf("\n");
}

int main(void)
{
    table t = initTable();
    //向顺序表添加元素；
    for (int i = 1; i <=Size; i++)
    {
        t.head[i - 1] = i;
        t.length++;
    }
    printf("顺序表中存储的元素分别是：\n");
    displayTable(t);
    return 0;
}