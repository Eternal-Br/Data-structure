#pragma once
/* c1.h (������) */
#define _CRT_SECURE_NO_DEPRECATE

#include<malloc.h> /* malloc()�� */
#include<stdio.h> /* EOF(=^Z��F6),NULL */
#include<stdlib.h>
#define LIST_INIT_SIZE 10 /* ���Ա�洢�ռ�ĳ�ʼ������ */
#define LISTINCREMENT 2 /* ���Ա�洢�ռ�ķ������� */
typedef int ElemType;

typedef struct {
    ElemType *elem; /* �洢�ռ��ַ */
    int length; /* ��ǰ���� */
    int listsize; /* ��ǰ����Ĵ洢����(��sizeof(ElemType)Ϊ��λ) */
}SqList;

typedef struct LNode {
	ElemType data;
	LNode* next;
}*LinkList;
//*LinkList������ʵ��LNode�͵�ָ�룬LNode����ʵ��ͷ�ڵ����ͨ�ڵ�

//ֵ��ע����ǣ��������д������������ʽ:
//typedef struct  {
//	ElemType data;
//	struct LNode* next;
//}LNode, *LinkList;
//����������linklist.cpp��CreatLinkliat_HeadInsert()������
//L->next = temp; 
//���ͻᱨ��"���ܽ�LNode*�͵�ֵ���䵽LNode*�ͱ���"
//����ط��е����⣬��Ϊ�ṹ�嶨���г�����struct Lnode�� Lnode�������ȴ������һ�г��ֵģ����ǰѱ�����Ū����
