#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
// ÿһ���������ַ��� ѡ����߲�ѡ��
 
int n;
vector<int> ans;
int H[1<<25];
void cal(int x){
	if(x == n+1){ //�߽� 
		for(int i=0;i<ans.size();i++) cout<<ans[i]<<' ';
		cout<<endl;
		return; 
	}
	// ��ѡ
	cal(x+1);
	// ѡ��
	ans.push_back(x);
	cal(x+1);
	// ���ݵ���һ����֧ 
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
