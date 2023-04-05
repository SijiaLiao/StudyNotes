#include<iostream>
#include<algorithm>
using namespace std;

int n;
int maxn = 1000010;
int tree[maxn],A[maxn],B[maxn];

int lowbit(int x){
	return x&-x;
}
 void update(int x,int val){
 	while(x<maxn){
 		tree[x] += val;
 		x+=lowbit(x);
 	}
 }
 
 int query(int x){
 	int ans=0;
 	while(x){
 		ans += tree[x];
		 x -= lowbit(x); 
 	}
 	return ans;
 }
int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>A[i],B[i]=a[i]; 
	
}
