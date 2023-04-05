#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N = 500006;
int n,m,w;// 数列的长度n 选取m对数据 
ll k; //最大校验值为k
ll a[N], b[N], c[N];

// 合并数列 以及 新增部分的数列 
void gb(int l,int mid, int r){
	int i=l, j = mid+1;
	for(int u=l;u<=r;u++)
		if(j>r || (i<=mid && b[i]<=b[j])) c[u] = b[i++];
		else c[u] = b[j++]; 
} 
// 计算数列的最大校验值
ll f(int l, int r){ 
	if(r>n) r=n;
	int t = min(m,(r-l+1)>>1);// 当前数列可以取到的数据的对数 小于等于 m对 
	
	for(int i=w+1;i<=r;i++) b[i] = a[i]; // 将新增的部分 备份到 b中 
	sort(b+w+1,b+r+1); // 只对新增部分排序 
	gb(l,w,r); // 将数列合并 并备份到c数组中 
	ll sum =0;
	for(int i=0;i<t;i++) sum+= (c[r-i]-c[l+i]) * (c[r-i]-c[l+i]);
	return sum;
}
void Genius_ACM(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) scanf("%lld", &a[i]);
	
	int ans = 0, l=1,r=1; // 分成几段 初始的数列 
	w = 1;
	b[1]=a[1];
	
	while(l<=n){ // 当数列没有划分完时 继续划分 
		int p = 1;
		
		while(p){ // 当p为0时 一次倍增结束 
			ll num = f(l,r+p);// 计算当前p下 数列[l,r+p]的最大校验值 
			if(num<=k){// 如果当前校验值 小于要求的值 r的范围可以确定会扩大至r+p 
				r = w = min(r+p,n);
				for(int i=1;i<=r;i++) b[i] = c[i];// 将当前划分出的数列备份到另一个数组中 
				if(r==n) break;
				p <<= 1; // p的范围进一步扩大 
			}else p>>=1;
		}
		ans++;
		l = r+1;
	}
	cout<<ans<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--) Genius_ACM();
	return 0;
}
