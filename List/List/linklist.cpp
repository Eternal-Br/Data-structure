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
	//按照序号查找单链表（带头节点）中第i个节点，返回指针
	if (i <= 0) {
		printf("位置不合法！\n");
		return  NULL;
	}
	LinkList  p = L->next;;
	int k = 1;//辅助计数器
	while (p != NULL && k < i) {
		p = L->next;
		k++;
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
	//在（带头结点）的链表的第i个位置插入给定值的节点，先检查位置是否合法
	//由于此链表带头结点，在任何位置的操作都一样
	//严蔚敏教材无此代码，殷人昆教材分开考虑了链表有无头节点时的添加情况
	LinkList  p = GetElem(L, i-1);//获取第i-1个结点
	if (p == NULL) {
		printf("插入位置不合法！\n");
		exit(-1);
	}
	//检查位置合法性之后再开始插入操作
	LinkList newNode = (LinkList)malloc(sizeof(LNode));
	if (!newNode) {
		printf("空间分配失败！\n");
		exit(-2);
	}
	newNode->data = e;
	newNode->next = p->next;
	p->next = newNode;
	printf("插入成功！\n\n");
	return 0;
}

int DeleNode(LinkList& L, int i, ElemType& e) {
	//删除带头节点的链表的第i个节点,并返回该节点的值
	//由于此链表带头结点，在任何位置的操作都一样
	//严蔚敏教材无此代码，殷人昆教材分开考虑了链表有无头节点时的删除情况
	LinkList  p = GetElem(L, i - 1);
	if (p == NULL) {
		printf("删除位置不合法！\n");
		exit(-1);
	}
	LinkList q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	printf("删除成功！\n\n");
	return e;
}

int ErgodicL(LinkList& L) {
	if (L->next== NULL) {
		printf("	已经是最后一个元素了！\n\n");
		return 0;
	}
	printf("%4d", L->data);
	ErgodicL(L->next);
}