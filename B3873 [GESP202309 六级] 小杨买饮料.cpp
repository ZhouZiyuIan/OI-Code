#include<cstdio>
#include<iostream>
using namespace std;
int N,L,c[501],l[501],totl,f[501][501],ans=2147483647;
int main()
{
	scanf("%d%d",&N,&L);
	for(int i = 1;i <= N;i++)
	{
		scanf("%d%d",&c[i],&l[i]);
		totl += l[i];
	}
	if(totl < L)
	{
		printf("no solution");
		return 0;
	}
	for(int i = 1;i <= N;i++)
	{
		for(int j = 0;j <= L;j++)
		{
			if(j < l[i])
			{
				f[i][j] = f[i - 1][j];
			}
			else
			{
				f[i][j] = min(f[i - 1][j],f[i - 1][j - l[i]] + c[i]);
			}
		}
	}
	for(int i = 1;i <= N;i++)
	{
		ans = min(ans,f[i][L]);
	}
	printf("%d",ans);
}
