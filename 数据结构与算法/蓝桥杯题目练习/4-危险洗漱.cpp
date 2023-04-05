#include<iostream>
#include<vector> 
#include<string.h>
#include<algorithm>
using namespace std;

/*
 ͨ��dfs������������֮�������·����Ȼ�󾭹��ĵ�ֵ��һ�����ֵ���ľ��� �ؼ��� 
*/
int n,m;
int arr[1005][1005]={0};
int vis[1005]={0};  // ��ǵ��Ƿ��߹� 
int v[1005]={0}; // ��¼ÿ�����ֵ 
vector<int> way; 
int ansv1,ansv2; // ����������� 

void dfs(int x){// ���ĸ������ 

	int currv =0;
	if(x==ansv2){ // �߹������е��һ 
		int len = way.size();
		for(int i=0;i<len;i++) v[way[i]]++;
		return;
	}
	
	// ��������
	if(vis[x]) return; // ��ǰ���ѱ��	
	vis[x] = 1; // ��Ǹõ�
	way.push_back(x); // ���뵱ǰ·����
	for(int i=1;i<=arr[x][0];i++) dfs(arr[x][i]); // ������ 
	
	// ����
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
