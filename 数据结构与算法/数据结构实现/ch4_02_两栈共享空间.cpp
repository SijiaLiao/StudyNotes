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
	int top1;
	int top2;
}SqDoubleStack;

Status visit(ElemType e){
	cout<<e<<" ";
	return OK;
}

// �����ջ
Status InitStack(SqDoubleStack *S){
	S->top1 = -1;
	S->top2 = MAXSIZE;
	return OK;
}

// �ÿ�ջ
Status ClearStack(SqDoubleStack *S){
	S->top1 = -1;
	S->top2 = MAXSIZE;
	return OK;
} 

// �ж�ջ�Ƿ�Ϊ�� 
Status StackEmpty(SqDoubleStack *S){
	if(S->top1 == -1 && S->top2 == MAXSIZE) return TRUE;
	return FALSE; 
}

// ����S��Ԫ�ظ�����������ջ���ܳ���
int StackLength(SqDoubleStack S){
	return S.top1+1+MAXSIZE-S.top2;
} 

// ����Ԫ��eΪ�µ�ջ��Ԫ��
Status Push(SqDoubleStack *S, ElemType e, int stackNumber){
	if(S->top1+1==S->top2) return ERROR; //ջ��
	
	if(stackNumber==1) S->data[++S->top1]=e;
	else if(stackNumber==2) S->data[--S->top2]=e;
	
	return OK;
} 

// ɾ��ջ��Ԫ��
Status Pop(SqDoubleStack *S, ElemType *e, int stackNumber){
	if(S->top1==-1 && stackNumber == 1) return ERROR; //ջ�� 
	if(S->top2 == MAXSIZE && stackNumber == 2) return ERROR;
	
	if(stackNumber == 1) *e = S->data[S->top1--];
	else if(stackNumber == 2) *e = S->data[S->top2--];
	
	return OK;
} 

Status StackTraverse(SqDoubleStack S){
	int i=0;
	cout<<"ջ1��"; 
	while(i<=S.top1) visit(S.data[i++]);
	cout<<endl;
	cout<<"ջ2��";
	i=MAXSIZE-1;
	while(i>=S.top2) visit(S.data[i--]);
	cout<<endl;
	return OK; 
}

int main(){
	SqDoubleStack S;
	cout<<InitStack(&S)<<endl;
	for(int i=1; i<=5; i++) Push(&S,i,1);
	for(int i=1; i<=5; i++) Push(&S,i,2);
	StackTraverse(S);
	int e;
	Pop(&S,&e,1);
	StackTraverse(S);
	return 0;
}



























 
