#include<iostream>
#include<string.h>
using namespace std;

int n,ans;
int a[6],aa[6];
char s[6];

void dj(int x, int y){ //�ڼ��У�1-5�� �ڼ�λ��0-4�� 
	// ����ǰλ��Ϊ0
	aa[x] ^= (1<<y); 
	// ��������λ ��Ϊ0 
	if(x!=1) aa[x-1] ^= (1<<y);
	if(x!=5) aa[x+1] ^= (1<<y);
	if(y!=0) aa[x] ^= (1<<(y-1));
	if(y!=4) aa[x] ^= (1<<(y+1));
}

void pd(int p){
	int k=0; 
	memcpy(aa,a,sizeof(a)); // ����ǰ���е����ݿ�������һ�������� 
	// ��һ������ 
	for(int i=0;i<5;i++){ 
		if(!((p>>i)&1)){ // �����һ�е�iλΪ0 �͵���� ʹ֮Ϊ1 
			dj(1,i);
			if(++k >= ans) return;
		} 
	}
	// �������� 
	for(int x=1;x<5;x++)
		for(int y=0;y<5;y++)
			if(!((aa[x]>>y)&1)){
				dj(x+1,y);
				if(++k >= ans) return;
			}
	if(aa[5] == 31) ans = k;
}
int main(){
	cin>>n; //���ݹ��м���
	while(n--){
		memset(a,0,sizeof(a));
		for(int i=1;i<6;i++){
			cin>>(s+1);// ��s[1]��ʼ����
			for(int j=1;j<6;j++) a[i] = a[i]*2 +(s[j]-'0');// ��ÿһ������ֱ�Ӽ�¼Ϊ����������
		}
		// ö�ٵ�һ���������ݵ�״̬(0������ ������ Ȼ��̶���һ�� 
		ans = 7;
		for(int i=0;i<(1<<5);i++) pd(i); 
		if(ans==7) cout<<"-1"<<endl;
		else cout<<ans<<endl;
	} 
	return 0;
}
