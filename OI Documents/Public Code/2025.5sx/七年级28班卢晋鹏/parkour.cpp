#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5;
int t,n,h,l;
bool v[15][N],w;
char a[15][N];
void dfs(int x,int y)
{
	
	if(w||v[x][y]) return;
	//printf("%d %d\n",x,y);
	if(y==l)
	{
		w=1;
		return;
	}
	v[x][y]=1;
	if(y<l-1)
	{
		if(x>1 && v[x-1][y]!=1 && v[x-1][y+1]!=1) dfs(x-1,y+2);
		if(x<h && v[x+1][y]!=1 && v[x+1][y+1]!=1) dfs(x+1,y+2);
		if(v[x][y+1]!=1)dfs(x,y+2);
	}
	else
	{
		if(x>1 && v[x-1][y]!=1) dfs(x-1,y+1);
		if(x<h && v[x+1][y]!=1) dfs(x+1,y+1);
		if(v[x][y+1]!=1)dfs(x,y+1);
	}
	
}
void start()
{
	memset(v,0,sizeof v);
	w=0;
	int x;
	scanf("%d%d",&l,&h);
	for(int i=1;i<=h;i++)
	  scanf("%s",a[i]+1);
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=l;j++)
		{
			if(a[i][j]=='s')  x=i;
			if(a[i][j]=='X')  v[i][j]=1;
		}
	}
	dfs(x,1);
	if(w) printf("YES\n");
	else printf("NO\n");
}
int main()
{
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		start();
	}
	//printf("  %d",v[2][5]);
	return 0;
}

