#include<iostReam>
using namespace std;
int count=0;
int main(){
	int tmp=0;
	for(int i=1;i<=2020;i++){
		tmp=i;
		while(tmp){
			if(tmp%10 == 2) count++;
			tmp/=10;
		}
	}
	cout<<count;
	return 0;
} 
