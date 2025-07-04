#include<bits/stdc++.h>
using namespace std;
int b,c,z=0;
void dfs(int x,int y,char aa[10010][11])
{
	x++;
	if(x==b)
	{
		z=1;
		return;
	}
	if(aa[y][x]=='X') return;
	char bb[10010][11];
	for(int i=1;i<=c;i++) for(int j=1;j<=b;j++)
	{
		bb[i][j]=aa[i][j];
		if(aa[i][j]=='X')
		{
			if(j-2>0)
			{
				bb[i][j-2]='X';
			}
			bb[i][j]='.';
		}
	}
	if(aa[y+1][x]=='.'&&bb[y+1][x]=='.'&&y+1<=c&&z!=1)
	{
		dfs(x,y+1,bb);
	}
	if(aa[y][x]=='.'&&bb[y][x]=='.'&&z!=1)
	{
		dfs(x,y,bb);
	}
	if(aa[y-1][x]=='.'&&bb[y-1][x]=='.'&&y-1>=1&&z!=1)
	{
		dfs(x,y-1,bb);
	}
}
int main()
{
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	int a,x,y;
	char aa[10010][11];
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		z=0;
		scanf("%d%d",&b,&c);
		for(int j=1;j<=c;j++)
		{
			scanf("\n");
			for(int m=1;m<=b;m++)
			{
				scanf("%c",&aa[j][m]);
				if(aa[j][m]=='s')
				{
					x=m;
					y=j;
					aa[j][m]='.';
				}
			}
		}
		dfs(x,y,aa);
		if(z==1) printf("Yes");
		else printf("No");
	}
	return 0;
}
