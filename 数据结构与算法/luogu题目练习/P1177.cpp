#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int arr[100005];
int N;

int main(){
	
	cin>>N;	
	for(int i=0;i<N;i++) cin>>arr[i]; 
	random_shuffle(arr,arr+N); // ´òÂÒĞòÁĞ
	sort(arr,arr+N);
	for(int i=0;i<N;i++) cout<<arr[i]<<' ';
	
	return 0;
}
