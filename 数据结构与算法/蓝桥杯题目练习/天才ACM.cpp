#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N = 500006;
int n,m,w;// ���еĳ���n ѡȡm������ 
ll k; //���У��ֵΪk
ll a[N], b[N], c[N];

// �ϲ����� �Լ� �������ֵ����� 
void gb(int l,int mid, int r){
	int i=l, j = mid+1;
	for(int u=l;u<=r;u++)
		if(j>r || (i<=mid && b[i]<=b[j])) c[u] = b[i++];
		else c[u] = b[j++]; 
} 
// �������е����У��ֵ
ll f(int l, int r){ 
	if(r>n) r=n;
	int t = min(m,(r-l+1)>>1);// ��ǰ���п���ȡ�������ݵĶ��� С�ڵ��� m�� 
	
	for(int i=w+1;i<=r;i++) b[i] = a[i]; // �������Ĳ��� ���ݵ� b�� 
	sort(b+w+1,b+r+1); // ֻ�������������� 
	gb(l,w,r); // �����кϲ� �����ݵ�c������ 
	ll sum =0;
	for(int i=0;i<t;i++) sum+= (c[r-i]-c[l+i]) * (c[r-i]-c[l+i]);
	return sum;
}
void Genius_ACM(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) scanf("%lld", &a[i]);
	
	int ans = 0, l=1,r=1; // �ֳɼ��� ��ʼ������ 
	w = 1;
	b[1]=a[1];
	
	while(l<=n){ // ������û�л�����ʱ �������� 
		int p = 1;
		
		while(p){ // ��pΪ0ʱ һ�α������� 
			ll num = f(l,r+p);// ���㵱ǰp�� ����[l,r+p]�����У��ֵ 
			if(num<=k){// �����ǰУ��ֵ С��Ҫ���ֵ r�ķ�Χ����ȷ����������r+p 
				r = w = min(r+p,n);
				for(int i=1;i<=r;i++) b[i] = c[i];// ����ǰ���ֳ������б��ݵ���һ�������� 
				if(r==n) break;
				p <<= 1; // p�ķ�Χ��һ������ 
			}else p>>=1;
		}
		ans++;
		l = r+1;
	}
	cout<<ans<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--) Genius_ACM();
	return 0;
}
