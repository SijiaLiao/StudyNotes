#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int m,n;
int arr[105][105];
string fx="LURD";
int fxmove[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
char s;
int x,y,k;// �к� �к� ���� 
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
		
		indexfx = fx.find(s);// �жϵ�ǰ����
		color = arr[x][y];// �жϵ�ǰ������ɫ 0�� 1�� 
		
		// ת�� 90
		if(color==0){
			if(indexfx==0) indexfx = 3;
			else indexfx -= 1;
		}else if(color ==1){
			indexfx = (indexfx +1)%4;
		}
		
		s = fx[indexfx];
		
		// ���� �ı������ɫ 
		if((x+fxmove[indexfx][0]) >=0 && (y+fxmove[indexfx][1])>=0){
			arr[x][y] = !arr[x][y];
			x += fxmove[indexfx][0];
			y += fxmove[indexfx][1];
		}
		
	}
	cout<<x<<' '<<y;
	return 0;
}
