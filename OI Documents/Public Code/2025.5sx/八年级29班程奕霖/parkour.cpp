#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+7;
int n,m;
int s[11][20001];
int f[20001][11];
inline void solve()
{
	memset(f,0,sizeof(f));
	memset(s,0,sizeof(s));
	cin>>n>>m;swap(n,m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char t;
			cin>>t;
			if(t=='s')
			{
				f[j][i]=1;
			}
			else if(t=='X')
			{
				s[i][j]=1;
			}
		}
	}
	for(int i=2;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int id=i+2*(i-1);
			int lst=i-1+2*(i-2);
			if(s[j][id]==1||s[j][lst+1]==1) continue;
			if(f[i-1][j+1]&&s[j+1][lst+1]==0)
			{
				f[i][j]=1;
			}
			if(f[i-1][j]&&s[j][lst+1]==0)
			{
				f[i][j]=1;
			}
			if(f[i-1][j-1]&&s[j-1][lst+1]==0)
			{
				f[i][j]=1;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=f[m][i];
	}
	puts(ans==0?"NO":"YES");
}
signed main()
{
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	int T;
	cin>>T;
	while(T--) solve();
}
