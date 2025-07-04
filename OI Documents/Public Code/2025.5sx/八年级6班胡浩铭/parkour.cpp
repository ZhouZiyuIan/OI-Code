#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e4+7;
const int MAXM=10+7;

int n,m,flag;
int dx[3]={1,0,-1};
char s[MAXM][MAXN];

struct node {
	int x,y,t;
};

void solve()
{
	flag=0;
	int sx,sy;
	for(int i=1;i<=n;i++)
		if(s[i][1]=='s')
			sx=i,sy=1;
	queue<node> q;
	q.push((node){sx,sy,0});
	while(!q.empty())
	{
		node d=q.front();
		q.pop();
		if(d.y+1+2*d.t<=m)
		{
			if(s[d.x][d.y+1+2*d.t]=='X')
				continue ;
			for(int i=0;i<3;i++)
			{
				int xx=d.x+dx[i];
				int yy=d.y+1;
				if(xx>=1 and xx<=n and yy>=1 and yy<=m and (yy+2*d.t>m or s[xx][yy+2*d.t]!='X'))
				{
					if(yy+2*(d.t+1)>m or s[xx][yy+2*(d.t+1)]!='X')
					{
						q.push((node){xx,yy,d.t+1});
						if(yy==m)
						{
							flag=1;
							return ;
						}
					}
				}
			}
		}
		else
		{
			for(int i=0;i<3;i++)
			{
				int xx=d.x+dx[i];
				int yy=d.y+1;
				if(xx>=1 and xx<=n and yy>=1 and yy<=m and (yy+2*d.t>m or s[xx][yy+2*d.t]!='X'))
				{
					if(yy+2*(d.t+1)>m or s[xx][yy+2*(d.t+1)]!='X')
					{
						q.push((node){xx,yy,d.t+1});
						if(yy==m)
						{
							flag=1;
							return ;
						}
					}
				}
			}
		}
	}
	return ;
}

int main()
{
//	freopen("D.in","r",stdin);
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&m,&n);
		for(int i=1;i<=n;i++)
			scanf("%s",s[i]+1);
//		return 0;
		solve();
		if(flag)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
