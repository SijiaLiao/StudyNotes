#include<iostream>
using namespace std;

int main(){
	//int a = 2*20 -1;
	int a = 2*20 -1;
	int sum=0;
	
	for(int i=1;i<=a;i++){
		sum += i;
	}
	int ans=0;
	ans = (sum-a+1 + sum)/2;
	cout<<ans;
	return 0;
}
