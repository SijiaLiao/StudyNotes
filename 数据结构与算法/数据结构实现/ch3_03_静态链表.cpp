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

Status visit(ElemType c){
	printf("%c ", c);
	return OK;
}

/*���Ա�ľ�̬����洢�ṹ*/
// ʹ�ýṹ��������Ϊ��̬��������� 
// ����һ��Ԫ�ص�cur��Ϊ���������һ�������±�
// �����һ��Ԫ�ص�cur��Ϊ����һ�������±꣬���ɿ���Ϊͷ��� 
// cur=0 ����ָ�� 
typedef struct{
	ElemType data;
	int cur; /*�α꣬Ϊ0ʱ��ָ��*/
}Component, StaticLinkList[MAXSIZE];


// ��һά����space�и���������һ����������  
Status InitList(StaticLinkList  space){
	for(int i=0; i<MAXSIZE-1; i++) space[i].cur = i+1;
	space[MAXSIZE-1].cur = 0;
	return OK;
}

// �����ÿռ�����ǿգ��򷵻ط���Ľ���±꣬���򷵻�0
int Malloc_SSL(StaticLinkList space){
	
	int i = space[0].cur; // ��ǰ�����һ��Ԫ�ص�cur���ֵ 
						  // ����ϣ�����������һ�����п���±�
	if(space[0].cur) space[0].cur = space[i].cur; 
					      // ��������Ҫ����һ�����п��ȥ
					      // ������Ҫ��������ȥ����α���Ϊ��һ�����п� 
	space[i].cur = 0;// �����ȥ�Ŀ��п�ָ��0 
	return i;
} 


// ���±�Ϊk�Ŀ��н����յ����������� 
void Free_SSL(StaticLinkList space, int k){
	space[k].cur = space[0].cur; // ����һ��Ԫ�����ӵ�k��
								 // Ȼ����k���ӵ�ԭ��һ��Ԫ�������ӵ�ֵ 
	space[0].cur = k;
} 

// ���ؾ�̬������Ԫ�صĸ�������������
int ListLength(StaticLinkList L){
	int j = 0;
	int i = L[MAXSIZE-1].cur;
	while(i){
		i = L[i].cur;
		j++;
	} 
	return j;
} 

// ��L�е�i��Ԫ��֮ǰ�����µ�����Ԫ��e
Status ListInsert(StaticLinkList L, int i, ElemType e){
	int j, k;
	k = MAXSIZE - 1;
	if(i<1 || i>ListLength(L)+1) return ERROR;
	j = Malloc_SSL(L); //��ȡ���з������±�
	if(j){
		L[j].data = e;
		for(int l=1; l<i; l++) k = L[k].cur; //�ҵ���i-1��Ԫ�ص��±� 
		L[j].cur = L[k].cur;
		L[k].cur = j;
		return OK;
	} 
	return ERROR;
} 


// ɾ����L�еĵ�i��Ԫ��
Status ListDelete(StaticLinkList L, int i){
	if(i<1 || i>ListLength(L)) return ERROR;
	int k = MAXSIZE - 1;
	for(int j=1; j<i; j++) k = L[k].cur;
	int l = L[k].cur;
	L[k].cur = L[l].cur;
	Free_SSL(L, l);
	return OK; 
} 


// �������������Ԫ��
Status ListTraverse(StaticLinkList L){
	int i = L[MAXSIZE-1].cur;
	while(i){
		cout<<L[i].data<<" ";
		i = L[i].cur;
	} 
	cout<<endl;
	return OK;
} 


int main(){
	StaticLinkList L;
	cout<<InitList(L)<<endl;
	for(int i=1;i<=5;i++) ListInsert(L,i,i);
	ListTraverse(L);
	ListDelete(L,3);
	ListTraverse(L);
	return 0;
}

































