#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int arr[3];
	int len = 3;
	for(int i=0;i<len;i++) cin>>arr[i];
	for(int i=0;i<len-1;i++)
		for(int j=0;j<len-i-1;j++)
			if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);

	for(int i=0;i<len;i++) cout<<arr[i]<<' ';
	return 0;
}
