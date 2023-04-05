#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;
typedef long long ll;

int n;
ll ans;
vector<int> a[2];
int c[250010];


void mergeSort(int k, int l, int r){
	int mid = (l+r)>>1;
	//cout<<"l: "<<l<<" mid"<<' '<<mid<<" r: "<<r<<endl;
	if(l==r) return;
	
	mergeSort(k,l,mid);
	mergeSort(k,mid+1,r);
	
	// 合并两个数组 
	int i=l,j=mid+1;
	for(int t=l;t<=r;t++){
		if(j>r || (i<=mid && a[k][i]<=a[k][j])) c[t] = a[k][i++];
		else{
			c[t] = a[k][j++];
			ans += mid-i+1;
		}	
	}
	for(int t=l;t<=r;t++) a[k][t] = c[t];
}
ll cal(int k){
	ans = 0;
	mergeSort(k,0,n*n-2);
	return ans;
}
int main(){
	while(cin>>n){
		
		a[0].clear();
		a[1].clear();
		
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
			int x;
			scanf("%d", &x);
			if(x) a[0].push_back(x);
		}
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
			int x;
			scanf("%d", &x);
			if(x) a[1].push_back(x);
	   }
	   
	   	puts(a[0].size()&&(cal(1) - cal(0) & 1) ? "NIE" : "TAK");

	}	
	return 0;
}
