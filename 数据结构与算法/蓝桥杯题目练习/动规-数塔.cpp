#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

const int MAX = 105;
int n;//数塔的高度 
int dp[MAX][MAX];
int c=0;
int main(){
	
	cin>>c;

	while(c--){
		memset(dp,0,sizeof(dp));
		int x = 0;
		int ans=0;
		
		cin>>n;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=i; j++){
				scanf("%d", &x);
				if(i==1 && j==1) dp[i][j] = x;
				else if(j==1) dp[i][j] = dp[i-1][j] + x;
				else if(j==i) dp[i][j] = dp[i-1][j-1] + x;
				else dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + x;
				
				if(i==n) ans = max(ans, dp[i][j]); 
			} 
		
		cout<<ans<<endl;	
	}
	
	return 0;
} 
