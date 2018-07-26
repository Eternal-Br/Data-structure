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
	//������Ų��ҵ�������ͷ�ڵ㣩�е�i���ڵ㣬����ָ��
	if (i <= 0) {
		printf("λ�ò��Ϸ���\n");
		return  NULL;
	}
	LinkList  p = L->next;;
	int k = 1;//����������
	while (p != NULL && k < i) {
		p = L->next;
		k++;
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
	//�ڣ���ͷ��㣩������ĵ�i��λ�ò������ֵ�Ľڵ㣬�ȼ��λ���Ƿ�Ϸ�
	//���ڴ������ͷ��㣬���κ�λ�õĲ�����һ��
	//��ε���̲��޴˴��룬�������̲ķֿ���������������ͷ�ڵ�ʱ��������
	LinkList  p = GetElem(L, i-1);//��ȡ��i-1�����
	if (p == NULL) {
		printf("����λ�ò��Ϸ���\n");
		exit(-1);
	}
	//���λ�úϷ���֮���ٿ�ʼ�������
	LinkList newNode = (LinkList)malloc(sizeof(LNode));
	if (!newNode) {
		printf("�ռ����ʧ�ܣ�\n");
		exit(-2);
	}
	newNode->data = e;
	newNode->next = p->next;
	p->next = newNode;
	printf("����ɹ���\n\n");
	return 0;
}

int DeleNode(LinkList& L, int i, ElemType& e) {
	//ɾ����ͷ�ڵ������ĵ�i���ڵ�,�����ظýڵ��ֵ
	//���ڴ������ͷ��㣬���κ�λ�õĲ�����һ��
	//��ε���̲��޴˴��룬�������̲ķֿ���������������ͷ�ڵ�ʱ��ɾ�����
	LinkList  p = GetElem(L, i - 1);
	if (p == NULL) {
		printf("ɾ��λ�ò��Ϸ���\n");
		exit(-1);
	}
	LinkList q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	printf("ɾ���ɹ���\n\n");
	return e;
}

int ErgodicL(LinkList& L) {
	if (L->next== NULL) {
		printf("	�Ѿ������һ��Ԫ���ˣ�\n\n");
		return 0;
	}
	printf("%4d", L->data);
	ErgodicL(L->next);
}