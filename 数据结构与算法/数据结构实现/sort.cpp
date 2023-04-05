#include<iostream>
using namespace std;

void DirectInsertSort(int A[], int n){
	int i,j,temp,cnt;
	for(i=1;i<n;i++){
		if(A[i]<A[i-1]){
			temp = A[i];
			for(j=i-1; A[j]>temp&&j>=0; --j){
				A[j+1] = A[j];
			}
			A[j+1] = temp;
		}
		cnt=0;
		while(cnt<=i){
			cout<<A[cnt++]<<" ";
		}
		cout<<endl;
	}
	
	return ;
}
int main(){
	
	int A[8] = {49,38,66,97,76,13,27,49};
	int n=8;
	cout<<"DirectInsertSort: "<<endl;
	DirectInsertSort(A,n);
	
	return 0;
}
