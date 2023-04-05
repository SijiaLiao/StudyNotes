#include<iostream>
#include<string.h>
using namespace std;

typedef long long ll;
const int n=21, m =1<<n;
bool weight[n][n];
ll f[m][n];


int gcd(int a, int b){
	return b ? gcd(b,a%b): a;
} 

void hamilton(){
	memset(f,0,sizeof(f));
	f[1][0] = 1;
	for(int i=1;i<m;i++)
		for(int j=0;j<n;j++) if((i>>j) & 1)
			for(int k=0;k<n;k++) if((i^(1<<j))>>k & 1){
				if(weight[k][j]){
					f[i][j] += f[i^1<<j][k];
				}
			}
	return;
}
int main(){
	memset(weight,0,sizeof(weight));
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j) continue;
			if(gcd(i,j)==1) weight[i-1][j-1] = weight[j-1][i-1] = true;
		}
	}
	hamilton();
	
	ll ans=0;
	for (int i = 1; i <= 20; i ++){
		cout<<f[m-1][i]<<endl;
		ans += f[m-1][i];
	}
		
		
	cout<<ans;
	return 0;
} 
