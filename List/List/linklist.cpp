#include"list.h"

LinkList CreatLinkList_HeadInsert(LinkList& L) {
	//ͷ�巨����������ÿ�ζ���ͷ�ڵ�ĺ������
	LNode* temp;
	int x;
	L = (LNode*)malloc(sizeof(LNode));//Create HEAD node
	if (!L) {
		printf("����ʧ�ܣ�\n\n");
		exit(-2);
	}
	L->next = NULL;
	printf("������ڵ��ֵ������999������\n");
	scanf("%d", &x);
	while (x != 999) {
		temp = (LNode*)malloc(sizeof(LNode));
		temp->data = x;
		temp->next = L->next;
		L->next = temp;
		scanf("%d", &x);
	}
	return L;
}

LinkList CreatLinkList_TailInsert(LinkList& L) {

}

LNode* GetElem(LinkList L, int i) {

}

LNode* LocateElem(LinkList L, ElemType e) {

}

int InsertNode(LinkList& L, int i, ElemType e ) {
	//�ڵ�i��λ�ò������ֵ�Ľڵ�
}

int DeleNode(LinkList& L, int i, ElemType& e) {
	//ɾ����i���ڵ�,�����ظýڵ��ֵ
}