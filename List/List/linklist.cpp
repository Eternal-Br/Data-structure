#include"list.h"

LinkList CreatLinkList_HeadInsert(LinkList& L) {
	//头插法建立单链表，每次都在头节点的后面插入
	LinkList temp;
	int x;
	L = (LinkList)malloc(sizeof(LNode));//Create HEAD node
	if (!L) {
		printf("创建失败！\n\n");
		exit(-2);
	}
	L->next = NULL;
	printf("将要头插创建链表，请输入节点的值，输入999结束：\n");
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
	//尾插法建立单链表，需要引入一个尾指针r
	int x;
	LinkList s, r;
	L = (LinkList)malloc(sizeof(LNode));
	r = L;
	printf("将要尾插创建链表，请输入节点的值，输入999结束：\n");
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
	//按照序号查找单链表（带头节点）中第i个节点的值
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
	//查找单链表（带头节点）中数据域中是否有等于给定的值，若有，返回该节点的指针（第一个），否则返回NULL
	LinkList p = L->next;
	while ((p != NULL) && (p->data != e)) {
		p = p->next;
	}
	return p;
}

int InsertNode(LinkList& L, int i, ElemType e ) {
	//在第i个位置插入给定值的节点
}

int DeleNode(LinkList& L, int i, ElemType& e) {
	//删除第i个节点,并返回该节点的值
}