#include<iostream>
using namespace std;

char s[81]; //输入的初始九宫格
int cnt[1<<9],f[1<<9]; //当前状态可以填几个数字， 可填的数字为
int x[9],y[9],z[9],X[81],Y[81];// 当前行可以填的数字，列 小九宫格 i在第几行 第几列
int gx, gy, gz; //当前元素所在行 列 小九宫格 

int get_cnt(int i){
	int ans = 0;
	while(i){
		++ans;
		i -= (i & -i);
	}
	return ans;
}

void get(int i){
	gx = X[i];
	gy = Y[i];
	gz = gx/3*3 + gy/3;
} 

void work(int i, int k){
	get(i);//第几个位置
	x[gx] ^= (1<<k);
	y[gy] ^= (1<<k); 
	z[gz] ^= (1<<k);
} 

bool dfs(int ans){
	if(!ans) return 1; //已经填满了 不用再填了
	int k =0, t;
	for(int i=0; i<81; i++){
		if(s[i]=='.'){
			get(i);
			int w = x[gx] & y[gy] & z[gz];
			if(cnt[w]< k){// 判断先填那个位置的数字 
				k = cnt[w];
				t = i;
			}
		}
	}
	get(t);
	int w = x[gx] & y[gy] & z[gz];
	while(w){
		int now = f[w&-w];
		s[t] = now + '1';// 当前位置就填写now值 
		work(t, now); 
		if(dfs(ans-1)) return 1;
		// 回溯 
		work(t, now);
		s[t] = '.' 
		w -= w & -w; 
	} 
}

void Sudoku(){
	// 初始当前九宫格没有填写任何数字 
	for(int i=0; i<9; i++) x[i] = y[i] = z[i] = (1<<9)-1;
	
	int ans = 0;
	for(int i=0;i<81; i++){
		if(s[i] != '.') work(i, s[i]-'1'); 
		else ans++; //有几个位置没有填写 
	}
	
	if(dfs(ans)) for(int i=0; i<81; i++) cout<<s[i]; //成功则输出对应的值
	cout<<endl; 
}

int main(){
	// 初始化数组
	for(int i=0; i<1<<9; i++) cnt[i] = get_cnt(i); 
	for(int i=0; i<9; i++) f[1<<i] = i;
	for(int i=0; i<81; i++){
		X[i] = i/3;
		Y[i] = i%3;
	} 
	
	// 传入数组
	while(cin>>s && s[0] != 'e') Sudoku(); 
	return 0;
} 
