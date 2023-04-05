#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

char s[4][4];
bool a[4][4], c[4][4];

int num(int x){ // 判断有几个1 
	int ans =0;
	while(x){
		ans ++;
		x -= x & -x;
	}
	return ans;
}

void dj(int x, int y){
	for(int i=0;i<4;i++){
		c[i][y] ^= 1;
		c[x][i] ^= 1; 
	}
	c[x][y] ^= 1; // 点击了两次 
}

bool pd(int x){
	//cout<<x<<' ';
	memcpy(c,a,sizeof(c));
	while(x){
		int k = log2(x & -x);
		//cout<<k<<' ';
		dj(k/4,k%4);
		x -= x & -x; 
	}
	//  判断点击 后是否是成功的
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++){
			//cout<<c[i][j]<<' ';
			if(c[i][j]){
				//cout<<endl;
				return false;
			} 
		}
			
	//cout<<endl;		
	return true;
}
int main(){
	
	memset(a,0,sizeof(a));
	for(int i=0;i<4;i++){
		cin>>s[i];
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(s[i][j]=='+') a[i][j] = 1; //关 
			else if(s[i][j]=='-') a[i][j] = 0; //开 
		}
	}
	
	int ans = 17; // 最大按把手的次数不超过17次 
	int x=0;
	
	for(int i=0;i<(1<<16);i++){
		 int n = num(i);  
		 if(n<ans && pd(i)){
		 	ans = n;
		 	x = i;
		 }
	}
	
	cout<<ans<<endl;
	while(x){
		int k = log2(x & -x);
		cout<<k/4+1<<' '<<k%4+1<<endl;
		x -= x & -x;
	}
	return 0;
}
