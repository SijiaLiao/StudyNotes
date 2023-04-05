#include <iostream>
using namespace std;
typedef long long LL;
const int N=21,M=1<<N;
bool e[N][N];
LL f[M][N];
 
int gcd(int a,int b)
{
  return b ? gcd(b,a%b) : a;
}
 
 
int main()
{
  
  for(int i=1;i<=21;++i)
  {
    for(int j=i;j<=21;++j)
    {
      if(gcd(i,j)==1)
        e[i-1][j-1]=e[j-1][i-1]=true;
    }
  }
  f[1][0]=1;
  for(int i=1;i<=M-1;++i)
  {
    for(int j=0;j<=20;++j)//计算以第j+1栋教学楼为目标 到达状态i的路数
    {
      if(i>>j&1)
      {
        for(int k=0;k<=20;++k)
        {
          if(i^(1<<j)>>k&1&&e[k][j])
          {
            f[i][j]+=f[i^(1<<j)][k];
          }
        }
      }
    }
  }
  LL ans=0;
  for(int i=1;i<=20;++i)
  {
  	cout<<f[M-1][i]<<endl;
    ans+=f[M-1][i];
  }
  cout<<ans;
  // cout<<881012367360;
  return 0;
}
