#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio> 
using namespace std;

typedef long long LL;
const int MOD = 1000000007;
const int N = 5010;
LL dp[N][N];
char str[N]; //存放括号 
int len;

LL func(){
	memset(dp,0,siezof(dp));
	dp[0][0] = 1;
	for(int i=1;i<=len;i++){
		if(str[i]=='('){
			for(int j=1;j<=len;j++){
				dp[i][j] = dp[i-1][j-1];
			} 
		}else{
			dp[i][0] = (dp[i-1][0] + dp[i-1][1])%MOD;
			for(int j=1;j<=len;j++){
				dp[i][j] = (dp[i-1][j+1] + dp[i][j-1]) % MOD;
			}
		}
	}
	
	for(int i=0;i<=len;i++){
		if(dp[len][i]) return dp[len][i];
		return -1;
	}
}

int main(){
	scanf("%s",str+1);//从下标为1出开始放入
	len = strlen(str+1);
	LL l = func();
	reverse(str+1,str+len+1);
	for(int i=1; i<=len; i++){
		if(str[i]=='(') str[i] = ')';
		else str[i] = '(';
	}
	LL r = func();
	cout<<(l*r)%MOD;
	return 0;
	
}
