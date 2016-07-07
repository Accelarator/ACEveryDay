//poj1416

#include<cstdio>
#include<math.h>
#include<queue>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
#define INF 9999999
const double pi=3.1415926535897932;
#define N 1000010

int vis[N];
int ans;
int sum;
int path; 
int p;
int n;

int getlen(int n)
{
	if(n<10)
	return 1;
	if(n<100)
	return 2;
	if(n<1000)
	return 3;
	if(n<10000)
	return 4;
	if(n<100000)
	return 5;
	return 6;
}

int getvalue(char *s,int i)
{
	int k=i;
	int sum=0;
	while(k)
	{
		k--;
		sum+=(s[k]-'0')*(int)pow(10.0,(double)(i-k-1)); 
	}
	return sum;
}

int gethead(int n,int i)
{
	int len=getlen(n);
	if(len<=i)
		return n;
	return n/(int)pow(10.0,(double)len-i);
}

int gettail(int n,int i)
{
	return n%(int)pow(10.0,(double)i);
}

void DFS(char *s,int len)
{
	if(!len)
	{
		vis[sum]++;
		if(sum>ans&&sum<=n)
		{
			ans=sum;
			path=p;
		}
		return;
	}
	
	for(int i=1;i<=len;i++)
	{
		int a=getvalue(s,i);
		sum+=a;
		
		if(sum>n)
		{
			sum-=a;
			continue;
		}
		
		p=p*10+i;
		
		char b[7];
		int j=0;
		for(int k=i;k<len;k++)
			b[j++]=s[k];
		b[j]='\0';
		
		DFS(b,len-i);
		
		sum-=a;
		p/=10;
	}
	return;
}


int main()
{
	while(1)
	{
		char s[8];
		cin>>n>>s;
	
		int len=strlen(s);
		int tt=getvalue(s,len);
		
		if(!n&&!tt)
			break;
		
		if(n==tt)
		{
			cout<<n<<" "<<tt<<endl;
			continue;
		}
		
		int num=tt;
		int k=0;
		while(num)
		{
			k+=num%10;
			num/=10;
		}
		if(k>n)
		{
			cout<<"error"<<endl;
			continue;
		}
		
		ans=-1;
		sum=path=p=0;
		memset(vis,0,sizeof(vis));
		
		DFS(s,len);
		
		if(vis[ans]>1)
		{
			cout<<"rejected"<<endl;
		}
		else if(vis[ans]==1)
		{
			cout<<ans<<" ";
			
			int L=getlen(path);
			
			for(int i=1;i<=L;i++)
			{
				int k=gethead(path,1);
				cout<<gethead(tt,k)<<" ";
				tt=gettail(tt,len-=k);
				path=gettail(path,L-i);
			}
			puts("");
		}
	}
	return 0;
}


 
