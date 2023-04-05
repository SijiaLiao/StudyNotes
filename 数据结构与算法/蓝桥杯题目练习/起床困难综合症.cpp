#include<iostream>
#include<utility>
#include<stdio.h>
using namespace std;
#define MAXN 100000
int n,m; //n道防守门 最大初始值 
pair<string,int> a[MAXN];
 
int cal(int bit, int now){
	for(int i=0;i<n;i++){ // n道门 计算经过n扇门后的值 
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
	
	// 根据m的最大值确定选择的初始值的最大值为多少
	// 从高位到低位
	int val=0,ans =0;
	for(int i=30;i>=0;i--){
		int res0 = cal(i,0);
		int res1 = cal(i,1);
		if(val+(1<<i)<=m && res0<res1){ // res0 为0 res1 为1 选择1较优 
			val += 1<<i;
			ans +=res1<<i;
		}else ans += res0<<i;
	} 
	cout<<ans;
	return 0;
}
