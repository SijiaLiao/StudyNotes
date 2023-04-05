#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
const int MAXN=100005;
int n;
int a[MAXN];
map<int, bool> exist;

void cal(int i){
	int val = a[i]+1;
	while(exist[val]) val++;
	a[i] = val;
}
int main(){
	cin>>n;
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		if(exist[a[i]]) cal(i);
		exist[a[i]] = true;
	}
	
	for(int i=1; i<=n; i++) cout<<a[i]<<' ';
	return 0;
}
