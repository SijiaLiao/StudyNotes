#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N = 500006;
// 对一串数据冒泡排序最小交换次数 就是求序列中逆序对的个数	 
int n; // 序列长度 
int a[N],b[N];
ll ans;

void merge(int l,int r){
	int mid = (l+r)>>1;
	// 问题边界
	if(l==r) return;
	if(l+1==r){
		if(a[l]>a[r]){
			ans++;
			swap(a[l],a[r]);
		}
	} 
	
	// 递归
	merge(l,mid);
	merge(mid+1,r);
	
	// 合并两个数组
	int i=l, j=mid+1;// 左数组的开头 右数组的开头 
	for(int k=l;k<=r;k++){
		if(j>r || (i<=mid && a[i]<=a[j])) b[k] = a[i++];
		else{
			b[k] = a[j++];
			ans += mid-i+1;
		} 
	}
	for(int k=l;k<=r;k++) a[k]=b[k];
};
void Ultra_QuickSort(){
	// 输入该序列的数据
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	ans =0;
	merge(1,n);
	cout<<ans<<endl; 
}

int main(){
	while(cin>>n && n) Ultra_QuickSort(); 
	return 0;
} 
