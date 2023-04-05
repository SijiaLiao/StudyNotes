#include<iostream>
#include<cstdio>
#include<cmath> 
#include<string.h>
using namespace std;

int n;
long long a[100005];
int w=0;
int cnt=0;

long long maxv=0;
int ans=0;

int lowbit(int x){
	int y;
	while(x){
		y = log2(x & -x);
		x -= x&-x;
	}
	return y;
}
int main(){
	cin>>n;
	int depth= lowbit(n);
	//cout<<depth<<endl;
	memset(a, 0, sizeof(a));
	for(int i=0; i<=depth; i++){
		for(int j=1; j<=pow(2,i); j++){
			scanf("%d", &w);n--;
			a[i] += w;
			if(n==0) break;
		}
		if(a[i]>maxv) maxv = a[i], ans = i+1;
	}
	cout<<ans;
	
	return 0;
} 
