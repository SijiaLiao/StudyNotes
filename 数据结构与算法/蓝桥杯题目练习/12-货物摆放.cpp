#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll n;
vector<ll> a;
int main(){
	cin>>n;
	// ���n������Լ��
	for(ll i=1;i*i<=n;i++){
		if(n%i==0){
			a.push_back(i);
			if(i != n/i) a.push_back(n/i);
		}
	}
	// �����е�Լ���������
	ll len = a.size();
	ll ans =0;
	for(ll i=0;i<len;i++)
		for(ll j=0; j<len; j++)
			for(ll k=0; k<len; k++){
				if(a[i] * a[j] * a[k] == n) ans++; 
			}		
	cout<<ans; 
	return 0;
}
