#include<iostream>
#include<algorithm> 
#include<stdio.h>
using namespace std;

int N;
int sum=0;
int w[102];
int dp[102][100002];
int ans=0;

int main(){
	cin>>N;
	for(int i=1;i<=N;i++) scanf("%d",&w[i]),sum+=w[i];
	dp[0][0] = 1;
	for(int i=1;i<=N;i++) for(int j=0;j<=sum;j++) 
		dp[i][j] = max(dp[i-1][j], max(dp[i-1][j+w[i]],dp[i-1][abs(j-w[i])]));
	for(int i=1;i<=sum;i++) if(dp[N][i]) ans++;
	cout<<ans;
	return 0;
} 
