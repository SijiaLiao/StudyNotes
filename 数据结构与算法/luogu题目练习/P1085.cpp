#include<iostream>
using namespace std;

int main(){
	int arr[8];
	int a,b;
	int max_day=1,max=0;
	for(int i=1;i<=7;i++){
		cin>>a>>b;
		arr[i] = a+b;
		if(arr[i]>max) max_day = i, max = arr[i];
	}
	if(max<=8) cout<<0;
	else cout<<max_day;
	return 0;
	
}
