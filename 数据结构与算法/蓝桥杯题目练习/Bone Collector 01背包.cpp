#include<iostream>
#include<string.h>
#include<cstdio>
#include<algorithm>
using namespace std;
int n, m;
int w[1005],v[1005],dp[1005];
int main(){
	int t;//°¸ÁÐÊý
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1; i<=n; i++) scanf("%d", &w[i]);
		for(int i=1; i<=n; i++) scanf("%d", &v[i]);
		memset(dp,0xcf, sizeof(dp));
		dp[0]=0;
		for(int i=1; i<=n ;i++){
			for(int j=m; j>=v[i]; j--){
				dp[j] = max(dp[j],dp[j-v[i]]+w[i]);
			}
		}
		int ans=0;
		for(int i=0; i<=m; i++) ans = max(ans, dp[i]);
		cout<<ans;
	}
	
	return 0;
}
