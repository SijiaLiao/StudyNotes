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

// 构造空栈
Status InitStack(SqDoubleStack *S){
	S->top1 = -1;
	S->top2 = MAXSIZE;
	return OK;
}

// 置空栈
Status ClearStack(SqDoubleStack *S){
	S->top1 = -1;
	S->top2 = MAXSIZE;
	return OK;
} 

// 判断栈是否为空 
Status StackEmpty(SqDoubleStack *S){
	if(S->top1 == -1 && S->top2 == MAXSIZE) return TRUE;
	return FALSE; 
}

// 返回S的元素个数，即两个栈的总长度
int StackLength(SqDoubleStack S){
	return S.top1+1+MAXSIZE-S.top2;
} 

// 插入元素e为新的栈顶元素
Status Push(SqDoubleStack *S, ElemType e, int stackNumber){
	if(S->top1+1==S->top2) return ERROR; //栈满
	
	if(stackNumber==1) S->data[++S->top1]=e;
	else if(stackNumber==2) S->data[--S->top2]=e;
	
	return OK;
} 

// 删除栈顶元素
Status Pop(SqDoubleStack *S, ElemType *e, int stackNumber){
	if(S->top1==-1 && stackNumber == 1) return ERROR; //栈空 
	if(S->top2 == MAXSIZE && stackNumber == 2) return ERROR;
	
	if(stackNumber == 1) *e = S->data[S->top1--];
	else if(stackNumber == 2) *e = S->data[S->top2--];
	
	return OK;
} 

Status StackTraverse(SqDoubleStack S){
	int i=0;
	cout<<"栈1："; 
	while(i<=S.top1) visit(S.data[i++]);
	cout<<endl;
	cout<<"栈2：";
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



























 
