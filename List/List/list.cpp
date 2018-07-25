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
            printf("���ҵ�Ԫ��λ����%d:\n\n", i + 1);
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
    printf("ɾ���ĵ�%d��λ����ɾ����Ԫ����:%d\n\n", i, x);
    return 0;
}

int Ergodic(SqList L) {
    if (!L.length) {
        printf("���Ѿ�����,û�б����ˣ�\n\n");
        return -1;
    }
    printf("���е�����Ϊ:");
    for (int i = 0; i < L.length; i++) {       
        printf("%4d ", L.elem[i]);       
    }
    printf("\n\n");
    return 0;
}

ElemType DeleMinElem(SqList &L) {
    //ɾ����СԪ�أ�����Ψһ
    if (!L.length) {
        printf("���Ա��ѿգ�\n\n");
        exit(1);
    }
    int i = 0, j = 0;
    for (i = 0; i < L.length; i++) {
        if (L.elem[i] < L.elem[j]) {
            j = i;
        }
    }
    ElemType temp =  L.elem[j];
    L.elem[j] = L.elem[i];
    L.length--;
    return temp;
}

int ReverseList(SqList &L) {
    //����˳���
    if (!L.length) {
        printf("���Ա��ѿգ�\n\n");
        exit(1);
    }
    ElemType temp;
    for (int i = 0; i < (L.length / 2);i++) {
        temp = L.elem[i];
        L.elem[i] = L.elem[L.length - i - 1];
        L.elem[L.length - i - 1] = temp;
    }
    printf("˳����Ѿ����ã�\n");
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
    Ergodic(L);//����˳���
    printf("����ok��\n\n");
    //����˳������
    ReverseList(L);
    printf("���ú�����Ա�����:\n");
    Ergodic(L);//����˳���
    //��ֵ����,��λĳ��ֵ���ڵ�λ��
    LocateElem(L, 7);
    //ɾ����С��Ԫ�ز���
    printf("�����Ա�����С��Ԫ����:%4d\n\n", DeleMinElem(L));

    //ɾ��Ԫ�ز���
    int k = 0;
    DeleElem(L, 2, k);  
    printf("ɾ�����ݺ�:\n");
    Ergodic(L);
    //�ͷŶ�̬˳���
    DestroyList(L);
    getchar();
}
//
//
