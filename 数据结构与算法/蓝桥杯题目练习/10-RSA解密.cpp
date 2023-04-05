#include<iostream>
using namespace std;

typedef unsigned long long ull;

ull n = 1001733993063167141, d = 212353, c = 20190324;

ull p=891234941, q=1123984201; // 1123984201;
ull e=823816093931522017;

bool is_prime(ull x){
	if(x<2) return false;
	for(int i=2; i*i <= x; i++){
		if(x%i==0) return false;
	}
	return true;
}

ull exgcd(ull a, ull b, ull& x, ull& y){
	if(b==0){
		x=1, y=0;
		return a;
	}
	
	ull d = exgcd(b, a%b, x, y);
	ull z = x;
	x = y;
	y = z - y*(a/b);
	return d;
}

ull quickmul(ull a, ull b){
	ull ans = 0;
	while(b){
		if(b&1) ans = (ans+a) %n;
		a = a*2%n;
		b>>=1;
	}
	return ans;
}
ull quickmod(ull a, ull b){
	ull ans = 1%n;
	a = a%n;
	while(b){
		if(b&1) ans = quickmul(ans, a);
		a = quickmul(a,a);
		b>>=1;
	}
	return ans;
}
int main(){
	cout<<n<<endl;
	
//	for(ull i=1000000000; i>=2; i--){
//		if(n%i==0){
//			if(is_prime(i) && is_prime(n/i)){
//				p = i;
//				q = n/i;
//				break;
//			}
//		}
//	}
	
	cout<<p<<' '<<q<<endl;
	ull phi = (p-1)*(q-1);
	ull x1, y1, s;
	//s = exgcd(d,phi,x1,y1);
	//e = (x1+phi)%phi;//823816093931522017
	
	cout<<e<<endl;
	ull ans = quickmod(c,e);
	cout<<ans;
	
	
	return 0;
}
