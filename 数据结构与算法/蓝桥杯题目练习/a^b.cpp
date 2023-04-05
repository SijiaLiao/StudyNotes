#include<iostream>
using namespace std;

int a,b,p;
int ans;
int main(){
	cin>>a>>b>>p;
	ans = 1%p; 
	while(b){
		if(b&1)  ans =(long long) ans * a % p;
		a = (long long) a*a % p;
		b>>=1;
	}
	cout<<ans;
	return 0;
} 
