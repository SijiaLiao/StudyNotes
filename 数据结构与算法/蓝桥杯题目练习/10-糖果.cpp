#include<iostream>
#include<string.h>
#include<cstdio> 
using namespace std;

const int MAXN=105;
const int MAXM=1<<22;
int n,m,k;
int x;
int a[MAXN];
int dp[MAXM];
int main(){
	cin>>n>>m>>k;//n包 m种 每包k种
	memset(a,0,sizeof(a));
	for(int i=1; i<=n; i++){
		for(int j=0; j<k; j++){
			scanf("%d", &x);
			a[i] |= (1<<(x-1));
		}
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0]=0;
	for(int i=1; i<=n; i++){
		for(int j=0; j<(1<<m); j++){
			dp[j|a[i]] = min(dp[j|a[i]], dp[j]+1);
		}
	}
	if(dp[(1<<m)-1]>=200) cout<<-1;
	else cout<<dp[(1<<m)-1];
	return 0;
}
