#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	int grade,n;
	int min,max,sum;
	double avg;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>grade;
		if(i==0) min=max=sum=grade;
		else{
			if(grade<min) min = grade;
			if(grade>max) max = grade;
			sum += grade; 
		}	
	}
	avg = sum*1.0 / n;
	cout<<max<<endl<<min<<endl;
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<avg<<endl;
	return 0;
} 
