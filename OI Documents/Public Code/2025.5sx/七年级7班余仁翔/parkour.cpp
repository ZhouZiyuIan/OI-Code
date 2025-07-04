#include<bits/stdc++.h>
using namespace std;
long long a,b,c,e,f,h,nx,ny,l[15][10005];
char d[15][10005];
int dy[4]{1,-1,0};
void dfs(int n,int m,int k)
{
	
	if(d[n][m+1+k]!='X')
	{
			ny=m+1;
	}

	if(h==1)
	{
		return;
	}
	if(m>=b)
	{
		h=1;
		return;
	}
	else
	{
		for(int i1=0;i1<=1;i1++)
		{
			nx=n+dy[i1];
			if(nx<=c&&nx>0&&d[nx][ny+k]!='X'&&l[nx][ny]==0)
			{
				l[nx][ny]=1;
				dfs(nx,ny,k+1);
				l[n+dy[i1]][m+1]=0;
			}
		}
		
	}
	if(d[n][m+1+k]!='X')
	{
		
		dfs(n,m+1,k+1);
	}
	
}
int main()

{
		freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
cin>>a;
for(int i=1;i<=a;i++)
{
	cin>>b>>c;
	for(int j=1;j<=c;j++)
	{
		for(int k=1;k<=b;k++)
		{
			cin>>d[j][k];
			
			if(d[j][k]=='s')
			{
				e=j;
				f=k;
			}
		}
		cout<<"\n";
	}
	dfs(e,f,1);
	if(h==1)
	{
		cout<<"Yes"<<"\n";
	}
	else
	{
		cout<<"No"<<"\n";
	}
	h=0;

}
	return 0;
}

