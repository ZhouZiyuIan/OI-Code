#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n,a[1005],s,vis[1005],t,tmp[1005],v[1005],ans=0;
void dfs(int x)
{
	if(a[x]!=-1)
	{
		dfs(x+1);
		return;
	}
	if(x>n)
	{
		ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0&&x!=i)
		{
			if(v[i]==0)
			{
				v[i]=1;
				dfs(x+1);
				v[i]=0;
			}
		}
	}
}
int main()
{
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]!=-1) vis[a[i]]=1;
	}
	dfs(1);
	printf("%d",ans%mod);
	return 0;
}
