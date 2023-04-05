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
	int top; // 用于栈顶指针 
}SqStack;

Status visit(ElemType e){
	cout<<e<<" ";
	return OK;
}

// 构造空栈
Status InitStack(SqStack *S){
	S->top = -1;
	return OK;
} 

// 置空栈
Status ClearStack(SqStack *S){
	S->top = -1;
	return OK;
} 
// 判断栈是否为空
Status StackEmpty(SqStack S){
	if(S.top == -1) return TRUE;
	else return FALSE;
} 

// 返回栈的长度
int StackLength(SqStack S){
	return S.top+1;
} 

// 若栈不空，用e返回栈顶元素
Status GetTop(SqStack S, ElemType *e){
	if(S.top == -1) return ERROR;
	*e = S.data[S.top];
	return OK;
} 

// 插入新的元素e为栈顶元素
Status Push(SqStack *S, ElemType e){
	if(S->top == MAXSIZE-1) return ERROR;
	S->top ++; //栈指针指向栈顶元素 
	S->data[S->top] = e;
	
	return OK; 
} 

// 若栈不空，弹出栈顶元素并返回
Status Pop(SqStack *S, ElemType *e){
	if(S->top == -1) return ERROR;
	S->top --;
	*e = S->data[S->top + 1];
	return OK;
} 

// 从栈顶依次显示栈中元素
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

























