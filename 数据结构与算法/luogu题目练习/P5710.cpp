#include<iostream>
using namespace std;

int main(){
	int n=0;
	cin>>n;
	
	int ans[4]={0,0,0,0};
	int f1=0,f2=0;
	
	if(n%2==0) f1 = 1;
	if(n>4 && n<=12) f2 = 1;
	if(f1&f2) ans[0] =1;
	if(f1|f2) ans[1] =1;
	if(f1^f2) ans[2] =1;
	if(!f1 & !f2) ans[3]=1;
	for(int i=0;i<4;i++) cout<<ans[i]<<' ';
	
	return 0;
}
