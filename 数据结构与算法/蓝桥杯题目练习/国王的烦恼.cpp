#include<iostream>
#include<algorithm>
using namespace std;

int m,n;
int fa[10005];
struct edge{
	int head;
	int tail;
	int value;
}eg[100005];

bool cmp(edge a,edge b){
	return a.value>b.value;
}
int findFa(int x){ // 找到树的根结点 
	return fa[x]==x ? x: findFa(fa[x]);
}
void merge(int a,int b){
	fa[findFa(a)] = findFa(b);
}
int kruskal(){ //最大生成树
	int res=0,day=0,cnt=0;//res:权值不同的边的个数、cnt:生成树当前的边数、day:第几天（或边的权）
	for(int i=1;i<m;i++){
		if(findFa(eg[i].head) == findFa(eg[i].tail)) continue; // 避免成环 
		merge(eg[i].head,eg[i].tail);
		if(day != eg[i].value) day = eg[i].value, res++;
		cnt++;
		if(cnt+1==n) break;
	}
	return res;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>eg[i].head>>eg[i].tail>>eg[i].value;
	sort(eg+1,eg+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i; // 最初一个结点就是一棵树 
	cout<<kruskal();
	return 0;
}
