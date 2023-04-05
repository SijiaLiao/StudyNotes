#include<iostream>
using namespace std;

string s;
int last[200];
int main(){
	cin>>s;
	int len = s.length();
	s = ' '+s;
	
	long long ans=0;
	for(int i=1;i<=len;i++){
		ans += (long long)(i - last[s[i]]) * (len - i +1);
		last[s[i]] = i;
	}
	cout<<ans;
	return 0;
} 
