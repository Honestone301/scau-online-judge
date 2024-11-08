#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "malloc.h"
#define LEN sizeof(struct student)

struct student
{
    long num;
    int score;
    struct student* next;
};

struct student* create(int n)
{
    struct student* head = NULL, * p1 = NULL, * p2 = NULL;
    int i;
    for (i = 1; i <= n; i++)
    {
        p1 = (struct student*)malloc(LEN);
        scanf("%ld", &p1->num);
        scanf("%d", &p1->score);
        p1->next = NULL;
        if (i == 1) head = p1;
        else p2->next = p1;
        p2 = p1;
    }
    return(head);
}

void print(struct student* head)
{
    struct student* p;
    p = head;
    while (p != NULL)
    {
        printf("%8ld%8d", p->num, p->score);
        p = p->next;
        printf("\n");
    }
}

struct student* insert(struct student* head, struct student* stud)
    //用于把stud插入合适位置
{
    struct student* p0, * p1, * p2;
    p1 = head;  p0 = stud;
    if (head == NULL)
    {
        head = p0;
    }
    else
    {
        while ((p0->num > p1->num) && (p1->next != NULL))
        {
            p2 = p1;     p1 = p1->next;
        }//这一段while用于寻找head链表里能比stud大的那一个节点 
        //并且把该节点的上一个也弄了出来 即p2
        if (stud->num <= p1->num)
        {//用于比较stud序号与上个while的p1的序号哪个更大  这里是假设p1更大
            if (head == p1) head = stud;//用于确认p1是否为结点 是则把stud插入头部
            else p2->next = stud;//不是头结点，则将p2下一个变成stud 
            p0->next = p1;//使得stud的下一个变成p1
        }//其实这一整串代码的意义在于 将stud与链表进行比较 然后找一个合适的位置插入
        else { p1->next = p0; }
    }   //如果stud的序号大于p1（即上一个while使得p1为最后一个结点） 
        //那就让stud变成尾结点。
    return(head);
}

struct student* del(struct student* head, long num)   //用于确认是否有相同结点 有则删除其一
{
    struct student* p1, * p2;
    p1 = head;
    while (p1 != NULL)
    {
        if (p1->num == num)//用于确认head链表中 是否会和输入num相同的结点。
        {
            if (p1 == head) head = p1->next;//p1是否为头结点 是则把第二个节点变为头结点
            else p2->next = p1->next;//不是就把p1下一个的指针存储给p2
            free(p1);//放空p1
            break;//停止循环
        }
        p2 = p1;//不是头结点的话就把【p1】传给p2
        p1 = p1->next;//更新p1
    }
    return(head);
}

struct student* sort(struct student* head)
{
    struct student* p1, * p2=NULL, * p3=NULL;
    p1 = head;
    if (head == NULL) return NULL;
    while (p1!=NULL) {
        p2 = p1->next;
        p1->next = NULL;//单独取出p1 使得可以放进insert函数中进行遍历插入。
        p3 = insert(p3, p1);//把得到的p3已有的链表 一个个搭建起来 然后每有一个新结点 都插入合适位置。
        p1 = p2;
    }
    return p3;
}

main()
{
    struct student* head, * stu;
    int n;
    scanf("%d", &n);
    head = create(n);
    print(head);
    head = sort(head);
    print(head);
}