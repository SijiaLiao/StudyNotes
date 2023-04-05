#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<io.h>
using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20

typedef int Status;
typedef int ElemType;

// 结点 = 指针 + 元素值
typedef struct Node{
	ElemType data;
	Node *next; //指向下一个结点的指针 
}Node; 

// 链表 
typedef struct Node *LinkList; 

/*初始化顺序线性表:创建头结点*/
Status InitList(LinkList *L){
	// malloc 返回分配空间的指针 
	*L = (LinkList)malloc(sizeof(Node)); // 产生头结点，并使L指向此头结点 
	if(!(*L)) return ERROR;
	(*L)->next = NULL;
	return OK; 
} 

/*判断链表是否为空:链表有头结点，为空即无数据元素*/
Status ListEmpty(LinkList L){
	if(L->next) return FALSE;
	else return TRUE;
} 

/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
Status ClearList(LinkList *L){
	LinkList p, q;
	p = (*L)->next; /* p指向第一个结点 */
	while(p){
		q = p->next;
		free(p);
		p = q;
	}  
	(*L)->next = NULL;  /* 头结点指针域为空 */
	return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(LinkList L){
	int i =0;
	LinkList p = L->next;
	while(p){
		i++;
		p = p->next;
	}
	return i;
}


/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值 */
Status GetItem(LinkList L, int i, ElemType *e){
	LinkList p = L->next; // 让p指针指向第一个结点 
	int j = 1;
	while(p && j<i){ //p存在且未达到第i个元素 
		p = p->next;
		j++;
	} 
	if(!p || j>i) return ERROR;
	*e = p->data;
	return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
int LocateElem(LinkList L, ElemType e){
	int i =0;
	LinkList p = L->next;
	while(p){
		i++;
		if(p->data == e) return i;
		p = p->next;
	}
	return 0;
} 

/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
Status ListInsert(LinkList *L, int i, ElemType e){
	
	
	LinkList p = *L;
	int j=1;
	while(p && j<i){ //到第i-1个停下 
		p = p->next;
		j++;
	}
	
	if(!p || j>i) return ERROR;
	LinkList s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	
	return OK; 
	
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(LinkList *L, int i, ElemType *e){
	
	LinkList p = *L;
	int j = 1;
	while(p && j<i){// 仍然找到第i-1个元素
		p = p -> next;
		j++;
	}	
	if(!(p->next)|| j>i) return ERROR;
	
	LinkList q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	
	return OK;	 
}



int main(){
	ElemType a;
	LinkList L; 
	cout<<"初始化链表："<< InitList(&L)<<endl;
	for(int i=1;i<=5;i++) ListInsert(&L,i,i);
	// 删除第5个元素
	ListDelete(&L, 6, &a);
	for(int i=1; i<=5; i++){
		L = L->next;
		cout<<L->data<<" ";
	} 
	return 0;
}


































