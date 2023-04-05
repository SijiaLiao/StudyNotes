#include<iostream>
using namespace std;

int a,b,c;
int cnt=0;
int ans=1;
int main(){
	cin>>a>>b>>c;
	int max=a;
	if(b>a) max = b;
	if(c>max) max = c;
	ans = max; 
	while(ans%a || ans%b || ans%c){
		cnt++;
		ans = max * cnt;
	}
	
	cout<<ans;
	return 0;
}
