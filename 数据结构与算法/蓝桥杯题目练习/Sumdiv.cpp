#include<iostream>
#include<vector>
#include<utility>
#include<map>
using namespace std;
// 分治是将 子问题划分为更小的同类子问题 由同类子问题的结果推出最终的结果 
#define ll long long
const ll MOD = 9901;
ll A,B; 
ll num=0;
vector< pair<ll,ll> > ys;

ll ksm(ll x, ll y){
	ll ans = 1%MOD;
	x %= MOD;
	while(y){
		if(y&1) (ans *=x)%=MOD;
		(x*=x)%=MOD;
		y>>=1;
	}
	return ans;
}

ll get_sum(ll p, ll c){
	// 问题边界
	if(!p) return 0;
	if(!c) return 1;
	
	// 分支条件
	// c为奇数
	if(c&1) return (ksm(p,(c+1)/2)+1)* get_sum(p,c>>1) %MOD;
	// c为偶数
	return (( ksm(p,c/2) + 1 ) * get_sum(p,(c-1)>>1) + ksm(p,c))%MOD; 
}

void fj(){
	for(ll i=2;i*i<=A;i++){
		if(!(A%i)){// i为质数 
			num=0;
			while(!(A%i)) num++, A /= i; 
			ys.push_back(make_pair(i,num));
		}
	}
	if(A != 1) ys.push_back(make_pair(A,1));
} 
int main(){
	cin>>A>>B;
	//将A分解质因数 
	fj();
	ll ans=1;
	for(ll i=0;i<ys.size();i++){
		ll tmp_p = ys[i].first, tmp_c = ys[i].second;
		(ans *=  get_sum(tmp_p,B*tmp_c) ) %= MOD;
	}
	cout<< ans<<endl;
	return 0;
}
