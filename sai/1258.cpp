//prim���⣬���������õ�TAT
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
#define inf 0x7fffffff

int mp[105][105];
int dis[105];
int jug[105];
int n;

int prim()
{
    int i, j, p;
    int minc, res = 0;
    memset(jug, 0, sizeof(jug));

    jug[0] = 1;

    for (i = 0; i < n; i++)
        dis[i] = mp[0][i];

    for (i = 1; i < n; i++)
    {
        minc = inf;
        p = -1;
        //��0����Ϊ��̾����j
        for (j = 0; j < n; j++)
		{
			if (jug[j]=0 && minc > dis[j])
            {
                minc = dis[j];
                p = j;
            }
		}
		//������С��inf��·��
        if (inf == minc)
            return -1;
		//ȡ��p��
        res += minc;
        jug[p] = 1;
        //����A���ϵ�B���ϵľ���
        for (j = 0; j < n; j++)
		{
			if (jug[j]==0 && dis[j] > mp[p][j])
                dis[j] = mp[p][j];
		}
    }
    return res;
}

int main()
{
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			scanf("%d",&mp[i][j]);
		cout<<prim()<<endl;
	}
	return 0;
}
