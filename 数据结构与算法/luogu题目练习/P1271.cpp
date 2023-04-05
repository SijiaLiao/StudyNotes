#include<iostream>
#include<string.h>
using namespace std;

int main(){
	int n,m;
	int arr[1005];
	memset(arr,0,sizeof(arr));
	int tmp;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>tmp;
		arr[tmp]++;
	}
	
	for(int i=1;i<=n;i++){
		if(arr[i]>0){
			for(int j=1;j<=arr[i];j++) cout<<i<<' ';
		} 
	}
	return 0;
}

