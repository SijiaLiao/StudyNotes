#include<iostream>
using namespace std;

int count=0;
int n;
int cal(int k){
	if(k>n) return 0;
	if(k==n){
		count ++;
		return 0;
	}
	cal(k+1);
	cal(k+2);
}
int main(){
	cin>>n;
	cal(0);
	cout<<count;
	return 0;
} 
