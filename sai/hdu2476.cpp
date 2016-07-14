#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

const int MAXN=110;
int dp[MAXN][MAXN];//dp[i][j]��ʾͿi~j����С����
char str1[MAXN],str2[MAXN];
int ans[MAXN];//��¼��С�ı��������ע���Ǹı���֣�

int main()
{
    while(scanf("%s%s",str1,str2)==2)
    {
        int n=strlen(str1);
        memset(dp,0,sizeof(dp));

        //��ʼ������Ϊÿ������Ϳһ��
        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++)
                dp[i][j]=j-i+1;

        //��ֱ��DP����ӿհ״����str2
        for(int i=n-2;i>=0;i--)/***********************ע�����˳�������޺�Ч��************************/
		{
            for(int j=i+1;j<n;j++)
            {
                dp[i][j]=dp[i+1][j]+1;
                for(int k=i+1;k<=j;k++)
				{
					 if(str2[i]==str2[k])//����ֿ�Ϳ������
                        dp[i][j]=min(dp[i][j],dp[i+1][k-1]+dp[k][j]);//�����ʾ�Ȱ�i~j��ɫͿΪstr2[i]��Ȼ��ֳ�������ȥͿɫ
				}
            }
		}

		//һ��һ���ļ����ַ�
        for(int i=0;i<n;i++)
        {
        	//��ʼ����Ϊǰi���ַ�ȫ����Ҫ�ı�
            ans[i]=dp[0][i];

            //�����һ��Ϳ��iλ����Ϊ��i����ȫ��ȫ��ͬ��
            //���������ͬ�ַ���˵�������ַ��㴦����Сֵ��֮ǰ��ͬ���� ���øı䣩
            if(str1[i]==str2[i])
            {
                if(i==0)
					ans[i]=0;
                else
					ans[i]=ans[i-1];
            }

            //����ֿ�Ϳ����Ϊ��j+1~i����ȫ��ͬ��
            //������Ҫȫ���ı������ [i,j]
            for(int k=0;k<i;k++)
                ans[i]=min(ans[i],ans[k]+dp[k+1][i]);
        }
        printf("%d\n",ans[n-1]);
    }
    return 0;
}
