#include<iostream>
#include<utility>
#include<stdio.h>
using namespace std;
#define MAXN 100000
int n,m; //n�������� ����ʼֵ 
pair<string,int> a[MAXN];
 
int cal(int bit, int now){
	for(int i=0;i<n;i++){ // n���� ���㾭��n���ź��ֵ 
		int t = a[i].second>>bit & 1;
		string op = a[i].first;
		if(op == "AND") now=now&t;
		else if(op =="OR") now= now|t;
		else now= now ^ t;
	}
	return now;
}
int main(){
	cin>>n>>m;
	
	char tmp_str[5];
	int tmp_t;
	for(int i=0;i<n;i++){
		scanf("%s%d",tmp_str,&tmp_t);
		a[i] = make_pair(tmp_str,tmp_t);
	}
	
	// ����m�����ֵȷ��ѡ��ĳ�ʼֵ�����ֵΪ����
	// �Ӹ�λ����λ
	int val=0,ans =0;
	for(int i=30;i>=0;i--){
		int res0 = cal(i,0);
		int res1 = cal(i,1);
		if(val+(1<<i)<=m && res0<res1){ // res0 Ϊ0 res1 Ϊ1 ѡ��1���� 
			val += 1<<i;
			ans +=res1<<i;
		}else ans += res0<<i;
	} 
	cout<<ans;
	return 0;
}
