#include<stdio.h>	
#include<iostream>
using namespace std;

#define MAXSIZE 20 /*存储空间初试分配量*/

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status; 
typedef int ElemType; 

typedef struct{
	ElemType data[MAXSIZE]; /*一维数组存储数据元素*/
	int length; /*线性表的当前长度*/ 
}SqList; 

// 初始化顺序线性表
Status InitList(SqList *L){
	L->length = 0;
	return OK;
} 

// 判断线性表是否非空
Status ListEmpty(SqList L){
	if(L.length == 0) return TRUE;
	else return FALSE;
} 

// 清空线性表
Status ClearList(SqList *L){
	L->length = 0;
	return OK;
} 

// 获取线性表长度
int ListLength(SqList L){
	return L.length;
} 

// 获取元素
Status GetItem(SqList L, int i, ElemType *e){
	if(L.length==0 || i<1 || i>L.length){
		return ERROR;
	}
	*e = *(L.data+i-1); // 运用指针获得数据 
	return OK;
}

// 定位元素 
// 返回第一个与e相同的元素的位序
int LocateItem(SqList L, ElemType e){
	if(L.length == 0) return 0;
	int i;
	for(i=1; i<=L.length; i++){
		if(L.data[i-1] == e) return i;
	}
	if(i>L.length) return 0; 
} 

// 插入元素
Status ListInsert(SqList *L, int i, ElemType e){
	// 判断异常
	if(L->length>=MAXSIZE) return ERROR;
	if(i<1 || i>L->length+1) return ERROR;
	// 插入元素 
	if(i!=L->length+1){
		for(int k = L->length; k>=i; k--){
			L->data[k] = L->data[k-1];
		}
	}
	L->data[i-1] = e;
	L->length ++;
	return OK;
} 

// 删除元素
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

// 线性表输出 
Status ListTraverse(SqList L){
	for(int i=1; i<=L.length; i++) cout<<L.data[i-1]<<" ";
	cout<<endl;
	return OK;
} 

int main(){
	SqList L;
	cout<< "初始化线性表："<<InitList(&L)<<endl; 
	
	cout<<"插入数据: "; 
	for(int i=1; i<=5; i++) ListInsert(&L, i, i); 
	ListTraverse(L); 
	 
	cout<<"删除第3个位置的数据：";
	ElemType e;
	ListDelete(&L,3,&e);
	cout<<e<<endl;
	
	 
	return 0;
}




















