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
#define MAXSIZE 100 /* 存储空间初始分配量 */

typedef int Status;		/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;	/* ElemType类型根据实际情况而定，这里假设为int */

typedef char String[MAXSIZE+1]; // 0号单元存放串的长度

// 生成一个其值等于chars的串T
Status StrAssign(String T, char* chars){
	if(strlen(chars)>MAXSIZE) return ERROR;
	T[0]=strlen(chars);
	for(int i=1; i<T[0]; i++) T[i]=*(chars+i-1); 
	return OK;
} 

// 清除字符串
Status ClearString(String S) {
	S[0]=0;
	return OK;
}

// 输出字符串T
void StrPrint(String T){
	for(int i=1; i<=T[0]; i++) cout<<T[i];
	cout<<endl; 
} 

// 输出Next数组值
void NextPrint(int next[], int length){
	for(int i=1; i<=length; i++) cout<<*(next+i);
	cout<<endl;
	return;
} 

// 返回串的个数
int StrLength(String S){
	return S[0];
} 

// 朴素模式匹配法
// 若pos不为1，则从pos开始 ;S为主串，T为匹配串 
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

// 通过计算返回子串T的next数组
void get_next(String T, int *next){
	int i=1; j=0;
	next[1]=0;
	while(i<T[0]){
		// T[i]表示后缀的单个字符，T[j]表示前缀的单个字符
		if(j==0||T[i]==T[j]){
			i++;
			j++;
			next[i]=j;
		}else{
			j = next[j]
		}
	}
	// 若当前前缀j与后缀i不匹配
	// 则i最多与j的最大前缀相匹配，故j=next[j] 
} 

// 返回子串T在主串S中第pos个字符之后的位置。若不存在，则函数返回值为0
// T非空，且1≤pos≤StrLength(S)
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

// 求模式串T的next函数修正值并存入数组nextval
void get_nextval(String T, int *nextval){
	int i=1,j=0;
	nextval[1]=0;
	while(i<T[0]){
		if(j==0||T[0]==T[j]){
			i++;
			j++;
			// 若当前字符与前缀字符不同
			// 则当前的j为nextval在i位置的值 
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


// 当前位置前的串中 p[1]...p[k-1]=p[j-k+1]...p[j-1]的最大值 
int main(){
	
	return 0;
}
































 
