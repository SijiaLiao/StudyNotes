#include<iostream>
#include<string.h>
#include<map>
using namespace std;
#define MAXN 10005
int n,p,h,m;
int a[MAXN]; 
map<pair<int,int>,bool> v;
int main(){
	cin>>n>>p>>h>>m;
	memset(a,0,sizeof(a));
	for(int i=1;i<=m;i++){
		int tmp_a=0, tmp_b=0;// 两个可以互相看见的牛 
		cin>>tmp_a>>tmp_b;
		if(tmp_a>tmp_b) swap(tmp_a,tmp_b);
		if(v[make_pair(tmp_a,tmp_b)]) continue;
		// 一对牛互相可以看见 但是只能判断一次 
		v[make_pair(tmp_a, tmp_b)] =1;
		a[tmp_a+1]--;
		a[tmp_b]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans += a[i];
		cout<<ans+h<<endl;
	} 
	return 0;
}
