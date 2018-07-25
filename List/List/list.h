#pragma once
/* c1.h (程序名) */
#define _CRT_SECURE_NO_DEPRECATE

#include<malloc.h> /* malloc()等 */
#include<stdio.h> /* EOF(=^Z或F6),NULL */
#include<stdlib.h>
#define LIST_INIT_SIZE 10 /* 线性表存储空间的初始分配量 */
#define LISTINCREMENT 2 /* 线性表存储空间的分配增量 */
typedef int ElemType;

typedef struct {
    ElemType *elem; /* 存储空间基址 */
    int length; /* 当前长度 */
    int listsize; /* 当前分配的存储容量(以sizeof(ElemType)为单位) */
}SqList;

typedef struct LNode {
	ElemType data;
	LNode* next;
}*LinkList;
//*LinkList型用于实现LNode型的指针，LNode用于实现头节点和普通节点

//值得注意的是，这里如果写成下面这种形式:
//typedef struct  {
//	ElemType data;
//	struct LNode* next;
//}LNode, *LinkList;
//后续代码在linklist.cpp的CreatLinkliat_HeadInsert()函数中
//L->next = temp; 
//处就会报错："不能将LNode*型的值分配到LNode*型变量"
//这个地方有点问题，因为结构体定义中出现了struct Lnode但 Lnode这个名字却是在下一行出现的，于是把编译器弄懵了
