#include<iostream>
using namespace std;
#define ll long long 

ll a,b,p,ans;
int main(){
    cin>>a>>b>>p;
    ans = 0;
    while(b){
        if(b&1) ans = (ans + a)%p;
        a = a*2%p;
        b>>=1;
    }
    cout<<ans;
    return 0;
}
