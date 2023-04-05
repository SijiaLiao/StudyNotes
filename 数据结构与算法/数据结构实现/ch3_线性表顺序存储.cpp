#include<stdio.h>	
#include<iostream>
using namespace std;

#define MAXSIZE 20 /*�洢�ռ���Է�����*/

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status; 
typedef int ElemType; 

typedef struct{
	ElemType data[MAXSIZE]; /*һά����洢����Ԫ��*/
	int length; /*���Ա�ĵ�ǰ����*/ 
}SqList; 

// ��ʼ��˳�����Ա�
Status InitList(SqList *L){
	L->length = 0;
	return OK;
} 

// �ж����Ա��Ƿ�ǿ�
Status ListEmpty(SqList L){
	if(L.length == 0) return TRUE;
	else return FALSE;
} 

// ������Ա�
Status ClearList(SqList *L){
	L->length = 0;
	return OK;
} 

// ��ȡ���Ա���
int ListLength(SqList L){
	return L.length;
} 

// ��ȡԪ��
Status GetItem(SqList L, int i, ElemType *e){
	if(L.length==0 || i<1 || i>L.length){
		return ERROR;
	}
	*e = *(L.data+i-1); // ����ָ�������� 
	return OK;
}

// ��λԪ�� 
// ���ص�һ����e��ͬ��Ԫ�ص�λ��
int LocateItem(SqList L, ElemType e){
	if(L.length == 0) return 0;
	int i;
	for(i=1; i<=L.length; i++){
		if(L.data[i-1] == e) return i;
	}
	if(i>L.length) return 0; 
} 

// ����Ԫ��
Status ListInsert(SqList *L, int i, ElemType e){
	// �ж��쳣
	if(L->length>=MAXSIZE) return ERROR;
	if(i<1 || i>L->length+1) return ERROR;
	// ����Ԫ�� 
	if(i!=L->length+1){
		for(int k = L->length; k>=i; k--){
			L->data[k] = L->data[k-1];
		}
	}
	L->data[i-1] = e;
	L->length ++;
	return OK;
} 

// ɾ��Ԫ��
Status ListDelete(SqList *L, int i, ElemType *e){
	if(L->length == 0) return ERROR;
	if(i<1 || i>L->length) return ERROR;
	
	*e = L->data[i-1];
	
	if(i!=L->length){
		for(int k=i; k<=L->length-1; k++){
			L->data[k-1] = L->data[k];  
		}
	}
	L->length--;
	
	return OK;
} 

// ���Ա���� 
Status ListTraverse(SqList L){
	for(int i=1; i<=L.length; i++) cout<<L.data[i-1]<<" ";
	cout<<endl;
	return OK;
} 

int main(){
	SqList L;
	cout<< "��ʼ�����Ա�"<<InitList(&L)<<endl; 
	
	cout<<"��������: "; 
	for(int i=1; i<=5; i++) ListInsert(&L, i, i); 
	ListTraverse(L); 
	 
	cout<<"ɾ����3��λ�õ����ݣ�";
	ElemType e;
	ListDelete(&L,3,&e);
	cout<<e<<endl;
	
	 
	return 0;
}




















