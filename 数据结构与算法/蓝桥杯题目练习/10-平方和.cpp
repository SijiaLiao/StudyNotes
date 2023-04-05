#include<iostream>
#include<string.h> 
using namespace std;

int a[10000];
int cnt=500;
void add(int x){
	
	int tot =0;
	while(x){
		int y = x%10;
		a[++tot] += y;
		//cout<<a[tot]<<' ';
		x /= 10;
	}
	//cout<<endl;
	for(int i=1; i<=100; i++){
		if(a[i]>=10){
			a[i+1]++;
			a[i] %= 10;
		}
		if(a[i]!=0) cnt = i;
	}
	for(int i=cnt; i>=1; i--) cout<<a[i];
	cout<<endl;
	return ;
	
}
bool pd(int x){
	while(x){
		int y =x %10;
		if(y==0 || y==1 || y==2 || y==9){
			return true;
		}
		x /= 10;
	}
	return false;
}
int main(){
	memset(a,0,sizeof(a));
	
	for(int i=1; i<=2019; i++){
		
		if(pd(i)){
			cout<<i<<' ';
			add(i*i);
		}
		
	}

	//for(int i=cnt; i>=1; i++) cout<<a[i];
	return 0;
}
