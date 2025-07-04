#include<bits/stdc++.h>
using namespace std;
int a[15][10005],ok[15][10005],p[15][10005],n,m,k[15][10005];
int dfs(int x,int y)
{
	if(y==n) return 1;
	if(p[x][y]!=-1) return p[x][y];
	p[x][y]=0;
	if(!ok[x][y+1]) p[x][y]|=dfs(x,y+1);
	if(x-1>=1&&!ok[x-1][y+1]&&!k[x][y+1]) p[x][y]|=dfs(x-1,y+1);
	if(x+1<=m&&!ok[x+1][y+1]&&!k[x][y+1]) p[x][y]|=dfs(x+1,y+1);
	return p[x][y];
}
void solve()
{
	scanf("%d%d",&n,&m);
	memset(a,0,sizeof(a));
	memset(ok,0,sizeof(ok));
	memset(p,-1,sizeof(p));
	memset(k,0,sizeof(k));
	int h=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			char u;
			cin>>u;
			if(u=='X') a[i][j]=1;
			if(u=='s') h=i;
		}
	}
	for(int i=1;i<=m;i++)
	{
//		printf("0");
		for(int j=2;j<=n;j++)
		{
			if(0<=j+2*(j-1)&&j+2*(j-1)<=n) ok[i][j]|=a[i][j+2*(j-1)];
			if(0<=j+2*(j-1)-1&&j+2*(j-1)-1<=n) ok[i][j]|=a[i][j+2*(j-1)-1];
			if(0<=j+2*(j-1)-2&&j+2*(j-1)-2<=n) ok[i][j]|=a[i][j+2*(j-1)-2];
			if(j+2*(j-2)<=n) k[i][j]=a[i][j+2*(j-2)];
//			printf("%d",ok[i][j]);
		}
//		printf("\n");
	}
	if(dfs(h,1)) printf("YES\n");
	else printf("NO\n");
}
int main()
{
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--) solve();
}
