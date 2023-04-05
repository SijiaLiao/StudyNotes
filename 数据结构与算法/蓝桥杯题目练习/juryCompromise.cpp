#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;
#define _ 400
int n=0,m=0;
int a[210],b[210],d[210][30][900],f[30][900];
int ans=0;
int t,suma,sumb; 
int A[30];

void solve(int i, int j, int k){
	if(!j) return ;
	int last = d[i][j][k+_];
	solve(last-1,j-1,k-(a[last]-b[last]));
	A[++t] = last;
	suma += a[last], sumb += b[last];
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	memset(f,0xcf,sizeof(f));
	f[0][_]=0;
	for(int i=1;i<=n;i++){
		// 不取i 
		for(int j=0;j<=m;j++) for(int k=-400;k<=400;k++) d[i][j][k+_] = d[i-1][j][k+_];
		//取i
		for(int j=m;j>=1;j--){
			for(int k=-400;k<=400;k++){
				if(k-(a[i]-b[i])<-400 || k-(a[i]-b[i])>400) continue;
				if(f[j-1][k-(a[i]-b[i])+_]+a[i]+b[i] > f[j][k+_]){
					f[j][k+_] = f[j-1][k-(a[i]-b[i])+_]+a[i]+b[i];
					d[i][j][k+_] = i;
				}
			}
		} 
	} 
	// 得到路径 选择d-p尽可能小 d+p 尽可能大的 
	ans = 400;
	for(int k=-400;k<=400;k++){
		if(f[m][k+_]<-400 || f[m][k+_]>400) continue;
		if(abs(k)<abs(ans) || (abs(k)==abs(ans) && f[m][k+_]>f[m][ans+_])) ans = k;
	}
	t = suma = sumb =0;
	solve(n,m,ans);
	printf("Best jury has value %d for prosecution and value %d for defence:\n", suma, sumb);
	for(int i = 1; i <= t; i++) printf(" %d", A[i]);
	return 0;
} 
