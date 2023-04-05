#include<iostream>
#include<vector>> 
using namespace std;

// 组合型枚举 每次选择m个数 
int n,m; //n个数 选择m个 
vector<int> ans;

void cal(int x){
	// 问题边界 
	if(ans.size()>m || (ans.size()+(n-x+1)<m)) return;
	if(x==n+1){	
		for(int i=0;i<ans.size();i++) cout<<ans[i]<<' ';
		cout<<endl;
		return;
	}
	
	// 分支条件
	// 选 
	ans.push_back(x);
	cal(x+1);
	// 回溯条件
	ans.pop_back(); 
	
	//不选当前数
	cal(x+1);
}
int main(){
	cin>>n>>m; 
	cal(1); 
	return 0;
} 
