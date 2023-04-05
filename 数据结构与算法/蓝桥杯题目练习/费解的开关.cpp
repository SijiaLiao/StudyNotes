#include<iostream>
#include<string.h>
using namespace std;

int n,ans;
int a[6],aa[6];
char s[6];

void dj(int x, int y){ //第几行（1-5） 第几位（0-4） 
	// 将当前位变为0
	aa[x] ^= (1<<y); 
	// 将其余四位 变为0 
	if(x!=1) aa[x-1] ^= (1<<y);
	if(x!=5) aa[x+1] ^= (1<<y);
	if(y!=0) aa[x] ^= (1<<(y-1));
	if(y!=4) aa[x] ^= (1<<(y+1));
}

void pd(int p){
	int k=0; 
	memcpy(aa,a,sizeof(a)); // 将当前所有的数据拷贝到另一个数组中 
	// 第一行数据 
	for(int i=0;i<5;i++){ 
		if(!((p>>i)&1)){ // 如果第一行第i位为0 就点击它 使之为1 
			dj(1,i);
			if(++k >= ans) return;
		} 
	}
	// 其余四行 
	for(int x=1;x<5;x++)
		for(int y=0;y<5;y++)
			if(!((aa[x]>>y)&1)){
				dj(x+1,y);
				if(++k >= ans) return;
			}
	if(aa[5] == 31) ans = k;
}
int main(){
	cin>>n; //数据共有几组
	while(n--){
		memset(a,0,sizeof(a));
		for(int i=1;i<6;i++){
			cin>>(s+1);// 从s[1]开始计入
			for(int j=1;j<6;j++) a[i] = a[i]*2 +(s[j]-'0');// 将每一行数据直接记录为二进制数据
		}
		// 枚举第一行所有数据的状态(0代表不按 代表按） 然后固定第一行 
		ans = 7;
		for(int i=0;i<(1<<5);i++) pd(i); 
		if(ans==7) cout<<"-1"<<endl;
		else cout<<ans<<endl;
	} 
	return 0;
}
