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

// ��� = ָ�� + Ԫ��ֵ
typedef struct Node{
	ElemType data;
	Node *next; //ָ����һ������ָ�� 
}Node; 

// ���� 
typedef struct Node *LinkList; 

/*��ʼ��˳�����Ա�:����ͷ���*/
Status InitList(LinkList *L){
	// malloc ���ط���ռ��ָ�� 
	*L = (LinkList)malloc(sizeof(Node)); // ����ͷ��㣬��ʹLָ���ͷ��� 
	if(!(*L)) return ERROR;
	(*L)->next = NULL;
	return OK; 
} 

/*�ж������Ƿ�Ϊ��:������ͷ��㣬Ϊ�ռ�������Ԫ��*/
Status ListEmpty(LinkList L){
	if(L->next) return FALSE;
	else return TRUE;
} 

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
Status ClearList(LinkList *L){
	LinkList p, q;
	p = (*L)->next; /* pָ���һ����� */
	while(p){
		q = p->next;
		free(p);
		p = q;
	}  
	(*L)->next = NULL;  /* ͷ���ָ����Ϊ�� */
	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
int ListLength(LinkList L){
	int i =0;
	LinkList p = L->next;
	while(p){
		i++;
		p = p->next;
	}
	return i;
}


/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* �����������e����L�е�i������Ԫ�ص�ֵ */
Status GetItem(LinkList L, int i, ElemType *e){
	LinkList p = L->next; // ��pָ��ָ���һ����� 
	int j = 1;
	while(p && j<i){ //p������δ�ﵽ��i��Ԫ�� 
		p = p->next;
		j++;
	} 
	if(!p || j>i) return ERROR;
	*e = p->data;
	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* �������������L�е�1����e�����ϵ������Ԫ�ص�λ�� */
/* ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */
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

/* ��ʼ������˳�����Ա�L�Ѵ���,1��i��ListLength(L)�� */
/* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
Status ListInsert(LinkList *L, int i, ElemType e){
	
	
	LinkList p = *L;
	int j=1;
	while(p && j<i){ //����i-1��ͣ�� 
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

/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 */
Status ListDelete(LinkList *L, int i, ElemType *e){
	
	LinkList p = *L;
	int j = 1;
	while(p && j<i){// ��Ȼ�ҵ���i-1��Ԫ��
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
	cout<<"��ʼ������"<< InitList(&L)<<endl;
	for(int i=1;i<=5;i++) ListInsert(&L,i,i);
	// ɾ����5��Ԫ��
	ListDelete(&L, 6, &a);
	for(int i=1; i<=5; i++){
		L = L->next;
		cout<<L->data<<" ";
	} 
	return 0;
}


































