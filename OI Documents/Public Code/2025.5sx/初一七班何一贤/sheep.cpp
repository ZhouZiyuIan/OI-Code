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
const int N=200005,mod=1000000007;
int n,vis[N],a[N],p[N],cnt,ans=0;
inline void dfs(int x)
{
	if(x>n)
	{
		++ans;return;
	}
	if(a[x]==-1)
	{
		for(int i=1;i<=n;i++)
		{
			if(!vis[i]&&i!=x)
			{
				vis[i]=1;p[x]=i;
				dfs(x+1);
				vis[i]=0;
			}
		}
	}
	else dfs(x+1);
}
signed main()
{
		freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	n=rd;
	for(int i=1;i<=n;i++)
	{
		a[i]=rd;
		if(a[i]!=-1)
		{
			vis[a[i]]=1;
		}
	}
	dfs(1);cout<<ans<<'\n';
	return 0;
}
