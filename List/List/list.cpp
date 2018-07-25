#include"list.h"
/*--------------��̬˳���----------------*/
int InitList(SqList &L) { /* �������������һ���յ�˳�����Ա� */
    L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem) {
        printf("����ʧ�ܣ�\n");
        exit(-2);
    }
    L.length = 0; /* �ձ���Ϊ0 */
    L.listsize = LIST_INIT_SIZE; /* ��ʼ�洢���� */
    return 0;
}

int DestroyList(SqList &L) { /* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������˳�����Ա�L */
    free(L.elem);
    L.elem = NULL;
    L.length = 0;
    L.listsize = 0;
    printf("���Ա��Ѿ��ͷţ�\n");
    return 0;
}

int ListInsert(SqList &L, int i, ElemType e) {
    /* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L)+1 */
    /* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
    ElemType *newbase = NULL;
    if (i<1 || i>L.length + 1) { /* iֵ���Ϸ� */
        printf("����λ�ò��Ϸ���/n");
        return -1;
    }
    if (L.length >= L.listsize) {/* ��ǰ�洢�ռ�����,���ӷ��� */
        newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        //ʹ��realloc�����޸�ԭ���Ѿ������˵��ڴ��Ĵ�С�������������ԭ�ȵ�������Ȼ����
        if (!newbase) {
            printf("����ʧ��!\n");
            exit(-2);
        }
        L.elem = newbase; /* �»�ַ */
        L.listsize += LISTINCREMENT; /* ���Ӵ洢���� */
    }
    for (int j = L.length; j >= i; j--) {
        L.elem[j] = L.elem[j - 1];
    }
    L.elem[i - 1] = e;
    L.length++; /* ����1 */
    free(newbase);
    newbase = NULL;
    return 0;
}

int LocateElem(SqList L, ElemType e) {
    int temp = 0;
    for (int i = 0; i<L.length; i++) {
        if (L.elem[i] == e) {
            printf("λ����%d:\n", i + 1);
        }
        else {
            temp++;
        }
    }
    if (temp == L.length) {
        printf("Not Found!\n\n");
        return -1;
    }
    return 0;
}

int DeleElem(SqList &L, int i, ElemType &x) {
    //ɾ����i(1��i��n)��λ���ϵ�����������ڣ�������x����ɾ������
    if (!L.length) {
        printf("���Ѿ����ˣ�����ɾ����\n");
        return -1;
    }
    if (i<1 || i>L.length) {
        printf("ɾ��λ�÷Ƿ���\n");
        return -1;
    }
    x = L.elem[i - 1];
    for (int j = i; j < L.length; j++) {
        L.elem[j - 1] = L.elem[j];
    }
    L.length--;
    printf("��%d��λ����ɾ����Ԫ����:%d\n", i, x);
    return 0;
}

int main() {
    SqList L;
    //��ʼ��
    InitList(L);
    printf("��ʼ��L��:L.length=%d	L.listsize=%d\n", L.length, L.listsize);
    printf("��ʼ��ok!\n\n");
    //���루ͷ�壩
    for (int j = 1; j <= 5; j++) {
        ListInsert(L, 1, j);
    }
    printf("��L�ı�ͷ���β���1��5:\n");
    for (int j = 1; j <= 5; j++) {
        printf("%d ", *(L.elem + j - 1));
    }
    printf("����ok��\n\n");
    //��ֵ����,��λĳ��ֵ���ڵ�λ��
    LocateElem(L, 7);
    //ɾ��Ԫ�ز���
    int k = 0;
    DeleElem(L, 5, k);  
    //�ͷŶ�̬˳���
    DestroyList(L);
    getchar();
}
