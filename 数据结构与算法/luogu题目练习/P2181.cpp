#include<iostream>
using namespace std;

int main(){
	unsigned long long n;
	cin>>n;
	if(n==3) cout<<0<<endl;
	else cout<<(n-3)*(n-2)/2*(n-1)/3*n/4<<endl;	
	return 0;
} 
