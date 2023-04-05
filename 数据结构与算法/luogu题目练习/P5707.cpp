#include<iostream>
using namespace std;

int main(){
	int s,v,h,m;
	cin>>s>>v;
	if(s%v) m=s/v+1+10;
	else m= s/v+10;
	
	if(m/60>=8) h = 24-(m/60-8);
	else h = 8-(m/60);
	
	m = m%60;
	h = h-1;
	m = 60-m;
	
	if(h<10) cout<<"0"<<h;
	else cout<<h;
	cout<<":";
	if(m<10) cout<<"0"<<m;
	else cout<<m;
	
	return 0;	
}
