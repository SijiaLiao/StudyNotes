#include<iostream>
#include<vector>> 
using namespace std;

// �����ö�� ÿ��ѡ��m���� 
int n,m; //n���� ѡ��m�� 
vector<int> ans;

void cal(int x){
	// ����߽� 
	if(ans.size()>m || (ans.size()+(n-x+1)<m)) return;
	if(x==n+1){	
		for(int i=0;i<ans.size();i++) cout<<ans[i]<<' ';
		cout<<endl;
		return;
	}
	
	// ��֧����
	// ѡ 
	ans.push_back(x);
	cal(x+1);
	// ��������
	ans.pop_back(); 
	
	//��ѡ��ǰ��
	cal(x+1);
}
int main(){
	cin>>n>>m; 
	cal(1); 
	return 0;
} 
