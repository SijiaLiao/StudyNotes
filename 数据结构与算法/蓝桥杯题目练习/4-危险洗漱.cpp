#include<iostream>
#include<vector> 
#include<string.h>
#include<algorithm>
using namespace std;

/*
 通过dfs搜索出两个点之间的所有路径，然后经过的点值加一，最后值最大的就是 关键点 
*/
int n,m;
int arr[1005][1005]={0};
int vis[1005]={0};  // 标记点是否走过 
int v[1005]={0}; // 记录每个点的值 
vector<int> way; 
int ansv1,ansv2; // 所求的两个点 

void dfs(int x){// 从哪个点出发 

	int currv =0;
	if(x==ansv2){ // 走过的所有点加一 
		int len = way.size();
		for(int i=0;i<len;i++) v[way[i]]++;
		return;
	}
	
	// 正常行走
	if(vis[x]) return; // 当前点已标记	
	vis[x] = 1; // 标记该点
	way.push_back(x); // 加入当前路径中
	for(int i=1;i<=arr[x][0];i++) dfs(arr[x][i]); // 继续走 
	
	// 回溯
	vis[x] = 0;
	way.pop_back(); 
}

 bool cmp(int a,int b){
 	return a>b;
 }
 
int main(){
	cin>>n>>m;
	
	int v1,v2;		
	for(int i=1;i<=m;i++){
		cin>>v1>>v2;
		arr[v1][ ++arr[v1][0] ] = v2;
		arr[v2][ ++arr[v2][0] ] = v1;
	}
	cin>>ansv1>>ansv2;
	dfs(ansv1);

	sort(v,v+n,cmp);
	int max = v[0];
	int res=0;
	
	for(int i=0;i<n;i++){
		if(v[i]==max) res++;
		else break;
	}
	cout<<res-1;
	return 0;	
}
