#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define maxn 100005
int n=0,s=0;
int h[maxn],f[maxn],vis[maxn];
int maxh = 50000; 
int ans=0;
int main(){
	
	while(scanf("%d",&h[++n])); n--;
	
	// 最长下降子序列
	memset(f,0,sizeof(f));
	f[1] = 1; // 初值  
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(h[j]>=h[i]) f[i] = max(f[i],f[j]+1);
		}
	} 
	// 最少需要多少套系统
	// 是导弹就拦截 
	
	memset(vis,0,sizeof(vis));
	while(s<n){
		maxh = 50000;
		ans ++;
		for(int i=1;i<=n;i++){
			if(h[i]<=maxh && vis[i]==0) s++,vis[i]=1,maxh=h[i];
		} 
	}
	cout<<f[n]<<endl<<ans;
	return 0;
	
} 
