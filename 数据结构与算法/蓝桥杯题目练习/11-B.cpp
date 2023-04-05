#include<iostream>
#include<math.h>
#include<vector>
#include<map>
using namespace std;

vector<int> prime;
vector<int> fz,fm;
map<int,bool> existed;
long long count=4039;

bool isPrime(int n){
	if(n<2) return false;
	for(int i=2;i<=sqrt(n);i++) if(n%i==0) return false;
	return true;
}

int main(){
	
	for(int i=2;i<=2020;i++){
		if(isPrime(i)) prime.push_back(i),existed[i]=true;
	}
	
	for(int i=2;i<=2020;i++){
		for(int j=2;j<=2020;j++){
			// 分子分母 相等
			if(i==j) continue;
			int min_ij = min(i,j);
			
			// 分子分母有一个是质数
			if(existed[i]||existed[j]){
				if(i%j==0 || j%i==0) continue;
				else{
					count++;
					cout<<i<<' '<<j<<' '<<count<<endl;
					continue;
				} 
			} 
			// 分子分母是合数 
			bool flag=true;
			for(int k=0;prime[k]<=min_ij;k++){
				if(i%prime[k]==0 && j%prime[k]==0){
					flag=false;
					break; 	
				} 
			}
			if(flag) count++,cout<<i<<' '<<j<<' '<<count<<endl;
		}
	}
	cout<<count;
	return 0;
}
