#include<iostream>
#include<stack>
#include<queue>

using namespace std;

struct node{
	int x;
	int y;
};

char map[32][52];//��ŵ�ͼ 
bool vis[32][52];
int record[32][52];
string s = "DLRU";//���� 
queue<node> q;
int dx[] = {1, 0, 0, -1};//�� �� �� ��
int dy[] = {0, -1, 1, 0};

void bfs(){
	node now, next;
	now.x = 0, now.y =0;//��ʼλ��
	vis[0][0] = 1;
	q.push(now);
	
	while(!q.empty()){
		now = q.front(); q.pop();
		for(int i=0; i<4; i++){
			int x0 = now.x + dx[i];
			int y0 = now.y + dy[i];
			// ������Է��ʾͼ��뵽������
			if(map[x0][y0]=='0' && !vis[x0][y0] && x0>=0 &&x0<30 && y0>=0 && y0 <50){
				next.x = x0;
				next.y = y0;
				vis[x0][y0] = 1;
				q.push(next);
				record[x0][y0] = i;//��¼����ô�������� 
			} 
		}
	}
	
	// �ӳ��ڿ�ʼ����ڱ�����¼�� ��˷���ջ�У����ӷ������
	stack<char> st;
	int x = 29, y = 49;
	while(x !=0 || y!= 0){
		int pre = record[x][y];
		st.push(pre);
		x = x - dx[pre];
		y = y - dy[pre];
	} 
	
	while(!st.empty()){
		cout<<st.top();
		st.pop();
	}
}

int main(){
	for(int i=0; i<30; i++) cin>>map[i];
	bfs(); 
	return 0;
}
