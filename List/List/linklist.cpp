#include"list.h"

LinkList CreatLinkList_HeadInsert(LinkList& L) {
	//头插法建立单链表，每次都在头节点的后面插入
	LNode* temp;
	int x;
	L = (LNode*)malloc(sizeof(LNode));//Create HEAD node
	if (!L) {
		printf("创建失败！\n\n");
		exit(-2);
	}
	L->next = NULL;
	printf("请输入节点的值，输入999结束：\n");
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
	//在第i个位置插入给定值的节点
}

int DeleNode(LinkList& L, int i, ElemType& e) {
	//删除第i个节点,并返回该节点的值
}