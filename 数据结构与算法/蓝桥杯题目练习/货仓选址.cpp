#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
#define MAXN 100005
int n;// 共有的整数
int a[MAXN]; 
int main(){
	
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	
	long long ans =0;
	for(int i=1;i<=n/2;i++) ans+=a[n-i+1] - a[i];
	
	//int mid = (n-1)/2, warehouse=0;
	//nth_element(a,a+mid,a+n);
	
	//if(n&1) warehouse = a[mid];
	//else warehouse = (a[mid] + a[mid+1])/2; 
	
	//long long dis=0;
	//for(int i=0;i<n;i++) dis += abs(warehouse - a[i]);
	
	cout<<ans; 
	return 0;
}
