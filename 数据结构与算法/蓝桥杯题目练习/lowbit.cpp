#include<iostream>
using namespace std;
#define ll long long
/*
	lowbit : ����n�ж�������Ϊ1�����λ�� ���������λ�Լ��Ժ��ֵ 
	���� 1001000 ����󷵻ص�ְλ1000
	
	����k��ֵΪ[0,35] pow(2,k) mod 37 ���������ǡ��ȡ������1~36 
*/

int H[37]; 
int n; 
int main(){
	for(int i=0;i<36;i++) H[(1ll<<i)%37] = i;
	while(cin>>n){
		while(n){
			cout<<H[(n & -n) % 37] <<endl;
			n -= n&-n;
		}
	}
	return 0;
}
