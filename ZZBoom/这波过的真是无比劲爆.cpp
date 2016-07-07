//poj 3185
//利用bit，通过位运算切换状态 ，然后BFS一下，轻易水过。
//说完好像很简单。。。是的，简单是简单，弱第一次以这种位运算姿势过题，太劲。膜思路 ORZ... 

#include<iostream>
#include<string.h>
#include<set>
#include<queue>
#include<sstream>
using namespace std;

bool vis[1<<21];
int step[1<<21];
int q[100000000];
int head,tail;

int BFS(int x)
{
	memset(vis,0,sizeof(vis));
	vis[x]=1;
	head=0;tail=1;
	q[head]=x;
	step[x]=0;
	while(head<tail)
	{
		int u=q[head];head++;
		if(u==0)
			return step[u];
		for(int i=1;i<19;i++)
		{
			int r=u;
			r^=(1<<i-1)|(1<<i)|(1<<i+1);
			if(!vis[r])
			{
				vis[r]=1;
				step[r]=step[u]+1;
				if(r==0) return step[r];
				q[tail++]=r;
			}
		}
		int r;
		r=u^(1<<0)^(1<<1);
		if(!vis[r])
		{		
			vis[r]=1;
			step[r]=step[u]+1;
			if(r==0) return step[r];
			q[tail++]=r;
		}
		r=u^(1<<18)^(1<<19);
		if(!vis[r])	
		{
			vis[r]=1;
			step[r]=step[u]+1;
			if(r==0) return step[r];
			q[tail++]=r;
		}
	}
	return -1;
	
}

int main()
{
	int ans=0;		
	int x;
	for(int i=0;i<20;i++)
	{
		scanf("%d",&x);
		ans|=(x<<i);
	}
	printf("%d\n",BFS(ans));
	return 0;
}
