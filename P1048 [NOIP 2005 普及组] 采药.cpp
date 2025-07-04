#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int T,M,t[101],w[101],f[1001][101];
int main()
{
	scanf("%d%d",&T,&M);
	for(int i = 1;i <= M;i++)
	{
		scanf("%d%d",&t[i],&w[i]);
	}
	for(int i = 1;i <= M;i++)
	{
		for(int j = T;j >= 0;j--)
		{
			if(j >= t[i])
			{
				f[i][j] = max(f[i - 1][j],f[i - 1][j - t[i]] + w[i]);
			}
			else
			{
				f[i][j] = f[i - 1][j];
			}
		}
	}
	printf("%d",f[M][T]);
	return 0;
}
