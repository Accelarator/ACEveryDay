#include <iostream>
#include<stdio.h>
using namespace std;

const int MAXN = 30001; /*�����Ŀ����*/

int pa[MAXN];  /*p[x]��ʾx�ĸ��ڵ�*/
int rank[MAXN];/*rank[x]��x�ĸ߶ȵ�һ���Ͻ�*/
int num[MAXN]; /*num[]�洢�ü�����Ԫ�ظ��������ڼ��Ϻϲ�ʱ����num[]����*/

/*����һ����Ԫ��*/
void make_set(int x)
{
    pa[x] = x;
    rank[x] = 0;
    num[x] = 1;
}

/*��·��ѹ���Ĳ���*/
int find_set(int x)
{
    /*��������ҵ���*/
    int r=x;
    int temp;

    /*�ҵ����ڵ�*/
    while(pa[r] != r)
		r = pa[r];

    //�ݹ�д��
    if(x != pa[x])
        pa[x] = find_set(pa[x]);
    return pa[x];
    //����д��
    /*while(x != r)
    {
        temp = pa[x];
        pa[x] = r;
        x = temp;
    }
    return x;*/
}

/*���Ⱥϲ�x��y���ڵļ���*/
void union_set(int x, int y)
{
    x = find_set(x);
    y = find_set(y);
    if(x == y)return ;
    if(rank[x] > rank[y])/*��rank�Ƚϸߵ���Ϊ�����*/
    {
        pa[y] = x;
        num[x] += num[y];
    }
    else
    {
        pa[x] = y;
        if(rank[x] == rank[y])
            rank[y]++;
        num[y] += num[x];
    }
}

int main()
{
    int n, m, x, y, i, t, j;
    while(cin>>n>>m,(m+n))
    {
        if(m == 0)
        {
            cout << "1\n"; continue;
        }
        for(i = 0; i < n; i++)
            make_set(i);
        for(i = 0; i < m; i++)
        {
            scanf("%d", &t);
            scanf("%d", &x);
            for(j = 1; j < t; j++)
			{
                scanf("%d", &y);
                union_set(x, y);
                x = y;
            }
        }
        x = find_set(0);/*�ҵ�0���ڵ���������*/
        cout << num[x] << endl;
    }
    return 0;
}
