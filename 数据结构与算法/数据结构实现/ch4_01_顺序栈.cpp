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

typedef struct{
	ElemType data[MAXSIZE];
	int top; // ����ջ��ָ�� 
}SqStack;

Status visit(ElemType e){
	cout<<e<<" ";
	return OK;
}

// �����ջ
Status InitStack(SqStack *S){
	S->top = -1;
	return OK;
} 

// �ÿ�ջ
Status ClearStack(SqStack *S){
	S->top = -1;
	return OK;
} 
// �ж�ջ�Ƿ�Ϊ��
Status StackEmpty(SqStack S){
	if(S.top == -1) return TRUE;
	else return FALSE;
} 

// ����ջ�ĳ���
int StackLength(SqStack S){
	return S.top+1;
} 

// ��ջ���գ���e����ջ��Ԫ��
Status GetTop(SqStack S, ElemType *e){
	if(S.top == -1) return ERROR;
	*e = S.data[S.top];
	return OK;
} 

// �����µ�Ԫ��eΪջ��Ԫ��
Status Push(SqStack *S, ElemType e){
	if(S->top == MAXSIZE-1) return ERROR;
	S->top ++; //ջָ��ָ��ջ��Ԫ�� 
	S->data[S->top] = e;
	
	return OK; 
} 

// ��ջ���գ�����ջ��Ԫ�ز�����
Status Pop(SqStack *S, ElemType *e){
	if(S->top == -1) return ERROR;
	S->top --;
	*e = S->data[S->top + 1];
	return OK;
} 

// ��ջ��������ʾջ��Ԫ��
Status StackTraverse(SqStack S){
	if(S.top == -1) return ERROR;
	int i = S.top;
	while(i != -1) visit(S.data[i--]);
	cout<<endl;
	return OK;
} 


int main(){
	SqStack S;
	cout<<InitStack(&S)<<endl;
	for(int i=1; i<=5; i++) Push(&S,i);
	StackTraverse(S);
	ElemType e;
	Pop(&S, &e);
	StackTraverse(S);
	return 0;
}

























