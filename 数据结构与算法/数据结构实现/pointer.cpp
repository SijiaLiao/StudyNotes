#include<stdio.h>
#include<iostream>
using namespace std;

int strlen(char *s){
	int  n=0;
	for(n=0; *s!='\0'; s++)	n++;
	
	return n;
}
int main(){
	int c =100;
	cout<< &c << endl;
	printf("%x \n",&c); // 16����  %o �˽��ƣ�%c �ַ��� %s �ַ��� 
	printf("%6d ", c); // 6�ַ��� %6.2f ���ַ�������λС�� 
	
	// 2.28
	cout<<endl; 
	char *str = "liaosijia";
	cout<<strlen(str)<<endl;
	int a[5] = {1,2,3,4,5};
	cout<<*(a+2)<<endl; 
	return 0;
	
}
