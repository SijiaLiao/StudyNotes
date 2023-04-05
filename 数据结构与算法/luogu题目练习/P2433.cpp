#include<iostream>
#include<string>
#include<iomanip>
#include<math.h>
using namespace std;

int main(){
	int num;//第几个问题
	cin>>num;
	double water;
	int ans;
	double pi = 3.1415923;
	int peach=1;
	
	
	switch(num){
		case 1:
			cout<<"I love Luogu!"<<endl;
			break;
		case 2:
			cout<<6<<' '<<4<<endl;
			break;
		case 3:
			cout<<3<<endl;
			cout<<12<<endl;
			cout<<2<<endl;
			break;
		case 4:
			water = (float)500/3;
			//cout<<setiosflags(ios::fixed)<<setprecision(6)<<water<<endl;
			cout<<fixed<<setprecision(3)<<water<<endl;
			break;
		case 5:
			ans = (260+220)/(12+20);
			cout<<ans<<endl;
			break;
		case 6:
			cout<<sqrt(6*6+9*9)<<endl;
			break;
		case 7:
			cout<<110<<"\n"<<90<<"\n"<<0;
			break;
		case 8:
			cout<<pi*10<<endl<<pi*25<<endl<<4*pi*125/3<<endl;
			break;
		case 9:
			for(int i=1;i<=3;i++){
				peach = (peach+1)*2;
			}
			cout<<peach<<endl;
			break;
		case 10:
			cout<<9<<endl;
			break;
		case 11:
			cout<<(float)100/3<<endl;
			break;
		case 12:
			cout<<13<<endl<<'R'<<endl;
			break;
		case 13:
			cout<<(int)pow(pi*4.0*1064.0/3.0,1.0/3)<<endl;
			break;
		case 14:
			cout<<50<<endl;
			break;
	}
	
	return 0;
} 
