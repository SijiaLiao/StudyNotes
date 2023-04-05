#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int N;
int arr1[105];
int arr2[105];
bool flag = false;
int js=0;
int main(){
	cin>>N;
	for(int i=0;i<N;i++) scanf("%d",&arr1[i]);
	do{
		memcpy(arr2,arr1,N*sizeof(int));
		flag = false;
		for(int i=0;i<N;i++){
			if(i>=1&& arr2[i]!=arr2[i-1]) flag = true; 
			if(i==0) arr1[i] = arr2[i]/2 + arr2[N-1]/2;
			else arr1[i] = arr2[i]/2 + arr2[i-1]/2;
			if(arr1[i]%2==1) arr1[i]++,js+=1;
		}
	}while(flag);
	cout<<js;
	return 0;
}
