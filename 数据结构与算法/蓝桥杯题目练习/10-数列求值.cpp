#include<iostream>
#include<string.h>
using namespace std;
typedef long long ll;
const int MAX= 30000000;
int a[MAX][5];
int cnt=0;

void add(int i, int j){// jº”µΩi…œ 
	for(int x=1;x<=5;x++){
		a[i][x] += a[j][x];
	}
	for(int x=1; x<=4; x++){
		if(a[i][x]>=10){
			a[i][x+1] ++;
			a[i][x] %= 10;
		}
	} 
	a[i][5] %= 10;
	return ;
}
int main(){
	memset(a, 0, sizeof(a));
	a[1][1]=a[2][1]=a[3][1]=1;
	for(int i=4; i<=20190324; i++){
		
		add(i, i-1);
		add(i, i-2);
		add(i, i-3);
		if(i%10000==0){
			cout<<i<<' ';
			for(int x=5; x>=1; x--) cout<<a[i][x];
			cout<<endl;
		} 
	}
	for(int x=5; x>=1; x--) cout<<a[20190324][x];
	return 0;
}
