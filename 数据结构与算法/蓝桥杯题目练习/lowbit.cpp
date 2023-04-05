#include<iostream>
using namespace std;
#define ll long long
/*
	lowbit : 计算n中二进制中为1的最低位数 并返回最低位以及以后的值 
	例如 1001000 计算后返回的职位1000
	
	任意k的值为[0,35] pow(2,k) mod 37 互不相等且恰好取遍整数1~36 
*/

int H[37]; 
int n; 
int main(){
	for(int i=0;i<36;i++) H[(1ll<<i)%37] = i;
	while(cin>>n){
		while(n){
			cout<<H[(n & -n) % 37] <<endl;
			n -= n&-n;
		}
	}
	return 0;
}
