#include<bits/stdc++.h>
using namespace std;
const int N=13,M=1e4+5;
int T,n,m,st,d[N*M][4],hd,tl,ans;
int way[3][2]={{-1,0},{0,0},{1,0}};
bool bz[N][M];
char ch[N][M];
int main()
{
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		swap(n,m);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",ch[i]+1);
			for(int j=1;j<=m;j++)
				bz[i][j]=0;
		}
		for(int i=1;i<=n;i++)
		{
			if(ch[i][1]=='s')
			{
				st=i;
			}
		}
		ans=0;
		hd=0,tl=1;
		d[1][0]=st;
		d[1][1]=1;
		bz[st][1]=1;
		while(hd<tl)
		{
			hd++;
			int x=d[hd][0],y=d[hd][1];
//			if(T==7)
//			{
//				printf("%d %d\n",x,y);
//			}
//			printf("%d %d\n",x,y);
			if(ch[x][y+1]=='X')
				continue;
			y++;
			for(int i=0;i<3;i++)
			{
				int xx=x+way[i][0];
				if(ch[xx][y]=='X') continue;
				if(xx<1||xx>n) continue;
				int sf=0;
				for(int j=y+1;j<=y+2;j++)
				{
					if(j>m)
					{
						sf=2;
						break;
					}
					if(ch[xx][j]=='X')
					{
						sf=1;
						break;
					}
					if(j>=m)
					{
						sf=2;
						break;
					}
				}
				if(sf==2)
				{
					ans=1;
					break;
				}
//				if(y>=140)
//				{
//					printf(" %d %d %d %d %d %d\n",x,y,xx,y+2,sf,bz[xx][y+2]);
//				}
				if(sf!=1)
				{
					if(bz[xx][y+2]==0)
					{
						d[++tl][0]=xx;
						d[tl][1]=y+2;
						bz[xx][y+2]=1;
					}
				}
			}
			if(ans==1) break;
		}
		if(ans) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
