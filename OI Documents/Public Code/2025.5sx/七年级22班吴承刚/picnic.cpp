#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll y,x[2005],ans=0;
map<ll,bool> vis;
signed main()
{
	//freopen("picnic.in","r",stdin);
	//freopen("picnic.out","w",stdout);
	scanf("%d%lld",&n,&y);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x[i]);
	}
	sort(x+1,x+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(vis[x[j]-x[i]]==false)
			{
				ans++;
				vis[x[j]-x[i]]=true;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
