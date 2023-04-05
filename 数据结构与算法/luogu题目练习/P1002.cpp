#include<string.h>
#include<iostream>
using namespace std;

int horse[9][2]={{0,0},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
int v[21][21];
int zx,zy,n,m;
long long count=0;

int cal(int x,int y){
	if(x==zx && y==zy) {
		count++;
		return 0;
	}
	if(x<0 || x>zx || y<0 || y>zy || v[x][y]==1) return 0;
	cal(x+1,y);
	cal(x,y+1);
}

int main(){
	cin>>zx>>zy>>n>>m;
	int tmpx,tmpy;
	memset(v,0,sizeof(v));
	for(int i=0;i<9;i++){
		tmpx=n+horse[i][0],tmpy=m+horse[i][1];
		if(tmpx>=0 && tmpx<=zx && tmpy>=0 && tmpy<=zy) v[tmpx][tmpy] = 1;
	}
	cal(0,0);
	cout<<count;
	return 0;
} 
