#include<iostream>
#include<map>
#include<string.h>
#include<stdio.h>
using namespace std;
#define MAXN 200005
int n,m; // n个科学家 m 部电影 
int b[MAXN], c[MAXN];
map<int,int> lang; // 语言 语言所在a数组的idx 
int cmp(int a, int b){
	return a>b;
}
int main(){
	cin>>n; 
	int tmp; 
	for(int i=1;i<=n;i++){
		scanf("%d", &tmp);
		if(lang[tmp])  lang[tmp] +=1;
		else lang[tmp]=1;
		
		//cout<<lang[tmp]<<' ';
	}
	//cout<<endl;
	
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	
	cin>>m;
	int tmp_b, tmp_c;// 一部电影的字母 语音 
	int maxb=0,ans=0;
	for(int i=1;i<=m;i++){
		scanf("%d", &tmp_b);
		if(lang[tmp_b]) b[i] += lang[tmp_b];
		maxb = max(maxb,b[i]);
		//cout<<b[i]<<' ';	
	}
	//cout<<endl;
	
	for(int i=1;i<=m;i++){
		scanf("%d",&tmp_c);
		if(lang[tmp_c]) c[i] += lang[tmp_c];
		//cout<<c[i]<<' ';
		//cout<<b[i]<<' '<<c[i]<<' ';
		if(b[i]==maxb){
			if(c[i]>=c[ans]) ans = i;
		}
	}
	//cout<<endl;	
	cout<<ans<<endl;
	return 0;
}
