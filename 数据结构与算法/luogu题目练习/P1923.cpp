#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int n,m; 
int arr[5000005]; 


int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>arr[i];
	//random_shuffle(arr,arr+n);
	//sort(arr,arr+n);
	
	//quickSort(0,n-1);
	
	nth_element(arr,arr+m,arr+n);
	cout<<arr[m];
	return 0;
}
