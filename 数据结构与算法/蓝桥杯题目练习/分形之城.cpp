#include<iostream>
#include<utility> 
#include<math.h>
#include<algorithm>
#include<iomanip>
using namespace std;

typedef long long ll;

ll n;
ll N,A,B;// 街区等级 两个城市的编号 编号-1 

pair<ll,ll> cal(ll n, ll num){ // 计算n级城市编号为num的街区所在的位置 
	ll len = 1ll <<(n-1); // 城市的边长 
	ll cnt = 1ll <<(2*n-2); //  城市的街区数目
	// 问题边界 
	if(n==0) return make_pair(0,0);
	// 分支条件
	pair<ll,ll> des = cal(n-1,num%cnt); // 计算num在n-1级的位置1编号
	//回溯条件 
	ll relative = num / pow(2,2*(n-1));
	ll x = des.first, y= des.second; // 求出num在n-1级城市中的位置  
	
	if(relative == 0) return make_pair(y,x);
	if(relative == 1) return make_pair(x,y+len);
	if(relative == 2) return make_pair(x+len, y+len);
	if(relative == 3) return make_pair(2*len - y -1, len - x -1);
}
int main(){
	cin>>n;
	while(n--){
		 cin>>N>>A>>B;
		// 分别计算 两个街区在n级城市中的的位置
		 pair<ll,ll> pa = cal(N,A-1);// 编号-1
		 pair<ll,ll> pb = cal(N,B-1);
		 ll dx = pa.first - pb.first;
		 ll dy = pa.second - pb.second;
		 cout<<setiosflags(ios::fixed)<<setprecision(0)<<sqrt(dx*dx+dy*dy)*10 <<endl;
	} 
	return 0;
}
