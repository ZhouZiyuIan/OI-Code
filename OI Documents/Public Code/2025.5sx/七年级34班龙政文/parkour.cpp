#include<bits/stdc++.h>
using namespace std;
int t,sx,sy,n,m,mark;
char a[10005][10005];
void fun(int x,int y)
{
	if(y>n)
	{
		mark=1;
		return;
	}
	if(x>=1 && x<=m && a[x][y+1]!='X')
	{
		int kx=0;
		for(int j=y+1;j<=y+3;j++)
		{
			if(a[x][j]=='X')
			{
				kx=1;
			}
		}
		if(kx==0)
		{
			fun(x,y+3);
		}
	}
	if(x!=1 && a[x][y+1]!='X' && a[x-1][y+1]!='X')
	{
		int kx=0;
		for(int j=y+1;j<=y+3;j++)
		{
			if(a[x-1][j]=='X')
			{
				kx=1;
			}	
		}	
		if(kx==0)
		{
			fun(x-1,y+3);
		}
	}
	if(x!=m && a[x][y+1]!='X' && a[x+1][y+1]!='X')
	{
		int kx=0;
		for(int j=y+1;j<=y+3;j++)
		{
			if(a[x+1][j]=='X')
			{
				kx=1;
			}
		}	
		if(kx==0)
		{
			fun(x+1,y+3);
		}
	}
}
int main()
{
	freopen("parkour.in","r","stdin");
	freopen("parkour.out","w","stdout");
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%s",a[i]+1);
			for(int j=1;j<=n;j++)
			{
				if(a[i][j]=='s')
				{
					sx=i;
					sy=j;
				}
			}
		}
		mark=0;
		fun(sx,sy);
		if(mark==1) printf("YES\n");
		else printf("NO\n");
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				a[i][j]=0;
			}
		}
	}
	return 0;
}
