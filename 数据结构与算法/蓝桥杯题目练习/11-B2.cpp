#include<iostream>
using namespace std;

int ans;
int gcd(int a, int b){
	return b ? gcd(b,a%b) : a;
}
int main(){
	for(int i=1;i<=2020;i++){
		for(int j=i;j<=2020;j++){
			if(gcd(i,j)==1){
				if(i == j) ans ++;
				else ans += 2; 
			}
		}
	}
	cout<<ans;	
	return 0;
} 
