#include<stdio.h>
#include<queue>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN=1000000;

int fac[]={1,1,2,6,24,120,720,5040,40320,362880};//����չ������
//            0!1!2!3!4!  5!   6!   7!     8!       9!

bool vis[MAXN];//���

int cantor(int s[])//����չ��������е�hashֵ
{
    int sum=0;
    for(int i=0;i<9;i++)
    {
        int num=0;
        for(int j=i+1;j<9;j++)
          if(s[j]<s[i])num++;
        sum+=(num*fac[9-i-1]);
    }
    return sum+1;
}

struct Node
{
    int s[9];
    int loc;//��0����λ��,�ѡ�x"��0
    int status;//����չ����hashֵ
    string path;//·��
}ncur;

string path;
int aim=46234;//123456780��Ӧ�Ŀ���չ����hashֵ
int move[4][2]={{-1,0},{1,0},{0,-1},{0,1}};//u,d,l,r
char indexs[5]="udlr";//��������

bool bfs()
{
    memset(vis,false,sizeof(vis));
    Node cur,next;
    queue<Node>q;
    q.push(ncur);

    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        if(cur.status==aim)
        {
            path=cur.path;
            return true;
        }

        int x=cur.loc/3;
        int y=cur.loc%3;

        for(int i=0;i<4;i++)
        {
            int tx=x+move[i][0];
            int ty=y+move[i][1];

            if(tx<0||tx>2||ty<0||ty>2)continue;

            next=cur;
            next.loc=tx*3+ty;
            next.s[cur.loc]=next.s[next.loc];//��λ
            next.s[next.loc]=0;//��λ
            next.status=cantor(next.s);

            if(!vis[next.status])//��¼·��
            {
                vis[next.status]=true;
                next.path=next.path+indexs[i];

                if(next.status==aim)
                {
                    path=next.path;
                    return true;
                }

                q.push(next);
            }
        }
    }
    return false;
}

int main()
{
    char ch;
    while(cin>>ch)
    {
        if(ch=='x')
		{
			ncur.s[0]=0;
			ncur.loc=0;
		}
        else
			ncur.s[0]=ch-'0';

        for(int i=1;i<9;i++)
        {
            cin>>ch;
            if(ch=='x')
            {
                ncur.s[i]=0;
                ncur.loc=i;
            }
            else ncur.s[i]=ch-'0';
        }

        ncur.status=cantor(ncur.s);

        if(bfs())
        {
            cout<<path<<endl;
        }
        else cout<<"unsolvable"<<endl;
    }
    return 0;
}
