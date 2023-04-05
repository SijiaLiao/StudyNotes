/*
输入一个不小于 100100 且小于 10001000，同时包括小数点后一位的一个浮点数，例如 123.4123.4 ，要求把这个数字翻转过来，变成 4.3214.321 并输出。
*/
#include<iostream> 
using namespace std;

int main(){
	string in;
	cin>>in;
	int len = in.size();
	for(int i=len-1;i>=0;i--) cout<<in[i]; 
	return 0;
}
