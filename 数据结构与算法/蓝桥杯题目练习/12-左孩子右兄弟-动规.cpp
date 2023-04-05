#include<iostream>
#include<string.h>
using namespace std;
const int MAXN = 100005;

int N=0,tmp=0,fa=0;
int s[MAXN],f[MAXN],dp[MAXN]; 

int main(){
	cin>>N;
	memset(dp,0,sizeof(dp));
	for(int i=2;i<=N;i++) cin>>tmp,f[i]=tmp,s[tmp]++;
	for(int i=N;i>1;i--) fa = f[i],dp[fa] = max(dp[fa],s[fa]+dp[i]); 
	cout<<dp[1];
	return 0;
}
