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

#define MAXSIZE 100 //�洢�ռ��ʼ������
#define MAX_TREE_SIZE 100 //���������������

typedef int Status;
typedef int ElemType;
typedef ElemType SqBiTree[MAX_TREE_SIZE];//0�ŵ�Ԫ�洢�����

typedef struct{
	int level,order;//���Ĳ㣬������ţ��������������㣩 
}position;

ElemType Nil =0;

Status visit(ElemType e){
	cout<<e<<" ";
	return OK;
} 

// ����ն�����T����ΪT�ǹ̶����飬����ı䣬�ʲ���Ҫ&
Status CreateBiTree(SqBiTree T){
	int i=0;
	cout<<"�밴�����������ֵ��0��ʾ�ս�㣬��999�����������"<<MAX_TREE_SIZE<<endl;
	while(i<10){
		T[i]=i+1;
		if(i!=0 && T[(i+1)/2-1]==Nil && T[i]!=Nil){//�˽����˫���ҷǸ� 
			cout<<"������˫�׵ķǸ����"<<T[i]<<endl;
			exit(ERROR); 
		}
		i++;
	} 
	while(i<MAX_TREE_SIZE){
		T[i]=Nil;//���ո��Ƹ�T�ĺ���Ľ�� 
	}
} 

































