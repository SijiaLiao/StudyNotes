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
int findFa(int x){ // �ҵ����ĸ���� 
	return fa[x]==x ? x: findFa(fa[x]);
}
void merge(int a,int b){
	fa[findFa(a)] = findFa(b);
}
int kruskal(){ //���������
	int res=0,day=0,cnt=0;//res:Ȩֵ��ͬ�ıߵĸ�����cnt:��������ǰ�ı�����day:�ڼ��죨��ߵ�Ȩ��
	for(int i=1;i<m;i++){
		if(findFa(eg[i].head) == findFa(eg[i].tail)) continue; // ����ɻ� 
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
	for(int i=1;i<=n;i++) fa[i]=i; // ���һ��������һ���� 
	cout<<kruskal();
	return 0;
}
