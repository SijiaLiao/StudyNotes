#include<iostream>
using namespace std;

int n; //µÚ¼¸Äê
int dp[60][5]; 

int main(){
	
	while(cin>>n){
		if(n==0) break;
		
		long long ans = 0;
		dp[1][0]=1, dp[1][1]=0; dp[1][2]=0; dp[1][3]=0; dp[1][4]=1;
		if(n==1){
			cout<<1<<endl;
			continue;
		}
		for(int i=2; i<=n; i++){
			dp[i][1] = dp[i-1][0];
			dp[i][2] = dp[i-1][1];
			dp[i][3] = dp[i-1][2];
			dp[i][4] = dp[i-1][3] + dp[i-1][4];
			dp[i][0] = dp[i][4];			
		}
		ans = dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4] - 1;
		cout<<ans<<endl;
	}
	return 0;
} 
