#include<bits/stdc++.h>
using namespace std;
struct id{
	struct safe{
		int l,r;
	}a[10001];
	int cnt=0;
}mp[11];
int n,m,sx,sy;
char mpz[21][20001];
int h=1,t=1,q[100001][3];
int pd(int r,int c,int tm)
{
	for(int i=1;i<=mp[r].cnt;i++)
	{
		int nwl=mp[r].a[i].l-tm*2,nwr=mp[r].a[i].r-tm*2;
//		cout<<nwl<<" "<<nwr<<" "<<tm<<endl;
		if(c>=nwl&&c<=nwr)
		{
			return 0;
		}
	}
	return 1;
}
void fun()
{
	int h=1,t=1;
	memset(mp,0,sizeof(mp));
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",mpz[i]+1);
//		cout<<i<<endl;
		for(int j=1;j<=m;j++)
		{
			if(mpz[i][j]=='X'&&(mpz[i][j-1]!='X'||j==1))
			{
				mp[i].a[++mp[i].cnt].l=j;
//				cout<<"L:"<<mp[i].cnt<<" "<<j<<endl;
			}
			if(mpz[i][j]=='X'&&(mpz[i][j+1]!='X'||j==m))
			{
				mp[i].a[mp[i].cnt].r=j;
//				cout<<"R:"<<mp[i].cnt<<" "<<j<<endl;
			}
			if(mpz[i][j]=='s')
			{
				sx=i;
				sy=j;
			}
		}
	}
//	cout<<pd(2,3,1)<<endl;
	q[1][1]=sx;
	q[1][2]=sy;
	while(h<=t)
	{
		for(int i=0;i<3;i++)
		{
			if(!i)
			{
				int xx=q[h][1];
				int yy=q[h][2]+1;
//				cout<<3<<" "<<xx<<" "<<yy<<" "<<q[h][3]<<endl;
				if(yy<=m&&pd(xx,yy,q[h][3]+1)&&pd(q[h][1],yy,q[h][3]))
				{
//					cout<<1<<" "<<q[h][1]<<" "<<q[h][2]<<"->"<<xx<<" "<<yy<<" "<<q[h][3]<<endl;
					q[++t][1]=xx;
					q[t][2]=yy;
					q[t][3]=q[h][3]+1;
					if(yy==m)
					{
						cout<<"YES"<<endl;
						return ;
					}
				}
			}
			else if(i==1)
			{
				int xx=q[h][1]-1;
				int yy=q[h][2]+1;
//				cout<<2<<" "<<xx<<" "<<yy<<" "<<q[h][3]<<endl;
				if(xx>0&&xx<=n&&yy<=m&&pd(xx,yy,q[h][3]+1)&&pd(q[h][1],yy,q[h][3]))
				{
//					cout<<2<<" "<<q[h][1]<<" "<<q[h][2]<<"->"<<xx<<" "<<yy<<" "<<q[h][3]<<endl;
					q[++t][1]=xx;
					q[t][2]=yy;
					q[t][3]=q[h][3]+1;
					if(yy==m)
					{
						cout<<"YES"<<endl;
						return ;
					}
				}
			}
			else
			{
				int xx=q[h][1]+1;
				int yy=q[h][2]+1;
//				cout<<1<<" "<<xx<<" "<<yy<<" "<<q[h][3]<<endl;
				if(xx>0&&xx<=n&&yy<=m&&pd(xx,yy,q[h][3]+1)&&pd(q[h][1],yy,q[h][3]))
				{
//					cout<<3<<" "<<q[h][1]<<" "<<q[h][2]<<"->"<<xx<<" "<<yy<<" "<<q[h][3]<<endl;
					q[++t][1]=xx;
					q[t][2]=yy;
					q[t][3]=q[h][3]+1;
					if(yy==m)
					{
						cout<<"YES"<<endl;
						return ;
					}
				}
			}
		}
		h++;
	}
	cout<<"NO";
}
int main()
{
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		fun();
	}
}
