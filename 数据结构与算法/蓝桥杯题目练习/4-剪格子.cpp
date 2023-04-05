#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string.h>
using namespace std;

int n,m;//�У���
int arr[11][11]; // ���� 
int flag[11][11]; 
int sum=0; // �ܺ�/2 
int sum1=0; // ���ݵĵ�ǰ�ܺ� 
int cnt=0;
int fx[4][2]={{-1,0},{1,0},{0,-1},{0,1}};// �������� 
vector<int> res; 

void cal(int i,int j){
	//cout<<' '<<i<<' '<<j<<' '<<sum1<<' '<<endl; 
	if(i<0||i>=n||j<0||j>=m) return; // �����߽� 
	if(flag[i][j]==1) return; // �ѱ��
	
	sum1 += arr[i][j];
	cnt++;
	flag[i][j] =1;
	
	//cout<<i<<' '<<j<<' '<<sum1<<' '<<endl; 
	
	if(sum1>sum){
		sum1 = sum1 - arr[i][j];
		cnt--;
		flag[i][j] = 0;
		return ;    
	}
	
	if(sum1==sum){
		res.push_back(cnt); 
		return;
	} 
	
	// �����Ͻǿ�ʼ ��������̽��
	cal(i+fx[0][0],j+fx[0][1]); // �� 
	cal(i+fx[1][0],j+fx[1][1]); // �� 
	cal(i+fx[2][0],j+fx[2][1]); // �� 
	cal(i+fx[3][0],j+fx[3][1]); // �� 
	
	sum1 = sum1 - arr[i][j];
	cnt--;
	flag[i][j] = 0;
} 

int main(){
	cin>>m>>n;
	memset(flag,0,sizeof(flag));


	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
			sum = sum + arr[i][j];
		} 
	}
	if(sum%2==1){
		cout<<0;
		return 0;
	}
	sum /= 2;
	
	cal(0,0);
	 
	if(res.size()==0){
		cout<<0;
	}else{
		sort(res.begin(),res.end());
		cout<<res[0];
	}
	return 0;
}
