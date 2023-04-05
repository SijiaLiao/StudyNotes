#include<iostream>
using namespace std;

int main(){
	int y,m;
	cin>>y>>m;
	int arr[13] {0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(y%4==0 && y%100!=0) arr[2] = 29;
	if(y%400==0) arr[2]=29;
	cout<<arr[m]<<endl;
	return 0;
}
