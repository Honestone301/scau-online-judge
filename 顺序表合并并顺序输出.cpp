#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<stdio.h>
#include<malloc.h>
#define OK 1 
#define ERROR 0
#define LISTINCREMENT 10
#define ElemType int


typedef struct
{
	int* elem;
	int length;
}SqList;


ElemType InitList_Sq(SqList& L,int n)
{
	// 算法2.3，构造一个空的线性表L，该线性表预定义大小为n
	// 请补全代码
	L.elem = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n;i++) {
		scanf("%d",&L.elem[i]);
	}
	L.length=n;
	return OK;
}


int printSq(SqList& L)
{
	// 输出顺序表中的所有元素
	int i;
	if (L.length == 0) {
		printf("The List is empty!");
		return ERROR;
	}// 请填空
	else
	{
		printf("The List is: ");
		for (i = 0; i <= L.length - 1;i++) printf("%d ",L.elem[i]);  // 请填空
	}
	printf("\n");
	return OK;
}

int merge(SqList &A, SqList &B,SqList &C,int a,int b) {

	int c = a + b;
	C.elem = (int*)malloc(c * sizeof(int));
	C.length = c;
	int i = 0, j = 0, k = 0;

	while (i < A.length && j < B.length) {
		if (A.elem[i] < B.elem[j]) {
			C.elem[k++] = A.elem[i++];
		}
		else {
			C.elem[k++] = B.elem[j++];
		}
	}

	while (i < A.length) {
		C.elem[k++] = A.elem[i++];
	}

	while (j < B.length) {
		C.elem[k++] = B.elem[j++];
	}

	C.length = k;
	return OK;
}


int main()
{
	SqList A;
	SqList B;
	int a, b;
	scanf("%d", &a);


	if (InitList_Sq(A, a) == ERROR)    // 判断顺序表是否创建成功
	{
		return 0;
	}
	else {
		printf("List A:");
		for (int i = 0; i < a;i++) {
			printf("%d ", A.elem[i]);
		}
		printf("\n");
	}
	scanf("%d", &b);
	if (InitList_Sq(B, b)==ERROR)    // 判断顺序表是否创建成功
	{
		return 0;
	}
	else {
		printf("List B:");
		for (int i = 0; i < b; i++) {
			printf("%d ", B.elem[i]);
		}
		printf("\n");
	}
	int c = a + b;
	SqList C;
	if (merge(A,B,C,a,b) == ERROR)    // 判断顺序表是否创建成功
	{
		return 0;
	}
	
	else {
		printf("List C:");
		for (int i = 0; i < c; i++) {
			printf("%d ", C.elem[i]);
		}
		printf("\n");
	}
	free(A.elem);
	free(B.elem);
	free(C.elem);

	return 0;

}

