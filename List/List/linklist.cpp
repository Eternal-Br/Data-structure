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
	L->data = -1;
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
	printf("������ϣ�\n\n");
	return L;
}

LinkList CreatLinkList_TailInsert(LinkList& L) {
	//β�巨������������Ҫ����һ��βָ��r
	ElemType x;
	LinkList s, r;
	L = (LinkList)malloc(sizeof(LNode));
	L->data = -1;
	r = L;
	printf("��Ҫβ�崴������������ڵ��ֵ������999������\n");
	scanf("%d", &x);
	while (x != 999) {
		s = (LinkList)malloc(sizeof(LNode));
		s->data = x;
		s->next = NULL;
		r->next = s;
		r = s;
		scanf("%d",&x);
	}
	r->next = NULL;
	printf("������ϣ�\n\n");
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

int ErgodicLinkList(LinkList& L) {
	if (L->next == NULL) {
		printf("%4d	�Ѿ������һ��Ԫ���ˣ�\n\n",L->data);
		return 0;
	}
	printf("%4d", L->data);
	ErgodicLinkList(L->next);
}

LinkList ReverseLinkList(LinkList& L) {
	//�͵����ô�ͷ��������
	//����1��ʹ������ָ��pre, p, r�ֱ�ֻ���������������ڵ�Ԫ��
	//���α������Ա�����ָ�뷴ת
	//LinkList pre, p = L->next, r = p->next;
	//p->next = NULL;
	//while (r != NULL) {
	//	pre = p;
	//	p = r;
	//	r = r->next;
	//	p->next = pre;
	//}
	//L->next = p;
	//return L;

	//����2����ͷ�ڵ�ժ�£��ӵ�һ���ڵ㿪ʼ������ʹ��ͷ�巨�嵽ͷ�ڵ�ĺ���
	LinkList p, r;
	p = L->next;
	L->next = NULL;//��ͷ�ڵ�ժ��
	while (p != NULL){
		r = p->next;
		p->next = L->next;
		p = r;
	}
	return L;
}

void ReverseOutputLinkList(LinkList L) {
	//������������е�Ԫ��
	//���������ַ�����1.�������ã��������2.����ջ��3.�ݹ����
	//����д����3���ݹ����
	//������ͷ�ڵ��ֵ��ô��������
	if (L->next != NULL) {
		ReverseLinkList(L->next);
	}
	printf("%4d", L->data);
}

int main() {
	LinkList L1, L2;
	L1 = CreatLinkList_HeadInsert(L1);
	printf("\n�����������£�\n");
	ErgodicLinkList(L1);
	L2 = CreatLinkList_TailInsert(L2);
	printf("\n�����������£�\n");
	ErgodicLinkList(L2);
}