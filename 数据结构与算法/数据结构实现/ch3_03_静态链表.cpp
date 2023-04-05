#include<stdio.h>
#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20

typedef int Status;
typedef int ElemType;

Status visit(ElemType c){
	printf("%c ", c);
	return OK;
}

/*线性表的静态链表存储结构*/
// 使用结构体数组作为静态链表的载体 
// 将第一个元素的cur赋为备用链表第一个结点的下标
// 将最后一个元素的cur赋为链表一个结点的下标，即可看作为头结点 
// cur=0 即无指向 
typedef struct{
	ElemType data;
	int cur; /*游标，为0时无指向*/
}Component, StaticLinkList[MAXSIZE];


// 将一维数组space中各分量链成一个备用链表  
Status InitList(StaticLinkList  space){
	for(int i=0; i<MAXSIZE-1; i++) space[i].cur = i+1;
	space[MAXSIZE-1].cur = 0;
	return OK;
}

// 若备用空间链表非空，则返回分配的结点下标，否则返回0
int Malloc_SSL(StaticLinkList space){
	
	int i = space[0].cur; // 当前数组第一个元素的cur寸的值 
						  // 我们希望返回链表的一个空闲块的下标
	if(space[0].cur) space[0].cur = space[i].cur; 
					      // 由于现在要分配一个空闲块出去
					      // 所以需要保存分配出去块的游标作为下一个空闲块 
	space[i].cur = 0;// 分配出去的空闲块指向0 
	return i;
} 


// 将下标为k的空闲结点回收到备用链表中 
void Free_SSL(StaticLinkList space, int k){
	space[k].cur = space[0].cur; // 将第一个元素链接到k，
								 // 然后让k链接到原本一个元素所链接的值 
	space[0].cur = k;
} 

// 返回静态链表中元素的个数，即链表长度
int ListLength(StaticLinkList L){
	int j = 0;
	int i = L[MAXSIZE-1].cur;
	while(i){
		i = L[i].cur;
		j++;
	} 
	return j;
} 

// 在L中第i个元素之前插入新的数据元素e
Status ListInsert(StaticLinkList L, int i, ElemType e){
	int j, k;
	k = MAXSIZE - 1;
	if(i<1 || i>ListLength(L)+1) return ERROR;
	j = Malloc_SSL(L); //获取空闲分量的下标
	if(j){
		L[j].data = e;
		for(int l=1; l<i; l++) k = L[k].cur; //找到第i-1个元素的下标 
		L[j].cur = L[k].cur;
		L[k].cur = j;
		return OK;
	} 
	return ERROR;
} 


// 删除在L中的第i个元素
Status ListDelete(StaticLinkList L, int i){
	if(i<1 || i>ListLength(L)) return ERROR;
	int k = MAXSIZE - 1;
	for(int j=1; j<i; j++) k = L[k].cur;
	int l = L[k].cur;
	L[k].cur = L[l].cur;
	Free_SSL(L, l);
	return OK; 
} 


// 遍历链表的所有元素
Status ListTraverse(StaticLinkList L){
	int i = L[MAXSIZE-1].cur;
	while(i){
		cout<<L[i].data<<" ";
		i = L[i].cur;
	} 
	cout<<endl;
	return OK;
} 


int main(){
	StaticLinkList L;
	cout<<InitList(L)<<endl;
	for(int i=1;i<=5;i++) ListInsert(L,i,i);
	ListTraverse(L);
	ListDelete(L,3);
	ListTraverse(L);
	return 0;
}

































