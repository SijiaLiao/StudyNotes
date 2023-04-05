#include<iostream>
#include<iomanip>
using namespace std;

int n,tmp;
int maxn=0,minn=100;
float avg;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>tmp;
		maxn = max(maxn,tmp);
		minn = min(minn,tmp);
		avg += tmp; 
	} 
	
	cout<<maxn<<endl<<minn<<endl<<setiosflags(ios::fixed)<<setprecision(2)<<avg*1.0/n<<endl;
	return 0;
} 
