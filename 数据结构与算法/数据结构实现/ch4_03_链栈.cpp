#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status; 
typedef int ElemType; /* SElemType类型根据实际情况而定，这里假设为int */

// 链栈解构
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

// 构造空栈
Status InitStack(LinkStack *S){
	S->top = NULL;
	S->count = 0;
	return OK;
} 

// 将栈置为空栈
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

// 判断栈是否为空
Status StackEmpty(LinkStack S){
	if(S.count == 0) return TRUE;
	else return FALSE;
} 

// 返回栈的长度
int StackLength(LinkStack S){
	return S.count;
} 

// 若栈不空，则用e返回S的栈顶元素
Status GetTop(LinkStack S, ElemType *e){
	if(S.count == 0) return ERROR;
	*e = S.top->data;
	return OK;
} 

// 插入元素e为新的栈顶元素
Status Push(LinkStack *S, ElemType e){
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = e;
	p->next = S->top; // 将当前的栈顶元素赋值给新结点的直接后继 
	S->top = p; // 将新的结点p赋值给栈顶指针 
	S->count++;
	return OK;
} 

// 若栈不空，则删除栈顶元素，用e返回其值
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

// 遍历链表
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
	cout<<"栈中元素依次为: ";
	StackTraverse(S);
	return 0; 
}































