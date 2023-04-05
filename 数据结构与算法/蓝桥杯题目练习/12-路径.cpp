#include<iostream>
#include<queue> 
#include<string.h>
#include<cmath>
using namespace std;

typedef long long ll;
const int n=2025;
const int m = 100000;
ll ver[m],edge[m],head[n],Next[m];
ll d[n];
bool v[n];

int tot=0;
priority_queue< pair<int, int> > q;


void add(int x, int y, int z){
	
	ver[++tot] = y;
	edge[tot] = z;
	Next[tot] = head[x];
	head[x] = tot;
	
}

int gbs(int a, int b){
	int c = max(a,b);
	int d = min(a,b);
	for(int i=1;i<=d;i++){
		if(c*i%d==0) return c*i;
	}
}

void dijkstra(){
	memset(d, 0x3f, sizeof(d));
	memset(v,0, sizeof(v));
	d[1]=0;
	q.push(make_pair(0,1));
	
	while(q.size()){
		int x = q.top().second; q.pop();
		if(v[x]) continue;
		v[x] = 1;
		
		for(int i=head[x]; i; i=Next[i]){ 
			int y = ver[i];
			int z = edge[i];
			if(d[y] > d[x]+z){
				d[y] = d[x] + z;
				q.push(make_pair(-d[y],y));
			}
		}
	}
	
}
int main(){
	
	int v = 2021;
	for(int i=1;i<=v;i++){
		
		for(int j=i+1; j<= i+21;j++){
			if( j>v) continue;
			int z = gbs(i,j);
			add(i,j,z);
			add(j,i,z);
		}

	}
	
	dijkstra();
	cout<<d[2021];
	return 0;
}
