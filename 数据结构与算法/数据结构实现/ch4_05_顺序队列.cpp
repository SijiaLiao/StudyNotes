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

// ѭ�����е�˳��洢�ṹ
typedef struct{
	ElemType data[MAXSIZE];
	int front; //ͷָ�� 
	int rear; // βָ�� 
}SqQueue; 

Status visit(ElemType e){
	cout<<e<<" ";
	return 0;
} 

// ��ʼ��һ���ն���
Status InitQueue(SqQueue *Q){
	Q->front = 0;
	Q->rear = 0;
	return OK;
} 

// ��ն���
Status ClearQueue(SqQueue *Q){
	Q->front = Q->rear = 0;
	return OK;
} 

// �ж϶����Ƿ�Ϊ�ն���
Status QueueEmpty(SqQueue Q){
	if(Q.front == Q.rear) return TRUE; //�ӿյı�־ 
	else return FALSE;
} 

// ����Q��Ԫ�صĸ����������еĵ�ǰ����
int QueueLength(SqQueue Q){
	return (MAXSIZE-Q.front+Q.rear) % MAXSIZE;
} 

// �����в��գ�����e����Q�Ķ�ͷԪ��
Status GetHead(SqQueue Q, ElemType *e){
	if(Q.front==Q.rear) return ERROR;
	*e = Q.data[Q.front];
	return OK;
} 

// ������δ���������Ԫ��eΪQ���µĶ�βԪ��
Status EnQueue(SqQueue *Q, ElemType e){
	if((Q->rear+1)%MAXSIZE == Q->front) return ERROR;
	Q->data[Q->rear]=e;
	Q->rear = (Q->rear+1)%MAXSIZE;
	return OK;
} 

// �����в��գ���ɾ��Q�ж�ͷԪ�أ���e������ֵ
Status DeQueue(SqQueue *Q, ElemType *e){
	if(Q->front==Q->rear) return ERROR; 
	*e = Q->data[Q->front];
	Q->front = (Q->front+1)%MAXSIZE;
	return OK;
} 

// ��������
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
















































