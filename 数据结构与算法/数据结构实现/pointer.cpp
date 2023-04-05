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
	printf("%x \n",&c); // 16½øÖÆ  %o °Ë½øÖÆ£»%c ×Ö·û£» %s ×Ö·û´® 
	printf("%6d ", c); // 6×Ö·û¿í %6.2f Áù×Ö·û¿í±£ÁôÁ½Î»Ğ¡Êı 
	
	// 2.28
	cout<<endl; 
	char *str = "liaosijia";
	cout<<strlen(str)<<endl;
	int a[5] = {1,2,3,4,5};
	cout<<*(a+2)<<endl; 
	return 0;
	
}
