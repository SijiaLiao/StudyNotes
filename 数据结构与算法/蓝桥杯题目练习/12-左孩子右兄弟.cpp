#include<iostream>
#include<vector> 
using namespace std;


int N,tmp;
vector<int> mp[100005];

int dfs(int idx){
	int size = mp[idx].size(); // 有几个孩子
	int ans =0;
	for(int i=0;i<size;i++) ans = max(ans,dfs(mp[idx][i]));
	return ans + size;    
} 
int main(){
	cin>>N;
	for(int i=2;i<=N;i++) cin>>tmp,mp[tmp].push_back(i); 
	cout<<dfs(1);
	return 0;
} 
