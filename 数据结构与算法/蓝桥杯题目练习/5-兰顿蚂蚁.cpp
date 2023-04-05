#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int m,n;
int arr[105][105];
string fx="LURD";
int fxmove[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
char s;
int x,y,k;// 行号 列号 步数 
int main(){
	memset(arr,0,sizeof(arr));
	cin>>m>>n;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++) scanf("%d",&arr[i][j]);
	}
	cin>>x>>y>>s>>k;
	
	int indexfx=0; 
	int color=0;
	for(int i=0;i<k;i++){
		
		indexfx = fx.find(s);// 判断当前方向
		color = arr[x][y];// 判断当前格子颜色 0白 1黑 
		
		// 转向 90
		if(color==0){
			if(indexfx==0) indexfx = 3;
			else indexfx -= 1;
		}else if(color ==1){
			indexfx = (indexfx +1)%4;
		}
		
		s = fx[indexfx];
		
		// 行走 改变格子颜色 
		if((x+fxmove[indexfx][0]) >=0 && (y+fxmove[indexfx][1])>=0){
			arr[x][y] = !arr[x][y];
			x += fxmove[indexfx][0];
			y += fxmove[indexfx][1];
		}
		
	}
	cout<<x<<' '<<y;
	return 0;
}
