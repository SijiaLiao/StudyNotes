#include<iostream>
#include<string.h>
#include<stdio.h> 
#include<algorithm>
using namespace std;
#define MAXN 100005
typedef long long ll;
int n;// n������
ll a[MAXN],b[MAXN];// ������� 
int main(){
	cin>>n;
	memset(b,0,sizeof(b));
	a[0] = 0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		b[i] = a[i]-a[i-1]; 
	} 
	ll p=0,q=0;// b1~bn������ ������ 
	for(int i=2;i<=n;i++){
		if(b[i]>0) p+=b[i];
		else if(b[i]<0) q-=b[i];
	} 
	cout<<max(p,q)<<endl<<abs(p-q)+1<<endl;
	return 0;
}
