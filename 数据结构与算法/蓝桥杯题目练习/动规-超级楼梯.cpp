#include<iostream>
using namespace std;

int n;
int m;
int dp[50];
int main(){
	cin>>n;
	while(n--){
		cin>>m;
		dp[1]=1, dp[2]=1;
		
		if(m==1){
			cout<<dp[1]<<endl;
			continue;
		}else if(m==2){
			cout<<dp[2]<<endl;
			continue;
		}
		
		for(int i=3;i<=m;i++){
			dp[i] = dp[i-1] + dp[i-2];
		}
		
		cout<<dp[m]<<endl; 
	}
	return 0;
} 
