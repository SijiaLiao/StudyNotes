#include<iostream>
#include<string.h>
using namespace std;

int f[5003][5003];
int len=1;
int cal(int k){
	for(int i=1;i<=len;i++) f[k][i]=f[k-1][i]+f[k-2][i];
	for(int i=1;i<=len;i++) if(f[k][i]>=10){
		f[k][i+1] += f[k][i]/10;
		f[k][i] %=10;
		if(f[k][len+1]) len++;
	}
}
int main(){
	int n;
	cin>>n;
	memset(f,0,sizeof(f));
	f[1][1]=1;f[2][1]=2;
	for(int i=3;i<=n;i++) cal(i);
	for(int i=len;i>=1;i--) cout<<f[n][i];
	return 0;
}

