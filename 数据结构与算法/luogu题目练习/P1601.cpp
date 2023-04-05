#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool ifJW(vector<int> jw){
	int len= jw.size();
	bool flag=false;
	for(int i=0;i<len;i++){
		if(jw[i]!=0) {
			flag = true;
			break;
		}
	}
	return flag;
}
int main(){
	string m,n;
	int len_a,len_b;
	vector<int> a,b,gw,jw,t_gw,t_jw;
	cin>>m>>n;
	len_a = m.size(),len_b=n.size();
	for(int i=len_a-1;i>=0;i--) a.push_back(m[i]-'0');
	for(int i=len_b-1;i>=0;i--) b.push_back(n[i]-'0');
	
	if(len_a<len_b){
		for(int i=0;i<(len_b-len_a);i++) a.push_back(0);
	}else if(len_a>len_b){
		for(int i=0;i<(len_a-len_b);i++) b.push_back(0);
	}
	
	for(int i=0;i<a.size();i++) gw.push_back((a[i]+b[i])%10),jw.push_back((a[i]+b[i])/10);
	while(ifJW(jw)){
		gw.push_back(0),jw.insert(jw.begin(),0);
		for(int i=0;i<gw.size();i++){
			t_gw.push_back((gw[i]+jw[i])%10);
			t_jw.push_back((gw[i]+jw[i])/10);
		}
		gw=t_gw, jw=t_jw;
		t_gw.clear(),t_jw.clear();
	}
	
	while(! gw[gw.size()-1] && gw.size()>1) gw.pop_back();
	for(int i=gw.size()-1;i>=0;i--) cout<<gw[i];
	
	return 0; 
	
}
