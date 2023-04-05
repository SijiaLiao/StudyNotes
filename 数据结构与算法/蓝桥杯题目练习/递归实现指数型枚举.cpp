#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
// 每一个数有两种方案 选择或者不选择
 
int n;
vector<int> ans;
int H[1<<25];
void cal(int x){
	if(x == n+1){ //边界 
		for(int i=0;i<ans.size();i++) cout<<ans[i]<<' ';
		cout<<endl;
		return; 
	}
	// 不选
	cal(x+1);
	// 选择
	ans.push_back(x);
	cal(x+1);
	// 回溯到上一个分支 
	ans.pop_back();
} 
int main(){
	cin>>n;
	//cal(1);
	for(int i=0;i<n;i++) H[1<<i]=i+1;
	cout<<endl;
	for(int i=1;i<1<<n;i++){
		int tmp=i;
		while(tmp){
			cout<<H[tmp & -tmp]<<' ';
			tmp -= tmp & -tmp; 
		}
		cout<<endl;
	}
	
	return 0;
} 
