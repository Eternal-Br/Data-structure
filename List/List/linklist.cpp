#include"list.h"

LinkList CreatLinkList_HeadInsert(LinkList& L) {
	//ͷ�巨����������ÿ�ζ���ͷ�ڵ�ĺ������
	LinkList temp;
	int x;
	L = (LinkList)malloc(sizeof(LNode));//Create HEAD node
	if (!L) {
		printf("����ʧ�ܣ�\n\n");
		exit(-2);
	}
	L->next = NULL;
	printf("��Ҫͷ�崴������������ڵ��ֵ������999������\n");
	scanf("%d", &x);
	while (x != 999) {
		temp = (LinkList)malloc(sizeof(LNode));
		temp->data = x;
		temp->next = L->next;
		L->next = temp;
		scanf("%d", &x);
	}
	return L;
}

LinkList CreatLinkList_TailInsert(LinkList& L) {
	//β�巨������������Ҫ����һ��βָ��r
	int x;
	LinkList s, r;
	L = (LinkList)malloc(sizeof(LNode));
	r = L;
	printf("��Ҫβ�崴������������ڵ��ֵ������999������\n");
	scanf("%d", &x);
	while (x != 999) {
		s = (LinkList)malloc(sizeof(LNode));
		s->data = x;
		s->next = NULL;
		r->next = s;
		r = s;
	}
	return L;

}

LNode* GetElem(LinkList L, int i) {
	//������Ų��ҵ�������ͷ�ڵ㣩�е�i���ڵ��ֵ
	int j = 1;
	LinkList  p = L->next;;
	if (i == 0) {
		return L;
	}
	if (i < 1)
		return NULL;
	while (p && (j < i)) {
		p = p->next;
		j++;
	}
	return p;
}

LNode* LocateElem(LinkList L, ElemType e) {
	//���ҵ�������ͷ�ڵ㣩�����������Ƿ��е��ڸ�����ֵ�����У����ظýڵ��ָ�루��һ���������򷵻�NULL
	LinkList p = L->next;
	while ((p != NULL) && (p->data != e)) {
		p = p->next;
	}
	return p;
}

int InsertNode(LinkList& L, int i, ElemType e ) {
	//�ڵ�i��λ�ò������ֵ�Ľڵ�
}

int DeleNode(LinkList& L, int i, ElemType& e) {
	//ɾ����i���ڵ�,�����ظýڵ��ֵ
}