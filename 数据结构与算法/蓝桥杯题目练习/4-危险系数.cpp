#include<iostream>
using namespace std;

/*
 ͨ��dfs������������֮�������·����Ȼ�󾭹��ĵ�ֵ��һ�����ֵ���ľ��� �ؼ��� 
*/
int n,m;
bool arr[1005][1005];
int vis[1005];  // ��ǵ��Ƿ��߹� 
int v[1005]; // ��¼ÿ�����ֵ 
vector<int> way; 
int ansv1,ansv2; // ����������� 

void dfs(int x){// ���ĸ������ 

	if(x==ansv2){ // �߹������е��һ 
		int len = way.size();
		for(int i=0;i<len;i++){
			v[way[i]]++;
		}
		return;
	}
	
	// ��������
	
	
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
