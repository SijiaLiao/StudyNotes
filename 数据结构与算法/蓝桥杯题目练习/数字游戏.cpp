#include<iostream>
using namespace std;

int n,k,T;

long long curr=1;
long long cnt=1;
long long sum=1;
int main(){
	cin>>n>>k>>T;
	for(int i=1;i<T;i++){
		curr = ((cnt + cnt+n-1)*n/2%k + curr%k)%k;
		sum +=curr;
		cnt +=n;
	}
	cout<<sum; 
	return 0;
} 
