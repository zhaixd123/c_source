#include <stdio.h>
#include <stdlib.h>

#define TElemType char //宏定义，节点中的数据域的类型

//枚举，Link为0，Thread为1
typedef enum 
{
    Link=0,
    Thread=1
} PointerTag;

//结点结构构造

typedef struct BiThrNode
{
    TElemType data;                   //数据瑜
    struct BiThrNod *lchild, *rchild; //左孩子，右孩子指针域
    PointerTag Ltag, Rtag;            //标志域枚举类型
} BiThrNode, *BiThrTree;

BiThrTree pre = NULL;
//采用前序初始化二叉树
//钟需和后续只需要改变赋值语句的未知即可

void CreateTree(BiThrTree *tree)
{
    char data;
    scanf("%c", &data);
    if (data != '#')
    {
        if (!((*tree) = (BiThrNode *)malloc(sizeof(BiThrNode))))
        {
            printf("申请空间失败");
            return;
        }
        else
        {
            (*tree)->data = data;           //采用前序遍历方式初始化二叉树
            CreateTree(&((*tree)->lchild)); //初始化左子树
            CreateTree(&((*tree)->rchild)); //初始化右子树
        }
    }
    else
    {
        *tree = NULL;
    }
}

//中序对二叉树进行线索化
void InThreading(BiThrTree p)
{
    //如果当前节点存在
    if (p)
    {
        InThreading(p->lchild); //递归当前节点的左子树，进行线索化
        //如果当前节点没有左孩子，左标志位设为1，左指针域指向上一届点pre
        if (!p->lchild)
        {
            p->Ltag = Thread;
            p->lchild = pre;
        }
        //如果pre没有右孩子，右标志位设置为1，右指针域指向当前节点。
        if (pre && !pre->rchild)
        {
            pre->Rtag = Thread;
            pre->rchild = p;
        }
        pre = p;                //pre指向当前结点
        InThreading(p->rchild); //递归右子树进行线索化
    }
}

//中序遍历二叉树
void InOrderThraverse_Thr(BiThrTree p)
{
    while (p)
    {
        //一直着左孩子，最后一个为中序序列中排第一的
        while (p->Ltag == Link)
        {
            p = p->lchild;
        }
        printf("%c", p->data); //操作结点数据
        //当节点右标志位为1时，直接找到其后继节点
        while (p->Rtag == Thread && p->rchild != NULL)
        {
            p = p->rchild;
            printf("%c", p->data);
        }
        //否则，按照中序遍历的规律，找其右子树最左下的结点，也就是继续循环遍历
        p = p->rchild;
    }
}

int main()
{
    BiThrTree t;
    printf("输入前序二叉树：\n");
    CreateTree(&t);
    InThreading(t);
    printf("输出中序序列：\n");
    InOrderThraverse_Thr(t);
    return 0;
}