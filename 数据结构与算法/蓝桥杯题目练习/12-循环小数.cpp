#include<iostream>
#include<math.h>
using namespace std;
int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int main(){
	int p,q,x; //  S ��ѭ������С������ p λ����q λ 
	cin>>p>>q>>x;
	int xh,fxh,fz,fm;
	fxh = x/pow(10,q-p+1);
	fz = x-fxh;
	fm =pow(10,q) - pow(10,p-1);
	int ys = gcd(fz,fm);
	fz /= ys;
	fm /= ys;
	cout<<fz<<' '<<fm;
	
	return 0;
} 
