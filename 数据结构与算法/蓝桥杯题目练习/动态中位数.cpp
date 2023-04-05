#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<cstdio>
using namespace std;
priority_queue<int> q1,q2; //默认为大根堆 升序队列
//priority_queue<int,vector<int>,greater<int> >q;
//priority_queue<int,vector<int>,less<int> >q;

int p; // 数据集的个数  数据集中数据的个数 

void Running_Median(){
	// 清空优先队列 
	while(q1.size()) q1.pop();
	while(q2.size()) q2.pop(); 	

	int num, n; 
	cin>>num>>n;
	cout<<num<<' '<<(n+1)/2<<endl;
	
	// 输出第一个数字 
	int a;
	cin>>a;
	cout<<a<<' ';
	
	q2.push(-a); // 插入到小根堆中 
	
	int cnt =1;
	for(int i=2;i<=n;i++){ // 剩下的数据 
	
		scanf("%d", &a);
		if(a < -q2.top()) q1.push(a); //如果数据小于q2.top(小根堆） 就插入到q1(大根堆) 
		else q2.push(-a); // 数据大于小根堆的top 就插入到 小根堆中 
		
		// 对弹
		int s=q1.size(); 
		if(s>i/2){ // 大根堆的数目小于等于小根堆 
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
