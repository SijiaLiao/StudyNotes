#include<iostream>
#include<string.h>
using namespace std;

int out(int y,int m, int d){
	cout<<y;
	if(!(m/10)) cout<<"0";
	cout<<m;
	if(!(d/10)) cout<<"0";
	cout<<d;
	return 0;
}

int main(){
	string in;
	int y,m,d;
	bool flag = true, flag_2 = true;
	int arr[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	
	cin>>in;
	y = (in[0]-48)*1000 + (in[1]-48)*100 + (in[2]-48)*10 + (in[3]-48);
	if(in[0]==in[7] && in[1]==in[6] && in[2]==in[5] && in[3]==in[4]) y++;
	while(flag || flag_2){
		m = y%10*10 + (y/10)%10;
		d = (y/100)%10*10 + (y/1000);
		
		if(y%4==0 && y%100 != 0) arr[2]=29;
		if(y%400==0) arr[2]=29;
		
		if(m>0 && m <13){
			if(d>0 && d<=arr[m])
				if(flag) out(y,m,d),cout<<endl,flag=false;
				if(d==m) out(y,m,d),flag_2=false;
		}
		arr[2]=28;
		y++;
	}
	return 0;
}
