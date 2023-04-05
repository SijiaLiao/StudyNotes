#include<iostream>
#include<algorithm>
using namespace std;

int N;
int a[10] ={0,1,2,3,4,5,6,7,8,9};

int getNum(int x,int y){
	int num=0;
	for(int i=x;i<=y;i++) num = num*10 + a[i];
}
void judge(int[] a){
	int i,j;
	for(int i=1;i<=7;i++){
		// 先求整数部分
		int integer=getNum(1,i); 
	}
}
int main(){
	cin>>N;
	do{
		judge(a)
	}while(next_permutation(a+1,a+10));
	return 0;
}
