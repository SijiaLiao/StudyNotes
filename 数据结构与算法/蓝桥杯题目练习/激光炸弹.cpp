#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm> 
using namespace std;
#define MAXX 5006
#define MAXY 5006 
typedef long long ll;
int N;
ll R; // N 个目标 r*r 范围 
int s[MAXX][MAXY];
int ans=0; 
int main(){
	cin>>N>>R;
	memset(s,0,sizeof(s));
	int x,y,w;
	int n=0;
	
	for(int i=0;i<N;i++){
		cin>>x>>y>>w;
		n= max(n,x);
		n= max(n,y);
		s[x][y] += w;
	}
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(!i && !j) continue;
			else if(!i) s[i][j] += s[i][j-1];
			else if(!j) s[i][j] += s[i-1][j];
			else s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
	
			if(i>=R-1 && j>=R-1){
				if(i==R-1 && j==R-1) ans = max(ans,s[i][j]);
				if(i==R-1) ans = max(ans, s[i][j]-s[i][j-R]);
				else if(j==R-1) ans = max(ans, s[i][j]-s[i-R][j]); 
				else ans = max(ans, s[i][j]-s[i-R][j]-s[i][j-R]+s[i-R][j-R]);
			}
		}
	}
	// R大于当前n
	if(R>n) cout<<s[n][n]<<endl; 
	else cout<<ans<<endl;
	return 0;
}
