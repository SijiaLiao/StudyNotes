#include<iostream>
using namespace std;

int main(){
	int a, b, c, d;
	int e,f;
	cin>>a>>b>>c>>d;
	if(d<b) d += 60, c -=1;
	cout<<(c-a)<<' '<<(d-b)<<endl; 
	return 0; 
}
