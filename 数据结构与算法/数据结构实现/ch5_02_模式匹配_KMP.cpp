#include "stdio.h"
#include "iostream"
#include "stdlib.h" 
#include "string.h"  
#include "io.h"  
#include "math.h"  
#include "time.h"

using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE
#define MAXSIZE 100 /* �洢�ռ��ʼ������ */

typedef int Status;		/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;	/* ElemType���͸���ʵ������������������Ϊint */

typedef char String[MAXSIZE+1]; // 0�ŵ�Ԫ��Ŵ��ĳ���

// ����һ����ֵ����chars�Ĵ�T
Status StrAssign(String T, char* chars){
	if(strlen(chars)>MAXSIZE) return ERROR;
	T[0]=strlen(chars);
	for(int i=1; i<T[0]; i++) T[i]=*(chars+i-1); 
	return OK;
} 

// ����ַ���
Status ClearString(String S) {
	S[0]=0;
	return OK;
}

// ����ַ���T
void StrPrint(String T){
	for(int i=1; i<=T[0]; i++) cout<<T[i];
	cout<<endl; 
} 

// ���Next����ֵ
void NextPrint(int next[], int length){
	for(int i=1; i<=length; i++) cout<<*(next+i);
	cout<<endl;
	return;
} 

// ���ش��ĸ���
int StrLength(String S){
	return S[0];
} 

// ����ģʽƥ�䷨
// ��pos��Ϊ1�����pos��ʼ ;SΪ������TΪƥ�䴮 
int index(String S, String T, int pos){
	int i = pos;  
	int j = 1;
	if(pos<1||pos>S[0]) return 0;
	while(i<=S[0] && j<=T[0]){
		if(S[i]==T[j]){
			i++;
			j++;
		}else{
		
		
		}
	} 
	if(j>T[0]) return i-T[0];
	return 0;
} 

// ͨ�����㷵���Ӵ�T��next����
void get_next(String T, int *next){
	int i=1; j=0;
	next[1]=0;
	while(i<T[0]){
		// T[i]��ʾ��׺�ĵ����ַ���T[j]��ʾǰ׺�ĵ����ַ�
		if(j==0||T[i]==T[j]){
			i++;
			j++;
			next[i]=j;
		}else{
			j = next[j]
		}
	}
	// ����ǰǰ׺j���׺i��ƥ��
	// ��i�����j�����ǰ׺��ƥ�䣬��j=next[j] 
} 

// �����Ӵ�T������S�е�pos���ַ�֮���λ�á��������ڣ���������ֵΪ0
// T�ǿգ���1��pos��StrLength(S)
int index_KMP(String S, String T, int pos){
	int i = pos;
	int j = 1;
	int next[255];
	get_next(T,next);
	while(i<=S[0]&&j<=T[0]){
		if(j==0 || S[i]==T[j]){
			i++;
			j++;
		}else{
			j = next[j];
		}
	}
	if(j>T[0]) return i-T[0];
	return 0;
}

// ��ģʽ��T��next��������ֵ����������nextval
void get_nextval(String T, int *nextval){
	int i=1,j=0;
	nextval[1]=0;
	while(i<T[0]){
		if(j==0||T[0]==T[j]){
			i++;
			j++;
			// ����ǰ�ַ���ǰ׺�ַ���ͬ
			// ��ǰ��jΪnextval��iλ�õ�ֵ 
			if(T[i]!=T[j]) nextval[i]=j;
			else nextval[i]=nextval[j]; 
		}else j = nextval[j];
	}
} 

int Index_KMP1(String S, String T, int pos){
	int i = pos;
	int j=1;
	int next[225];
	get_nextval(T, next);
	while(i<=S[0] && j<=T[0]){
		if(j==0 || S[i]==T[j]){
			i++;
			j++;
		}else{
			j = next[j];
		}
	}
	if(j>T[0]) return i-T[0];
	else return 0;
}


// ��ǰλ��ǰ�Ĵ��� p[1]...p[k-1]=p[j-k+1]...p[j-1]�����ֵ 
int main(){
	
	return 0;
}
































 
