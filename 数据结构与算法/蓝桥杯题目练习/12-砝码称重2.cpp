#include<iostream>
#include<string.h>
#include<stdio.h> 
#include<cmath>
#include<algorithm>
using namespace std;

const int MAXN = 105, MAXS=100005;
int w[MAXN];//砝码的重量
int n=0,sum=0;//砝码的总重量
bool dp[MAXN][MAXS];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d", &w[i]), sum+=w[i];
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=sum;j++){
			dp[i][j] = max(dp[i-1][j], max(dp[i-1][j+w[i]],dp[i-1][abs(j-w[i])]));
		}
	}
	long long ans=0;
	for(int i=1; i<=sum;i++) if(dp[n][i]) ans++;
	cout<<ans;
	return 0;
}
