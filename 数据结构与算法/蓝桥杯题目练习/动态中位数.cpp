#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<cstdio>
using namespace std;
priority_queue<int> q1,q2; //Ĭ��Ϊ����� �������
//priority_queue<int,vector<int>,greater<int> >q;
//priority_queue<int,vector<int>,less<int> >q;

int p; // ���ݼ��ĸ���  ���ݼ������ݵĸ��� 

void Running_Median(){
	// ������ȶ��� 
	while(q1.size()) q1.pop();
	while(q2.size()) q2.pop(); 	

	int num, n; 
	cin>>num>>n;
	cout<<num<<' '<<(n+1)/2<<endl;
	
	// �����һ������ 
	int a;
	cin>>a;
	cout<<a<<' ';
	
	q2.push(-a); // ���뵽С������ 
	
	int cnt =1;
	for(int i=2;i<=n;i++){ // ʣ�µ����� 
	
		scanf("%d", &a);
		if(a < -q2.top()) q1.push(a); //�������С��q2.top(С���ѣ� �Ͳ��뵽q1(�����) 
		else q2.push(-a); // ���ݴ���С���ѵ�top �Ͳ��뵽 С������ 
		
		// �Ե�
		int s=q1.size(); 
		if(s>i/2){ // ����ѵ���ĿС�ڵ���С���� 
			q2.push(-q1.top());
			q1.pop(); 
		} 
		if(s<i/2){
			q1.push(-q2.top());
			q2.pop();
		}
		if(i&1){
			cout<<-q2.top()<<' ';
			if(!(++cnt % 10)) cout<<endl;
		}
	}
	if(cnt%10) cout<<endl;
}
int main(){
	cin>>p;
	while(p--) Running_Median(); 
	return 0;
}
