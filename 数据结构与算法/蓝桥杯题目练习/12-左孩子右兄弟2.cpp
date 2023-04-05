#include<iostream>
#include<vector>
#include<string.h>
#include<cstdio>
using namespace std;

const int MAXN = 100005;
int n;//结点总数
int fa[MAXN],d[MAXN]; 
vector<int> son[MAXN];

void dp(int x){
	if(son[x].size()==0) return;
	int len = son[x].size();
	for(int i=0;i<len;i++){
		int y = son[x][i]; // 孩子 
		dp(y);
		d[x] = max(d[x], d[y]+len);
	}
}

int main(){
	cin>>n;
	memset(d,0,sizeof(d));
	for(int i=2;i<=n;i++){
		scanf("%d", &fa[i]);
		son[fa[i]].push_back(i);
	}
	dp(1);
	cout<<d[1];
	return 0;
}
