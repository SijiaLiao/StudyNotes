#include<iostream>
using namespace std;

int n; //²âÊÔÊµÀý 
int a, b;
int dp[60];
int main(){
	cin>>n;
	while(n--){
		cin>>a>>b;
		dp[a]=1, dp[a+1]=1;
		if(b==a || b==a+1){
			cout<<1<<endl;
			continue;
		}
		for(int i=a+2; i<=b; i++){
			dp[i] = dp[i-1] + dp[i-2];
		}
	}
	cout<<dp[b]<<endl;
	return 0;
}
