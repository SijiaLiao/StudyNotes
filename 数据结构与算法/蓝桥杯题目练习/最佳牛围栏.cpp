#include<iostream>
#include<stdio.h>
#include<math.h> 
using namespace std;
#define MAXN 100005
int n,f;// n����� ������Ҫf���
double a[MAXN],b[MAXN], sum[MAXN]; 
double l=0,r=0;
int main(){
	cin>>n>>f;
	
	for(int i=1;i<=n;i++) scanf("%lf",&a[i]),l+=a[i];
	r = l;
	l /= n; //ƽ��ֵ���������� >= �������е�ƽ��ֵ
	while(l+1e-5 < r){
		
		double ans = -1e10;
		double min_val= 0X3f; 
		
		double mid = (l + r)/2;
		
		// �õ�ǰ���е�aֵ ����ȥ mid �� ���㵱ǰ������������
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
