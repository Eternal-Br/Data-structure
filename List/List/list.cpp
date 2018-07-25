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
    ElemType *newbase = NULL;
    if (i<1 || i>L.length + 1) { /* i值不合法 */
        printf("插入位置不合法！/n");
        return -1;
    }
    if (L.length >= L.listsize) {/* 当前存储空间已满,增加分配 */
        newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        //使用realloc函数修改原先已经分配了的内存块的大小，如果用于扩大，原先的内容依然保存
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
    free(newbase);
    newbase = NULL;
    return 0;
}

int LocateElem(SqList L, ElemType e) {
    int temp = 0;
    for (int i = 0; i<L.length; i++) {
        if (L.elem[i] == e) {
            printf("查找的元素位置在%d:\n\n", i + 1);
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
    //删除第i(1≤i≤n)个位置上的数（如果存在），并用x返回删除的数
    if (!L.length) {
        printf("表已经空了，不能删除！\n");
        return -1;
    }
    if (i<1 || i>L.length) {
        printf("删除位置非法！\n");
        return -1;
    }
    x = L.elem[i - 1];
    for (int j = i; j < L.length; j++) {
        L.elem[j - 1] = L.elem[j];
    }
    L.length--;
    printf("删除的第%d个位置上删除的元素是:%d\n\n", i, x);
    return 0;
}

int Ergodic(SqList L) {
    if (!L.length) {
        printf("表已经空了,没有遍历了！\n\n");
        return -1;
    }
    printf("表中的内容为:");
    for (int i = 0; i < L.length; i++) {       
        printf("%4d ", L.elem[i]);       
    }
    printf("\n\n");
    return 0;
}

ElemType DeleMinElem(SqList &L) {
    //删除最小元素，假设唯一
    if (!L.length) {
        printf("线性表已空！\n\n");
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
    //逆置顺序表
    if (!L.length) {
        printf("线性表已空！\n\n");
        exit(1);
    }
    ElemType temp;
    for (int i = 0; i < (L.length / 2);i++) {
        temp = L.elem[i];
        L.elem[i] = L.elem[L.length - i - 1];
        L.elem[L.length - i - 1] = temp;
    }
    printf("顺序表已经逆置！\n");
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
    Ergodic(L);//遍历顺序表
    printf("插入ok！\n\n");
    //逆置顺序表测试
    ReverseList(L);
    printf("逆置后的线性表如下:\n");
    Ergodic(L);//遍历顺序表
    //按值查找,定位某个值所在的位置
    LocateElem(L, 7);
    //删除最小的元素测试
    printf("此线性表中最小的元素是:%4d\n\n", DeleMinElem(L));

    //删除元素测试
    int k = 0;
    DeleElem(L, 2, k);  
    printf("删除内容后:\n");
    Ergodic(L);
    //释放动态顺序表
    DestroyList(L);
    getchar();
}
//
//
