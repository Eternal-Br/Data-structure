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