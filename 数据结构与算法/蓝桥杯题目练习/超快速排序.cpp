#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N = 500006;
// ��һ������ð��������С�������� ����������������Եĸ���	 
int n; // ���г��� 
int a[N],b[N];
ll ans;

void merge(int l,int r){
	int mid = (l+r)>>1;
	// ����߽�
	if(l==r) return;
	if(l+1==r){
		if(a[l]>a[r]){
			ans++;
			swap(a[l],a[r]);
		}
	} 
	
	// �ݹ�
	merge(l,mid);
	merge(mid+1,r);
	
	// �ϲ���������
	int i=l, j=mid+1;// ������Ŀ�ͷ ������Ŀ�ͷ 
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
	// ��������е�����
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	ans =0;
	merge(1,n);
	cout<<ans<<endl; 
}

int main(){
	while(cin>>n && n) Ultra_QuickSort(); 
	return 0;
} 
