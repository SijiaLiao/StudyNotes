#include<stdio.h>
#include<iostream>
#include<io.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* �洢�ռ��ʼ������ */

typedef int Status;
typedef int ElemType;

typedef struct QNode{
	ElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct{
	QueuePtr front, rear; //��ͷ����βָ�� 
}LinkQueue;

Status visit(ElemType e){
	cout<<e<<" ";
	return OK;
} 

// ����ն��� ��ͷ�������� 
Status InitQueue(LinkQueue *Q){
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q->front) exit(OVERFLOW);
	Q->front->next = NULL;
	return OK;
} 

// ���ٶ���
Status DestroyQueue(LinkQueue *Q){
	while(Q->front){
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK;
} 

// ��ն��� �ö�ͷ��βָ��ָ��һ��,���ͷ���������Ԫ�� 
Status ClearQueue(LinkQueue *Q){
	QueuePtr p,q;
	Q->rear = Q->front;
	p = Q->front->next;
	Q->front->next = NULL;
	while(p){
		q = p;
		p = p->next;
		free(q);
	} 
	return OK; 
}

// �ж϶����Ƿ�Ϊ��
Status QueueEmpty(LinkQueue Q){
	if(Q.front == Q.rear) return TRUE;
	else return FALSE;
} 

// ����еĳ���
int QueueLength(LinkQueue Q){
	int len =0;
	QueuePtr p = Q.front;
	while(p!=Q.rear){
		p = p->next;
		len++;
	}
	return len;
} 

// ���ض�ͷԪ��
Status GetHead(LinkQueue Q, ElemType *e){
	if(Q.front==Q.rear) return ERROR;
	*e = Q.front->next->data;
	return OK; 
}

// ����Ԫ��eΪQ���µĶ�βԪ�� 
Status EnQueue(LinkQueue *Q, ElemType e){
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if(!p) exit(OVERFLOW);//�洢����ʧ�� 
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
} 

// �����в��գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ
Status DeQueue(LinkQueue *Q, ElemType *e){
	QueuePtr p;
	if(Q->front == Q->rear) return ERROR;
	p = Q->front->next;
	*e = p->data; 
	Q->front->next = p->next;
	if(Q->rear==p) Q->rear=Q->front;
	free(p);
	return OK;
} 

// ��������Q
Status QueueTraverse(LinkQueue Q){
	QueuePtr p = Q.front->next;
	while(p){
		visit(p->data);
		p = p->next;
	}
	cout<<endl;
	return OK;
} 

int main(){
	LinkQueue Q;
	ElemType e;
	cout<<InitQueue(&Q)<<endl;
	for(int i=1; i<=10; i++) EnQueue(&Q,i);
	QueueTraverse(Q);
	for(int i=1;i<6;i++) DeQueue(&Q, &e);
	QueueTraverse(Q);
	return OK;
}


























































 
