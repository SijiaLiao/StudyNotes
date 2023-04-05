#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* �洢�ռ��ʼ������ */

typedef int Status; 
typedef int ElemType; /* SElemType���͸���ʵ������������������Ϊint */

// ��ջ�⹹
typedef struct StackNode{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr; 

typedef struct{
	LinkStackPtr top;
	int count;
}LinkStack;

Status visit(ElemType e){
	cout<<e<<" ";
	return 0;
}

// �����ջ
Status InitStack(LinkStack *S){
	S->top = NULL;
	S->count = 0;
	return OK;
} 

// ��ջ��Ϊ��ջ
Status ClearStack(LinkStack *S){
	LinkStackPtr p,q;
	p = S->top;
	while(p){
		q = p;
		p = p->next;
		free(q);
	}
	S->count =0;
	return 0;
} 

// �ж�ջ�Ƿ�Ϊ��
Status StackEmpty(LinkStack S){
	if(S.count == 0) return TRUE;
	else return FALSE;
} 

// ����ջ�ĳ���
int StackLength(LinkStack S){
	return S.count;
} 

// ��ջ���գ�����e����S��ջ��Ԫ��
Status GetTop(LinkStack S, ElemType *e){
	if(S.count == 0) return ERROR;
	*e = S.top->data;
	return OK;
} 

// ����Ԫ��eΪ�µ�ջ��Ԫ��
Status Push(LinkStack *S, ElemType e){
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = e;
	p->next = S->top; // ����ǰ��ջ��Ԫ�ظ�ֵ���½���ֱ�Ӻ�� 
	S->top = p; // ���µĽ��p��ֵ��ջ��ָ�� 
	S->count++;
	return OK;
} 

// ��ջ���գ���ɾ��ջ��Ԫ�أ���e������ֵ
Status Pop(LinkStack *S, ElemType *e){
	if(S->count==0) return ERROR;
	LinkStackPtr p;
	p = S->top;
	*e = p->data;
	S->top = p->next;
	free(p);
	S->count--;
	return OK;
} 

// ��������
Status StackTraverse(LinkStack S){
	LinkStackPtr p;
	p = S.top;
	while(p){
		visit(p->data);
		p = p->next; 
	} 
	cout<<endl;
	return OK;
} 

int main(){
	LinkStack S;
	int e;
	cout<<InitStack(&S)<<endl;
	for(int i=1; i<=10; i++) Push(&S,i);
	cout<<"ջ��Ԫ������Ϊ: ";
	StackTraverse(S);
	return 0; 
}































