#include<iostream>
#include<utility> 
#include<math.h>
#include<algorithm>
#include<iomanip>
using namespace std;

typedef long long ll;

ll n;
ll N,A,B;// �����ȼ� �������еı�� ���-1 

pair<ll,ll> cal(ll n, ll num){ // ����n�����б��Ϊnum�Ľ������ڵ�λ�� 
	ll len = 1ll <<(n-1); // ���еı߳� 
	ll cnt = 1ll <<(2*n-2); //  ���еĽ�����Ŀ
	// ����߽� 
	if(n==0) return make_pair(0,0);
	// ��֧����
	pair<ll,ll> des = cal(n-1,num%cnt); // ����num��n-1����λ��1���
	//�������� 
	ll relative = num / pow(2,2*(n-1));
	ll x = des.first, y= des.second; // ���num��n-1�������е�λ��  
	
	if(relative == 0) return make_pair(y,x);
	if(relative == 1) return make_pair(x,y+len);
	if(relative == 2) return make_pair(x+len, y+len);
	if(relative == 3) return make_pair(2*len - y -1, len - x -1);
}
int main(){
	cin>>n;
	while(n--){
		 cin>>N>>A>>B;
		// �ֱ���� ����������n�������еĵ�λ��
		 pair<ll,ll> pa = cal(N,A-1);// ���-1
		 pair<ll,ll> pb = cal(N,B-1);
		 ll dx = pa.first - pb.first;
		 ll dy = pa.second - pb.second;
		 cout<<setiosflags(ios::fixed)<<setprecision(0)<<sqrt(dx*dx+dy*dy)*10 <<endl;
	} 
	return 0;
}
