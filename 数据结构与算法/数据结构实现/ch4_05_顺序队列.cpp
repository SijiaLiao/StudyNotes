#include<stdio.h>
#include<iostream>
using namespace std;

#define OK 0
#define ERROR 1
#define FALSE 0 
#define TRUE 1
#define MAXSIZE 20

typedef int Status;
typedef int ElemType;

// 循环队列的顺序存储结构
typedef struct{
	ElemType data[MAXSIZE];
	int front; //头指针 
	int rear; // 尾指针 
}SqQueue; 

Status visit(ElemType e){
	cout<<e<<" ";
	return 0;
} 

// 初始化一个空队列
Status InitQueue(SqQueue *Q){
	Q->front = 0;
	Q->rear = 0;
	return OK;
} 

// 清空队列
Status ClearQueue(SqQueue *Q){
	Q->front = Q->rear = 0;
	return OK;
} 

// 判断队列是否为空队列
Status QueueEmpty(SqQueue Q){
	if(Q.front == Q.rear) return TRUE; //队空的标志 
	else return FALSE;
} 

// 返回Q的元素的个数，即队列的当前长度
int QueueLength(SqQueue Q){
	return (MAXSIZE-Q.front+Q.rear) % MAXSIZE;
} 

// 若队列不空，则用e返回Q的对头元素
Status GetHead(SqQueue Q, ElemType *e){
	if(Q.front==Q.rear) return ERROR;
	*e = Q.data[Q.front];
	return OK;
} 

// 若队列未满，则插入元素e为Q的新的队尾元素
Status EnQueue(SqQueue *Q, ElemType e){
	if((Q->rear+1)%MAXSIZE == Q->front) return ERROR;
	Q->data[Q->rear]=e;
	Q->rear = (Q->rear+1)%MAXSIZE;
	return OK;
} 

// 若队列不空，则删除Q中队头元素，用e返回其值
Status DeQueue(SqQueue *Q, ElemType *e){
	if(Q->front==Q->rear) return ERROR; 
	*e = Q->data[Q->front];
	Q->front = (Q->front+1)%MAXSIZE;
	return OK;
} 

// 遍历队列
Status QueueTraverse(SqQueue Q){
	int i = Q.front;
	while(i!=Q.rear){
		visit(Q.data[i]);
		i = (i+1)%MAXSIZE;
	}
	cout<<endl;
	return OK;
} 

int main(){
	ElemType e;
	SqQueue Q;
	cout<<InitQueue(&Q)<<endl;
	for(int i=1; i<=12; i++) EnQueue(&Q,i);
	cout<<QueueLength(Q)<<endl;
	QueueTraverse(Q);
}
















































