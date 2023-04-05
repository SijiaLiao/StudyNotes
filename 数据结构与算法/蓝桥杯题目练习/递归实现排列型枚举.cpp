#include<iostream>
#include<string.h>
using namespace std;
#define MAXN 10
int n;
int vis[MAXN];
int ans[MAXN];
void cal(int x){
	if(x==n+1){
		for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
		cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		ans[x] = i;
		vis[i] = 1; 
		cal(x+1);
		vis[i]=0;
	}
}
int main(){
	cin>>n;
	memset(vis,0,sizeof(vis));
	cal(1);
	return 0;
}
