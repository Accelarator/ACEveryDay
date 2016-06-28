#include<iostream>
using namespace std;

//���ٳ�
long long multi(long long a,long long b,long long mod)
{
	long long ans=0;

	while(b>0)
	{
		if(b&1)
			ans=(ans+a)%mod;
		b>>=1;//*****************��λ�������Ҫ��ֵ*************
		a=(a<<1)%mod;
	}

	return ans;
}

long long data[100];//LUCAS����

int main()
{

	long long sum;
	long long tmp;
	int p;
	int t;

	cin>>t;
	while(t--)
	{
		sum=1;

		cin>>p;

		if(p==2)
		{
			cout<<"yes"<<endl;
			continue;
		}

		data[1]=4;
		sum<<=p;//*****************��λ�������Ҫ��ֵ*************
		sum-=1;

		//��Lucas���еı�
		for(int i=2;i<=p-1;i++)
		{
			tmp=multi(data[i-1],data[i-1],sum);
			data[i]=(tmp-2)%sum;
		}

		if(data[p-1]==0)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}
