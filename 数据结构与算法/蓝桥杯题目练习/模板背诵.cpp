#include<iostream>
#include<string.h>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;

typedef long long ll;

// a^b
int power(int a, int b, int p){
	ll ans = 1%p;
	while(b){
		if(b&1) ans = (long long) ans * a %p;
		a = (long long) a*a%p;
		b>>=1
	}
	return ans;
} 

// a*b%p
ll calc(ll a, ll b, ll p){
	ll ans = 0;
	while(b){
		if(b&1) ans = (ans+a)%p;
		a = a*2%p;
		b>>=1;
	}
	
	return ans;
}

// 最短hamilton 路径

int f[1<<20][20]
int hamilton(){
	memset(f, 0x3f, sizeof(f));
	f[1][0]=0; 
	for(int i=1; i<1<<20; i++)
		for(int j=0; j<20; j++) if(i>>j&1)
			for(int k=0; k<20; k++) if((i^(1<<j))>>k&1)
				f[i][j] = min(f[i][j], f[i^1<<j][k]+w[k][j]);
	
	return f[(1<<20)-1][n-1];//从结点0到结点1的halmiton路径 
} 

// 任意整数在0-35之间 2^k mod 37 取遍1-36
void mod_mi(){
	int h[37];
	for(int i=0; i<36; i++) h[1ll<<i % 37]=i;
	
} 

// 倍增
void beizeng(){
	int p=0;
	while(p){
		ll num = f(l, r+p)//计算 
		if(num<k){
			// 满足条件
			p <<=1; 
		}else{
			//不满足条件
			p >>=1; 
		}
	}
} 

// 区间最值
void st_prework(){
    //初始化
    for(int i=1; i<=n; i++) f[i][0] = a[i];
    int t = log2(n)+1;
    for(int j=1; j<t; j++){
        for(int i=1; i<=n-(1<<j)+1; i++){
            f[i][j] = max(f[i][j-1], f[i+(1<<(j-1))][j-1]);
        }
    }
}

int st_query(int l, int r){
    int k = log2(r-l+1);
    return max(f[l][k], f[r-(1<<k)+1][k]);
}

// 字典树

int tot =1;
int trie[10000][26];
void insert(char* str){
    int len = strlen(str), p=1;
    for(int i=0; i<len; i++){
        int ch = str[i]-'a';
        if(trie[p][ch]==0) trie[p][ch] = ++tot;
        p = trie[p][ch];
    }
    end[p] = true;
}
bool search(char* str){
    int len = strlen(str), p=1;
    for(int i=0; i<len; i++){
        p = trie[p][str[i]-'a'];
        if(p==0) return false;
    }

    return end[p];
}

// 二叉堆
int heap[1000], n;
void up(int p){
    while(p>1){
        if(heap[p]>heap[p/2]) swap(heap[p], heap[p/2]), p/=2;
        else break;
    }
}
void insert(int val){
    heap[++n] = val;
    up(n);
}

int get_top(){
    return heap[1];
}

void down(int p){
    int s = p*2;
    while(s<=n){
        if(s<n && heap[s]<heap[s+1]) s++;// 取左右较大结点
        if(heap[p]<heap[s]){
            swap(heap[s], heap[p]);
            p = s, s = p*2;
        }else break;
    }
}
void extract(){
    heap[1] = heap[n--];
    down(1);
}



// 深度优先遍历 求重心
int ans, pos;
void dfs(int x){
    v[x] = 1;
    int max_part = 0;
    for(int i=head[x]; i; i<next[i]){
    	int y = ver[i];
    	if(v[y]) continue;
    	dfs(y);
    	size[x] += size[y];
    	max_part = max(max_part, size[y]);
    }
    
    maxpart = max(max_part, n-size[x]);
    if(maxpart<ans){
    	ans = maxpart;
    	pos = x;
    }
}

// 广度优先遍历
void bfs(){
	memset(d, 0, sizeof(d));
	queue<int> q;
	q.push(1), d[1] =1;
	
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(int i=head[x]; i; i=next[i]){
			int y = ver[i];
			if(d[y]) continue;
			d[y] = d[x] +1;
			q.push(y);
		}
	}
} 

// 求联通块的数目
int cnt = 0;
void dfs(int x){
	v[x] = cnt;
	for(int i= head[x]; i; i=neax[i]){
		int y = ver[i];
		if(v[y]) continue;
		dfs(y);
	}
} 

// topsort
void add(int x, int y){
	ver[++tot] = y;
	next[tot] = head[x];
	head[x] = tot;
	
	deg[y]++;
} 

void topsort(){
	queue<int> q;
	for(int i=1; i<=n; i++) if(deg[i]==0) q.push(i);
	while(!q.empty()){
		int x = q.front(); q.pop();
		a[++cnt] = x;
		for(int i=head[x]; i; i=next[i]){
			int y = ver[i];
			if(--deg[y]==0) q.push(y);
		} 
	}
}
int main(){
	
	for(int i=1; i<=n; i++){
		if(!v[i]){
			cnt++;
			dfs(i);
		}
	}
	return 0;
}

