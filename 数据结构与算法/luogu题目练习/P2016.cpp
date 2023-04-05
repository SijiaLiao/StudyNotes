#include<iostream>
using namespace std;

int main(){
	int n=0,tmp_n=0,tmp_p=1;
	int num,price;
	int ans =0;
	cin>>n;
	for(int i=0;i<3;i++){
		cin>>num>>price;
		tmp_n = num; tmp_p = price;
		while(tmp_n<n) tmp_n<<=1, tmp_p<<=1;
		while(tmp_n>n) tmp_n -=num, tmp_p -=price;
		while(tmp_n<n) tmp_n +=num,tmp_p +=price;
		if(ans==0) ans = tmp_p;
		else if(ans > tmp_p) ans = tmp_p;
	}
	cout<<ans;
	return 0;	
}
