#include<iostream>
#include<map> 
using namespace std;
string s;
int main(){
	cin>>s;

	int len = s.size();
	int cnt=0;
	long long count=0,sum=0;
	
	while(cnt<len){
		map<char,int> mapchar;
		for(int i=cnt;i<len;i++){
			if(!mapchar.count(s[i])) mapchar.insert(pair<char,int>(s[i],1)),count++; 
			else if(mapchar.at(s[i])==1) count--,mapchar[s[i]]+=1;
			sum +=count;
		}
		cnt++,count=0;
	}
	cout<<sum;
	return 0;
} 
