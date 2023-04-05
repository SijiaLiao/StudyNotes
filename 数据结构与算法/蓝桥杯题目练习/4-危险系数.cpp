#include<iostream>
using namespace std;

/*
 通过dfs搜索出两个点之间的所有路径，然后经过的点值加一，最后值最大的就是 关键点 
*/
int n,m;
bool arr[1005][1005];
int vis[1005];  // 标记点是否走过 
int v[1005]; // 记录每个点的值 
vector<int> way; 
int ansv1,ansv2; // 所求的两个点 

void dfs(int x){// 从哪个点出发 

	if(x==ansv2){ // 走过的所有点加一 
		int len = way.size();
		for(int i=0;i<len;i++){
			v[way[i]]++;
		}
		return;
	}
	
	// 正常行走
	
	
}

int main(){
	cin>>n>>m;
	
	int v1,v2;
	memset(arr,0,sizeof(arr));
	
	for(int i=1;i<=m){
		cin>>v1>>v2;
		arr[v1][ ++arr[v1][0] ] = v2;
	}
	cin>>ansv1>>ansv2;
	
	memset(vis,0,sizeof(v));
	memset(v,0,sizeof(v));
	
}
