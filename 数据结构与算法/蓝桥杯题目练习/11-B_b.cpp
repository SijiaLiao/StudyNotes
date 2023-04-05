#include<iostream>
using namespace std;

int count=0;

int gcd(int a,int b){
	if(a%b==0) return b;
	return gcd(b,a%b);
}

int main(){
	for(int i=1;i<=2020;i++)
		for(int j=1;j<=2020;j++) if(gcd(i,j)==1) 
			count++;
	cout<<count;
	return 0;
}
