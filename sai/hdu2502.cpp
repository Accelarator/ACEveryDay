#include <iostream>
#include <cstdio>
#include <bitset>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
	{
        int n, cnt = 0;
		cin >> n;
        for(int i = (1<<(n-1)); i < (1<<n); ++i)
		{
			//��ʼ��һ��bitset��Ϊi�ĸ���
            bitset<32> t(i);
			//t.count()Ϊt����Ϊ1�Ķ�����λ�ĸ���
            cnt += t.count();
        }
        cout << cnt << endl;
    }
    return 0;
}
