#include<iostream>
using namespace std;

int ans=0;
int main(){
	for(int i=1;i<=2020;i++){
		int x = i;
		while(x){
			if(x%10==2) ans++;
			x /= 10;
		}
	}
	cout<<ans;
	return 0;
}
