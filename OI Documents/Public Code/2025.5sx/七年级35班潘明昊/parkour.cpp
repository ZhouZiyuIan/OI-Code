#include<bits/stdc++.h>
using namespace std;
int n,m,t,sx,sy;
char s[10005][10005];
bool rng(int x,int y)
{
	for(int i=y;i<=m;i++)
	{
		if(s[x][i]=='X')return false;
	}
	return true;
}
bool solve(int x,int y)
{
	if(rng(x,y))
	{
		return true;
	}
	int mar=0;
	if(s[x+1][y+1]=='.' && s[x+1][y+2]=='.'&& s[x+1][y+3]=='.')
	{
		solve(x+1,y+3);
		mar=1;
	}
	if(s[x-1][y+1]=='.' && s[x-1][y+2]=='.'&& s[x-1][y+3]=='.')
	{
		solve(x-1,y+3);
		mar=1;
	}
	if(s[x][y+1]=='.' && s[x][y+2]=='.'&& s[x][y+3]=='.')
	{
		solve(x,y+3);
		mar=1;
	}
	if(mar==0)return false;
}
int main()
{
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s[i]+1);
			for(int j=1;j<=m;j++)
			{
				if(s[i][j]=='s')
				{
					sx=i;
					sy=j;
					s[i][j]='.';
				}
				
			}
		}
		if(s[sx][sy+1]=='X')
		{
			printf("No\n");
			continue;
		}
		if(solve(sx,sy))printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

