#include<iostream>
#include<string.h>
#include<cmath>
#include<stdio.h>
using namespace std;

typedef long long ll;
const int MAXN = 200000;
int t;//ѯ���� 
int n;//���г��� 
ll a;
int num[30];//��¼ÿһλΪ1�ĸ��� 
ll ans=0;

void calc_num(ll x){
	while(x){
		int y = log2( x & -x );
		num[y] ++;
		x -= x & -x;
	}
}

void calc(){
	memset(num,0,sizeof(num));
	ans = 0;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld", &a);
		ans ^= a;
		calc_num(a);
	}
	
	if(ans==0){
		cout<<0<<endl;
		return;
	}
	
	for(int i=20;i>=0;i--){
		//cout<<num[i]<<endl;
		//���λֻ��һ��1
		if(num[i]==1){
			cout<<1<<endl;
			return;
		}else if(num[i]&1){ //���λnum����Ϊ 
			if(n&1) cout<<1<<endl;
			else cout<<-1<<endl;
			return;
		}
	} 
	//cout<<0<<endl;
	//if(t != 0) cout<<endl;
	return;
}
int main(){
	cin>>t;
	while(t--){
		calc();
	}
	return 0;
} 
