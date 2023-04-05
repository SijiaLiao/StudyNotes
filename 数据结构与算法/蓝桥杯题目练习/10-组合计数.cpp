#include<iostream>
using namespace std;
typedef long long ll;
ll t, k, n, m;
ll mod = 1000000007;
ll mat[1000][1000];

ll recombinat(ll m, ll n){
	if(mat[m][n] != 0) return mat[m][n];
	if(n==0 || m==n){
		mat[m][n] = 1;
		return 1;
	}
	mat[m-1][n-1] = recombinat(m-1, n-1);
	mat[m-1][n] = recombinat(m-1, n);
	mat[m][n] = mat[m-1][n-1] + mat[m-1][n];
	return mat[m][n];
}
int main(){
	
	cin>>t>>k;
	while(t--){
		cin>>n>>m;
		for(ll i=1; i<=n; i++){
			for(int j=0; j<=min(i,m); j++){
				memset(mat, 0, sizeof(mat));
				ll res = recombinat(i,j)%mod;
				if(res % k == 0) ans ++;
			}
		}
		cout<<ans%mod;
	}
	return 0;
}
