#include<bits/stdc++.h>
using namespace std;
int n,m,ans,Q;char c[105][100005];
struct stu
{
	int x,y;
}q[10000005];
int main()
{
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	cin>>Q;
	while(Q)
	{
		Q--;
		int h=1,t=1;bool p=false;
		cin>>n>>m;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>c[i][j];
				if(c[i][j]=='s')
				{
					q[h].x=i;q[h].y=0;
				}
			}
		}
		while(h<=t)
		{
			for(int i=-1;i<=1;i++)
			{
				int xx=i+q[h].x;
				if(xx>=0 and xx<m and c[xx][q[h].y+3]!='X' and c[xx][q[h].y]!='X')
				{
					t++;
					q[t].x=xx;
					q[t].y=q[h].y+3;
					if(q[t].y>n)
					{
						p=true;break;
					}
				}
			}
			if(p)break;
			h++;
		}
		if(p)cout<<"YES\n";
		else cout<<"NO\n";
	}
}

