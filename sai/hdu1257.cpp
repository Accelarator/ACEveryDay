#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>

#define M 100000

using namespace std;

int b[M], h[M];
int cnt;

int main()
{
	int n;
	while(cin >> n)
	{
		memset(b,0,sizeof(b));
		memset(h,0,sizeof(h));
		cnt = 0;

		for(int i=0; i<n; i++)
		{
			cin >> b[i];
			for(int j=0; j<=cnt; j++)
			{
				if(b[i] < h[j])         //������ϵͳ�����������������ֵ
				{
					h[j] = b[i];
					break;
				}
				else if(j == cnt)		//û������ϵͳ��������
				{
					h[++cnt] = b[i];	//�½�����ϵͳ
					break;
				}
			}
			sort(h,h+cnt);         //������ʹ������ֵС������
		}

		cout << cnt << endl;
	}
	return 0;
}
