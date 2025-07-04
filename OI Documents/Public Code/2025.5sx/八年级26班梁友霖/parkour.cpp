#include<bits/stdc++.h>
using namespace std;
int T;
const int N=1e4+7,M=10+7;
char a[M][N];
int q[N*M][3];
int dx[3]={1,-1,0},dy[3]={0,0,0};
int bz[M][N];
int main()
{
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(bz,0,sizeof(bz));
		int n,m;
		scanf("%d%d",&m,&n);
		int stx,sty;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
				if(a[i][j]=='s')
				{
					stx=i;
					sty=j;
				}
				if(a[i][j]=='X')
				bz[i][j]=1;
			}
		}
//		cout<<stx<<" "<<sty<<endl;
		int h=0,t=1;
		q[1][0]=stx;
		q[1][1]=sty;
		q[1][2]=0;
		int ok=0;
		while(h<t)
		{
			h++;
			int x=q[h][0],y=q[h][1];
			y++;
			if(2*q[h][2]+y<=m)
			{
				if(bz[x][y+2*q[h][2]])
				continue;
			}	
		//	cout<<x<<' '<<y<<endl;
			for(int i=0;i<3;i++)
			{
				int xx=x+dx[i];
				int yy=y+dy[i];
		//		cout<<xx<<' '<<yy<<endl;
			
				if(xx>=1&&xx<=n&&yy>=1&&yy<=m)
				{
				
					int tim=q[h][2]+1;
				
					if(2*tim+yy<=m)
					{
						if(bz[xx][yy+2*tim])
						continue;
					}
					tim--;
					if(2*tim+yy<=m)
					{
						if(bz[xx][yy+2*tim])
						continue;
					}	
					if(yy==m)
					{
					ok=1;
					puts("YES");
					break;
					}
				//	cout<<xx<<' '<<yy<<" "<<q[h][2]+1<<endl;
					q[++t][0]=xx;
					q[t][1]=yy;
					q[t][2]=q[h][2]+1;
					
				
				}
				
			}
			if(ok==1)
			break;
		}
		if(ok==0)
		puts("NO");
	}
	return 0;
}
