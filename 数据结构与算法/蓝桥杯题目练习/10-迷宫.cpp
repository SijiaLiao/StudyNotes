#include<iostream>
#include<stack>
#include<queue>

using namespace std;

struct node{
	int x;
	int y;
};

char map[32][52];//存放地图 
bool vis[32][52];
int record[32][52];
string s = "DLRU";//方向 
queue<node> q;
int dx[] = {1, 0, 0, -1};//上 左 右 下
int dy[] = {0, -1, 1, 0};

void bfs(){
	node now, next;
	now.x = 0, now.y =0;//初始位置
	vis[0][0] = 1;
	q.push(now);
	
	while(!q.empty()){
		now = q.front(); q.pop();
		for(int i=0; i<4; i++){
			int x0 = now.x + dx[i];
			int y0 = now.y + dy[i];
			// 如果可以访问就加入到队列中
			if(map[x0][y0]=='0' && !vis[x0][y0] && x0>=0 &&x0<30 && y0>=0 && y0 <50){
				next.x = x0;
				next.y = y0;
				vis[x0][y0] = 1;
				q.push(next);
				record[x0][y0] = i;//记录是怎么到这个点的 
			} 
		}
	}
	
	// 从出口开始向入口遍历记录， 因此放在栈中，更加方便输出
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
