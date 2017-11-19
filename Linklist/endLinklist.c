#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node, *Linklist; //Linklist 为结构指针类型

Linklist CreateFormEnd(void)
{
    Linklist node;
    int c;
    Linklist L;
    Linklist R;
    _Bool flag = 0;
    L = (Linklist)malloc(sizeof(Node));
    R = L;
    while (flag == 0)
    {
        scanf("%d", &c);
        printf("c:%d\n",c);
        if (c != 999)
        {
            node = (Linklist)malloc(sizeof(Node)); //新建节点
            node->data = c;                        //数据给到新节点的数据存储中
            R->next = node;                        //尾节点的next指向新节点
            node->next = NULL;                     //新节点的next指向无
            R = node;                              //新节点成为新的尾节点
        }
        else
        {
            flag = 1;
        }
    }
    return L;
}

void ShowList(Linklist L)
{
    _Bool flag = 1;
    Linklist n = L;
    while (flag == 1)
    {
        printf("data:%d \n", n->data);
        if (n->next != NULL)
        {
            n = n->next;
        }
        else
            flag = 0;
    }
}

int GetLength(Linklist L)
{
    Linklist node;
    node = L;
    int num = 0;
    while(node->next!= NULL)
    {
        num++;
        node = node->next;
    }
    return num;
}

int main()
{
    Linklist list;
    int num;
    list = CreateFormEnd();
    ShowList(list);
    num = GetLength(list);
    printf("num:%d", num);
    printf("end\n");
    getchar();
    getchar();
}