#include "stdio.h"
#include "iostream"
#include "stdlib.h"
#include "math.h"
#include "time.h"
using namespace tsd;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 //存储空间初始分配量
#define MAX_TREE_SIZE 100 //二叉树的最大结点数

typedef int Status;
typedef int ElemType;
typedef ElemType SqBiTree[MAX_TREE_SIZE];//0号单元存储根结点

typedef struct{
	int level,order;//结点的层，本层序号（按照满二叉树算） 
}position;

ElemType Nil =0;

Status visit(ElemType e){
	cout<<e<<" ";
	return OK;
} 

// 构造空二叉树T。因为T是固定数组，不会改变，故不需要&
Status CreateBiTree(SqBiTree T){
	int i=0;
	cout<<"请按层序输入结点的值，0表示空结点，输999结束，结点数"<<MAX_TREE_SIZE<<endl;
	while(i<10){
		T[i]=i+1;
		if(i!=0 && T[(i+1)/2-1]==Nil && T[i]!=Nil){//此结点无双亲且非根 
			cout<<"出现无双亲的非根结点"<<T[i]<<endl;
			exit(ERROR); 
		}
		i++;
	} 
	while(i<MAX_TREE_SIZE){
		T[i]=Nil;//将空复制给T的后面的结点 
	}
} 

































