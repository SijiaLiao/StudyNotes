#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

int main(){
	char right;
	char in[14];
	int sum=0,count=1;
	for(int i=0;i<13;i++) cin>>in[i];
	for(int i=0;i<11;i++){
		if(in[i]=='-') continue;
		sum += (in[i]-'0')*count;
		count++; 
	}
	if(sum%11 == 10) right='X';
	else right = sum%11 + '0';
	if(right == in[12]) cout<<"Right";
	else{
		for(int i=0;i<12;i++) cout<<in[i];
		cout<<right;
	}
	return 0;
}
