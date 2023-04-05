#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
#define MAX 100005
typedef long long ll;

ll n,m,t;
int x[MAX], y[MAX], a[MAX], s[MAX];

int main(){
	cin>>n>>m>>t;
	for(int i=1;i<=t;i++) scanf("%d %d", &x[i], &y[i]);  
	bool row = !(t%n), column = !(t%m);
	
	if(row){
		if(column) cout<<"both"<<' ';
		else cout<<"row"<<' ';
	}else{
		if(column) cout<<"column"<<' ';
		else{
			cout<<"impossible"<<' ';
			return 0;
		} 
	}
	
	ll ans=0;
	
	if(row){
		ll num = t/n;
		memset(a,0,sizeof(a));
		for(int i=1;i<=t;i++) a[x[i]]++; // 计算第i行初始 有多少个摊位点
		s[0] = 0;
		for(int i=1;i<=n;i++) a[i] -= num,s[i] = s[i-1] + a[i];
		//for(int i=1;i<=n;i++) s[i] = s[i-1] + a[i];
		sort(s+1,s+n+1);
		for(int i=1;i<=n/2;i++) ans += s[n-i+1] -s[i]; // 货仓选址 
	}
	
	if(column){
		ll num = t/m;
		memset(a,0,sizeof(a));
		for(int i=1;i<=t;i++) a[y[i]]++;
		s[0] = 0;
		for(int i=1;i<=m;i++) a[i] -= num, s[i]=s[i-1]+a[i];
		//for(int i=1;i<=m;i++) s[i] = s[i-1] + a[i];
		sort(s+1,s+m+1);
		for(int i=1;i<=m/2;i++) ans += s[m-i+1] - s[i];
	}
	
	cout<<ans; 
	return 0;
}
