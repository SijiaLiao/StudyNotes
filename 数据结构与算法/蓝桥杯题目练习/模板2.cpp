// �ж�n�Ƿ�������
bool is_prime(int n){
	if(n<2) return false;
	for(int i=2; i*i<=n; i++){
		if(n%i==0) return false;
	}
	return true;
} 

// �ж�С�ڵ���n����������
int tot =0;
int p[SIZE], v[SIZE];//���� ��Ǻ���
void primes(int n){
	memset(v, 0 sizeof(v));
	
	for(int i=2; i<=n; i++){
		if(v[i]) continue;
		p[++tot] = i;// iΪ����
		for(int j=i; j<=n/i; j++) v[i*j] =1; 
	}
} 

//�ֽ�������
int p[SIZE], c[SIZE];
void divide(int n){
	int m =0;
	for(int i=2; i*i<=n; i++){
		if(n%i==0){//iΪ������ 
			p[++m] = i, c[m]=0;
		}
		while(n%i==0) n/=i, c[m]++; 
	}
	
	if(n>1) p[++m]=n, c[m]=1;
	
} 

// ���Լ��
int gcd(int a, int b){
	return b ? gcd(b,a%b):a;
} 

// ��n��������Լ��
vector<int> res;
void all_pd(int n){
	for(int i=1; i*i<=n; i++){
		if(n%i==0){
			res.push_back(i);
			if(i != n/i) res.push_back(n/i);
		}
	}
} 

// ��1~nÿ��������Լ��
vector<int> factor[SIZE];
void cd_all(int n){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n/i; j++){
			factor[i*j].push_back(i);
		}
	}
} 

// ������֮��
 






























