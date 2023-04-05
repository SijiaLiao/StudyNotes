#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

int main(){
	double a,b,c,p,ans;
	cin>>a>>b>>c;
	p = (a+b+c)/2;
	ans = pow(p*(p-a)*(p-b)*(p-c),1.0/2);
	cout<<setiosflags(ios::fixed)<<setprecision(1)<<ans<<endl;
	return 0;
}
