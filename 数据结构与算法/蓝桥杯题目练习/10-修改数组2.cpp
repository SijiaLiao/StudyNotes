#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 1000010;
int n;
int fa[MAXN];
int val;
int get(int x){
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
int main(){
	cin>>n;
	for(int i=1; i<=MAXN; i++) fa[i] = i;
	for(int i=1; i<=n ;i++){
		scanf("%d", &val);
		val = get(val); 
		cout<<val<<' ';
		fa[val] = val+1;
	}
	return 0;
}
