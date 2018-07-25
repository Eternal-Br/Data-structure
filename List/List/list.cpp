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
    ElemType *newbase;
    if (i<1 || i>L.length + 1) { /* iֵ���Ϸ� */
        printf("����λ�ò��Ϸ���/n");
        return -1;
    }
    if (L.length >= L.listsize) {/* ��ǰ�洢�ռ�����,���ӷ��� */
        newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
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
    //�ͷŶ�̬˳���
    DestroyList(L);
    getchar();
}
