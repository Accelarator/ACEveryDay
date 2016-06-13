//��С����ͼ
#include <stdio.h>
#include <queue>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define MAXN 100050
#define MAXM 2000050

using namespace std;

struct Line
{
	int u,v; //��㡢�յ�
	int w; //��Ȩ
	int next; //��һ����
}edge[MAXM]; //�߼�

queue<int>q; //bfs�ö���

int f[MAXN]; //���鼯��

long long int dis=0; //dis=��̾���

int n,m;
int cnt=0,tot=0;//cnt=�ɾ����ĵ�����,tot=��Ч�ߵ�����.
int visit[MAXN],high[MAXN]; //visit[i]=1��ʾ��i���ʹ�,high[i]=��i�ĸ߶�

int head[MAXM];

//�Ȱ��ߵ��յ�߶Ƚ������򣬸߶���ͬ�İ���Ȩ��������
//����д���ɣ�
int cmp(Line a,Line b)
{
	return (high[b.v]<high[a.v]) || ((high[a.v]==high[b.v])&&(a.w<b.w));
}

//��·��ѹ���Ĳ��鼯����
int findSet(int x)
{
	if(f[x]==x)
		return x;
	return f[x]=findSet(f[x]);
}

//��ӱ�s->t,��ȨΪn
void AddLine(int s,int t,int n)
{
	edge[tot].u=s;
	edge[tot].v=t;
	edge[tot].w=n;
	edge[tot].next=head[s];
	head[s]=tot++;
}

void init()
{
	int i,j;

	memset(head,-1,sizeof(head));

	scanf("%d%d",&n,&m);

	for(i=1;i<=n;i++)
	{
		scanf("%d",&high[i]);
	}

	for(i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);

		//�ӱ�
		if(high[u]>=high[v])
			AddLine(u,v,w);
		if(high[v]>=high[u])
			AddLine(v,u,w);
	}
}

void bfs() //bfs�ҿ��ߵ�·
{
	int i,x;
	q.push(1);
	visit[1]=1; //�ǳ���Ҫ������*****************************************
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		cnt++;
		//ע��for���÷�
		for(i=head[x];i!=-1;i=edge[i].next)
		{
			int y=edge[i].v; //��һ���ߵ��յ�
			if(!visit[y])
			{
				visit[y]=1;
				q.push(y); //���õ�δ�����ʹ�����ǣ����
			}
		}
	}
}

//kruscal����С������
void kruscal()
{
	int i,j,rootu,rootv,u,v;
	sort(edge,edge+tot,cmp);

	//���鼯��ʼ��
	for(i=1;i<=n;i++)
		f[i]=i;

	for(i=0;i<tot;i++)
	{
		u=edge[i].u;
		v=edge[i].v;

		if(!visit[u]||!visit[v])
			continue; //����i�������յ�δ���ʹ����������i�Ƿϱ�(�����1����ͨ)

		rootu=findSet(u);
		rootv=findSet(v);

		if(rootu!=rootv)
		{
			f[rootu]=rootv; //û�ϲ��ͺϲ�
			dis+=edge[i].w; //�ۼ���̾���
		}
	}
}

int main()
{
	init();
	bfs();
	kruscal();
	printf("%d %lld\n",cnt,dis);
	return 0;
}
