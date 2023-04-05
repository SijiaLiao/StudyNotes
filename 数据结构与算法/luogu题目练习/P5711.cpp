#include<iostream>
using namespace std;

int main(){
	int y;
	cin>>y;
	int flag=0;
	if(y%4==0 && y%100 !=0) flag = 1;
	if(y%400==0) flag =1;
	cout<<flag<<endl;
	return 0;
}
