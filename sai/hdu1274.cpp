#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include<stdio.h>
using namespace std;

string s;

int fun(int ith)
{
	int k,e;
	char c;
	/***************�ݹ�������������ַ�������������������*/
	for(c=s[ith++] ; ith<s.size()&&c!=')' ; c=s[ith++])//
	{
		//���㲢ͳһϵ��k������ϵ��Ϊϵ��1��*****������
		for(k=0 ; isdigit(c) ; c=s[ith++])
			k=k*10+(c-'0');
		if(k==0)
			k=1;

		//k������ǰ��ϵ��
		if(c=='(')
		{
			//��ÿ�����ŵݹ�
			while(k--)
				e=fun(ith);
			//��Ϊ��ȡ�ַ�������ith�����ģ����Դ���������ֱ���������ŵ���һ���ַ�
			//����ith��ֵ�����²�ݹ������λ��
			ith=e;
		}
		//k���ַ�ǰ��ϵ��
		else
		{
			while(k--)
				putchar(c);
		}
	}
	//���ر��ζ�����β��λ��
	if(c==')')
		return ith;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		s.clear();
		cin>>s;
		fun(0);
		cout<<endl;
	}
	return 0;
}
