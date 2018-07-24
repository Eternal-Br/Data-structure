#include"list.h"
/*--------------动态顺序表----------------*/
int InitList(SqList &L) { /* 操作结果：构造一个空的顺序线性表 */
    L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem) {
        printf("分配失败！\n");
        exit(-2);
    }
    L.length = 0; /* 空表长度为0 */
    L.listsize = LIST_INIT_SIZE; /* 初始存储容量 */
    return 0;
}

int DestroyList(SqList &L) { /* 初始条件：顺序线性表L已存在。操作结果：销毁顺序线性表L */
    free(L.elem);
    L.elem = NULL;
    L.length = 0;
    L.listsize = 0;
    printf("线性表已经释放！\n");
    return 0;
}

int ListInsert(SqList &L, int i, ElemType e) {
    /* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L)+1 */
    /* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
    ElemType *newbase;
    if (i<1 || i>L.length + 1) { /* i值不合法 */
        printf("插入位置不合法！/n");
        return -1;
    }
    if (L.length >= L.listsize) {/* 当前存储空间已满,增加分配 */
        newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase) {
            printf("分配失败!\n");
            exit(-2);
        }
        L.elem = newbase; /* 新基址 */
        L.listsize += LISTINCREMENT; /* 增加存储容量 */
    }
    for (int j = L.length; j >= i; j--) {
        L.elem[j] = L.elem[j - 1];
    }
    L.elem[i - 1] = e;
    L.length++; /* 表长增1 */
    return 0;
}

int LocateElem(SqList L, ElemType e) {
    int temp = 0;
    for (int i = 0; i<L.length; i++) {
        if (L.elem[i] == e) {
            printf("位置在%d:\n", i + 1);
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
    //初始化
    InitList(L);
    printf("初始化L后:L.length=%d	L.listsize=%d\n", L.length, L.listsize);
    printf("初始化ok!\n\n");
    //插入（头插）
    for (int j = 1; j <= 5; j++) {
        ListInsert(L, 1, j);
    }
    printf("在L的表头依次插入1～5:\n");
    for (int j = 1; j <= 5; j++) {
        printf("%d ", *(L.elem + j - 1));
    }
    printf("插入ok！\n\n");
    //按值查找,定位某个值所在的位置
    LocateElem(L, 7);
    //释放动态顺序表
    DestroyList(L);
    getchar();
}
