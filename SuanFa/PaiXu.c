#include <stdio.h>
#include <stdlib.h>

int paixuArray[] = {1, 3, 600, 300, 100, 50, -300 - 200, -100, 1000};

void printArray(int *testArray, int arrayLen) //打印int数组
{
    for (int i = 0; i < arrayLen; i++)
    {
        if (i == arrayLen - 1)
        {
            printf("%d\n", *(testArray + i));
        }
        else
        {
            printf("%d,", *(testArray + i));
        }
    }
}

void MaoPaoPaiXu() //冒泡排序
{
    int arrayLen = sizeof(paixuArray) / sizeof(int);
    int temp;
    int i, j;
    printf("开始冒泡排序:\n排序前数组顺序->:");

    printArray(paixuArray, arrayLen);

    for (i = 0; i < arrayLen - 1; i++)
    {
        for (j = 0; j < arrayLen - i - 1; j++)
        {
            if (paixuArray[j] < paixuArray[j + 1])
            {
                temp = paixuArray[j];
                paixuArray[j] = paixuArray[j + 1];
                paixuArray[j + 1] = temp;
            }
        }
    }
    printf("冒泡排序结束:\n排序后数组顺序->:");
    printArray(paixuArray, arrayLen);
}

void XuanZePaiXu() //选择排序，冒泡排序改进版
{
    int arrayLen = sizeof(paixuArray) / sizeof(int);
    int tempFlag;
    int temp;
    int i, j;
    printf("开始选择排序:\n排序前数组顺序->:");

    printArray(paixuArray, arrayLen);

    for (i = 0; i < arrayLen - 1; i++)
    {
        tempFlag = 0;
        for (j = 0; j < arrayLen - i - 1; j++)
        {
            if (paixuArray[tempFlag] < paixuArray[j + 1])
            {
                tempFlag = j + 1;
            }
        }
        temp = paixuArray[arrayLen - i - 1];
        paixuArray[arrayLen - i - 1] = paixuArray[tempFlag];
        paixuArray[tempFlag] = temp;
    }
    printf("选择排序结束:\n排序后数组顺序->:");
    printArray(paixuArray, arrayLen);
}

int main(void)
{
    XuanZePaiXu();
    return 0;
}