#include<iostream>
#include<stdio.h>
#include<math.h> 
using namespace std;
#define MAXN 100005
int n,f;// n块田地 最少需要f块地
double a[MAXN],b[MAXN], sum[MAXN]; 
double l=0,r=0;
int main(){
	cin>>n>>f;
	
	for(int i=1;i<=n;i++) scanf("%lf",&a[i]),l+=a[i];
	r = l;
	l /= n; //平均值最大的子序列 >= 整个序列的平均值
	while(l+1e-5 < r){
		
		double ans = -1e10;
		double min_val= 0X3f; 
		
		double mid = (l + r)/2;
		
		// 让当前所有的a值 都减去 mid 后 计算当前和最大的子序列
		sum[0] = 0;
		for(int i=1;i<=n ;i++){
			
			b[i] = a[i] - mid;
			sum[i] = sum[i-1] + b[i];
			
			if(i==f) ans = sum[i]; 
			if(i>f){
				min_val = min(min_val, sum[i-f]);		
				ans = max(ans, sum[i] - min_val);
			}
		}  
		if(ans >= 0) l = mid; else r = mid;
	}
	cout<<int(r*1000)<<endl;
	return 0;
}
