#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
priority_queue<int> q1,q2;// ����� С���� 
int p;

void Running_Median(){
	// ��ն���
	while(q1.size()) q1.pop(); 
	while(q2.size()) q2.pop();
	
	// ���ǵڼ������ݼ� ���ж��ٸ���λ��
	int num,m;
	cin>>num>>m;
	cout<<num<<' '<<(m+1)/2<<endl;
	
	int a=0,cnt=0;
	for(int i=1;i<=m;i++){
		// �������ݲ�������Ӧ�Ķ��� 
		scanf("%d", &a);
		if(i==1) q2.push(-a);
		else if(a<-q2.top()) q1.push(a);
		else q2.push(-a);
		
		// �Ե�
		int s = q1.size();
		if(s>i/2){
			q2.push(-q1.top());
			q1.pop();
		}else if(s<i/2){
			q1.push(-q2.top());
			q2.pop();
		}
		
		// ����������� ��Ҫ�����Ӧ��ֵ
		if(i&1){
			cout<<-q2.top()<<' ';
			if(++cnt % 10 == 0) cout<<endl;
		} 
	} 
	if(cnt%10) cout<<endl;
};
int main(){
	cin>>p;
	while(p--) Running_Median();
	return 0;
}
