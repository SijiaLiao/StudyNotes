#include<iostream>
using namespace std;

int n,m,K; // 行 列 宝物最多件数 
int arr[52][52]={0};
long long dp[51][51][13][13];
long long mod = 1000000007;
int main(){
	cin>>n>>m>>K;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>arr[i][j];
	
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) for(int k=0;k<=K;k++) for(int c=0;c<13;c++){
		long long na=0,buna=0;
		if(i==1 && j==1){
			if(!k || (k==1 && c>arr[i][j])) dp[i][j][k][c] = 1;
			continue;
		}
		if(k && c>arr[i][j]) na = dp[i-1][j][k-1][arr[i][j]] + dp[i][j-1][k-1][arr[i][j]]; // 当前格子的宝物可拿 
		buna =  dp[i-1][j][k][c] + dp[i][j-1][k][c];
		dp[i][j][k][c] = (na+buna)%mod; 
	}
	
	cout<<dp[n][m][K][12];
	return 0;
}
