#include<iostream>
using namespace std;
long long n;
int main(){
	cin>>n;
	while(n) cout<<n<<' ', n >>= 1; 
	return 0;
} 
