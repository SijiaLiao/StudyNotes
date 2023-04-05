// 判断n是否是质数
bool is_prime(int n){
	if(n<2) return false;
	for(int i=2; i*i<=n; i++){
		if(n%i==0) return false;
	}
	return true;
} 

// 判断小于等于n的所有质数
int tot =0;
int p[SIZE], v[SIZE];//质数 标记合数
void primes(int n){
	memset(v, 0 sizeof(v));
	
	for(int i=2; i<=n; i++){
		if(v[i]) continue;
		p[++tot] = i;// i为质数
		for(int j=i; j<=n/i; j++) v[i*j] =1; 
	}
} 

//分解质因数
int p[SIZE], c[SIZE];
void divide(int n){
	int m =0;
	for(int i=2; i*i<=n; i++){
		if(n%i==0){//i为质因数 
			p[++m] = i, c[m]=0;
		}
		while(n%i==0) n/=i, c[m]++; 
	}
	
	if(n>1) p[++m]=n, c[m]=1;
	
} 

// 最大公约数
int gcd(int a, int b){
	return b ? gcd(b,a%b):a;
} 

// 求n的所有正约数
vector<int> res;
void all_pd(int n){
	for(int i=1; i*i<=n; i++){
		if(n%i==0){
			res.push_back(i);
			if(i != n/i) res.push_back(n/i);
		}
	}
} 

// 求1~n每个数的正约数
vector<int> factor[SIZE];
void cd_all(int n){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n/i; j++){
			factor[i*j].push_back(i);
		}
	}
} 

// 求余数之和
 






























