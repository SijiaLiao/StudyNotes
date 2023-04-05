#include<iostream>
#include<string.h>
using namespace std;

int arr[1001000];
int n,m;
int cnt=0;
int main(){
	cin>>n>>m;
	memset(arr,0,sizeof(arr));
	arr[m]=arr[n]=1;
	int i; 
	for(i=0;cnt<10000;i++){
		if(arr[i]) arr[i+m]=arr[i+n]=1,cnt++;
		else cnt=0;
	}
	cout<<i-10000-1<<endl;
	return 0;
} 
