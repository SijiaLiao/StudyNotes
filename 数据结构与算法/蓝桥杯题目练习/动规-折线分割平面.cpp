#include<iostream>
#include<string.h> 
using namespace std;

const int MAXN=10005;
int c;
int n;
long long dp[MAXN];
int main(){
	cin>>c;
	while(c--){
		cin>>n;
		memset(dp,0,sizeof(dp));
		dp[1] = 2;
		if(n==1){
			cout<<dp[1]<<endl;
			continue;
		}
		for(int i=2;i<=n;i++) dp[i] = dp[i-1] + 4*(i-1) + 1;
		cout<<dp[n]<<endl;
	}
	return 0;
} 
