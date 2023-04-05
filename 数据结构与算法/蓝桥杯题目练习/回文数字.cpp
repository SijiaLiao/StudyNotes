#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int v;
vector<int> res;
int main(){
	cin>>n;	
	
	if(n>=55){
		cout<<-1;
		return 0;
	} 
	for(int i=1;i<10;i++){
		for(int j=0;j<10;j++){
			for(int k=0;k<10;k++){
				if(i+j+k+j+i == n) v=i*10000+j*1000+k*100+j*10+i ,res.push_back(v);
				if(i+j+k+k+j+i == n) v= i*100000+j*10000+k*1000+k*100+j*10+i,res.push_back(v);
			} 
		}
	}
	if(!res.size()) cout<<-1;
    sort(res.begin(),res.end());
    for(int i=0;i<res.size();i++) cout<<res[i]<<endl;
	return 0;
} 
