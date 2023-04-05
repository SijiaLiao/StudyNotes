#include<iostream>
using namespace std;

int main(){
	int n,local,luogu;
	cin>>n;
	local = 5*n;
	luogu = 11+3*n;
	if(local > luogu) cout<<"Luogu";
	if(luogu > local) cout<<"Local";
	
	return 0;
}
