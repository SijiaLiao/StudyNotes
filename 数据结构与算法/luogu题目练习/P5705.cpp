/*
����һ����С�� 100100 ��С�� 10001000��ͬʱ����С�����һλ��һ�������������� 123.4123.4 ��Ҫ���������ַ�ת��������� 4.3214.321 �������
*/
#include<iostream> 
using namespace std;

int main(){
	string in;
	cin>>in;
	int len = in.size();
	for(int i=len-1;i>=0;i--) cout<<in[i]; 
	return 0;
}
