#include<stdio.h>
#include<iostream>
using namespace std;


// 递归实现斐波那契
int Fbi(int i){
	if(i<2) return i==0 ? 0:1;
	return Fbi(i-1)+Fbi(i-2);
} 

int main(){
	int i;
	int a[40];
	cout<<"迭代显示斐波那契数列："<<endl;
	a[0] = 0;
	a[1] = 1; 
	cout<<a[0]<<" "<<a[1]<<" ";
	for(int i=2;i<=39;i++){
		a[i] = a[i-1] + a[i-2];
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
	cout<<"递归显示斐波那契数列："<<endl; 
	for(int i=0; i<40; i++) cout<<Fbi(i)<<" ";
	cout<<endl;
	return 0;
} 
