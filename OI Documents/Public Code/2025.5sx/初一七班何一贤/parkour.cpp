#include<bits/stdc++.h>
#define int long long
#define rd read()
#define gc getchar()
using namespace std;
inline int read()
{
	int x=0,ss=1,ch=gc;
	while((ch<'0'||ch>'9')&&ch!='-')ch=gc;
	if(ch=='-')ss=-1,ch=gc;
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=gc;
	return x*ss;
}
const int N=300005,D=26;
int T,n,m,sx,sy,dp[15][N];
char s[15][N];
int K[3]={0,-1,1};
inline void solve()
{
	n=rd,m=rd;
	memset(dp,0,sizeof(dp)),memset(s,0,sizeof(s));
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)cin>>s[i][j];
	for(int i=1;i<=m;i++)
		if(s[i][1]=='s')sx=i;
//	cout<<sx<<'\n';
	dp[sx][1]=1;int tim=0;
	for(int i=1;i<n;tim++,i++)
		for(int j=1;j<=m;j++)
		{
			if(dp[j][i])
			{
			//	if(i==1)cout<<j<<' '<<i<<'\n';
				for(int k=0,x,y;k<3;k++)
				{
					x=j+K[k],y=i+1;
					if(
					x>=1&&x<=m
					&&s[j][i+2*tim]!='X'
					&&s[j][y+2*tim]!='X'
					&&s[x][y+2*tim]!='X'
					&&s[x][y+1+2*tim]!='X'
					&&s[x][y+2+2*tim]!='X'
					)
					{
						dp[x][y]=1;
					}
				}
			}
	}
	for(int i=1;i<=m;i++)if(dp[i][n]){cout<<"YES\n";return;}
	cout<<"NO\n";
}
signed main()
{
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	T=rd;while(T--)solve();
	return 0;
}
