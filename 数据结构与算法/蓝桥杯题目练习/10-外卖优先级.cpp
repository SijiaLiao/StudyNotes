#include<iostream>
#include<queue>
#include<map>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
const int MAXN =100005;

struct o{
	int s;
	int time;
}order[MAXN]; 

int n,m,t;
int  store[MAXN];
map<int, bool> ma;
int ans=0;
bool cmp(o a, o b){
	return a.time < b.time;
}
int main(){
	
	cin>>n>>m>>t;
	for(int i=1; i<=m; i++){
		scanf("%d%d", &order[i].time, &order[i].s);
	} 
	sort(order+1, order+m+1,cmp);
	
	int pre =0;
	for(int i=1; i<=m ;i++){
		int now = order[i].time;
		int idx = order[i].s;
		
		store[idx] -= now - pre;
		
		if(store[idx]<0) store[idx]=0;
		store[idx] += 2;
		if(store[idx]>=5) ma[idx] = true;
		else ma[idx] = false;
		pre = now;
	}
	for(int i=1; i<=n ;i++){
		if(ma[i]) ans ++;
	}
	cout<<ans;
	return 0;
}
