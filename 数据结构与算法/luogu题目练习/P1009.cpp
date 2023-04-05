#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int n=0;
vector<int> mul,sum;

bool ifJW(vector<int> jw){
    bool flag = false;
    for(int i=0;i<jw.size();i++){
        if(jw[i] != 0){
            flag = true;
            break;
        } 
    }
    return flag;
}

vector<int> Iterator(vector<int> gw,vector<int> jw){
	int tmp=0;
	vector<int> t_gw,t_jw;
    while(ifJW(jw)){
        gw.push_back(0),jw.insert(jw.begin(),0);
        for(int i=0;i<gw.size();i++){
            tmp = gw[i]+jw[i];
            t_gw.push_back(tmp % 10);
            t_jw.push_back(tmp / 10);
        }
        gw = t_gw, jw = t_jw;
        t_gw.clear(), t_jw.clear();
    }
    return gw;
}

vector<int> Multiply(vector<int> a,int b){
    vector<int> gw, jw;
    for(int i=0;i<a.size();i++){
        gw.push_back(a[i]*b % 10);
        jw.push_back(a[i]*b / 10);
    }
    return Iterator(gw,jw);
}

vector<int> Sum(vector<int> a,vector<int> b){
    int len_a = a.size(),len_b=b.size();
    vector<int> gw, jw;

    if(len_a<len_b){
        for(int i=0;i<(len_b-len_a);i++) a.push_back(0);
    }else if (len_a>len_b)
    {
        for(int i=0;i<(len_a-len_b);i++) b.push_back(0);
    }
    
    int tmp=0;
    for(int i=0;i<a.size();i++){
        tmp = a[i]+b[i];
        gw.push_back(tmp % 10);
        jw.push_back(tmp / 10);
    }
    return Iterator(gw,jw);
}

void cal(int k){
    if(k>n) return;
    vector<int> tmp_mul1,tmp_mul2;
    tmp_mul1 = Multiply(mul,k%10);
    tmp_mul2 = Multiply(mul,k/10);
    //tmp_mul1.push_back(0),
	tmp_mul2.insert(tmp_mul2.begin(),0);
    mul = Sum(tmp_mul1,tmp_mul2);
    
    sum = Sum(sum,mul);
    
    cal(k+1);
}
int main(){
    cin>>n;
    mul.push_back(1),sum.push_back(0);
	cal(1);
	while(!sum[sum.size()-1]) sum.pop_back();
    for(int i=sum.size()-1;i>=0;i--) cout<<sum[i];
    cout<<endl;
    return 0;
}
