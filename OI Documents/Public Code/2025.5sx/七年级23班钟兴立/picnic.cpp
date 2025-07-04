#include<bits/stdc++.h>
using namespace std;
long long n,y,ans,vis[1005],x[1005];
int main()
{
	freopen("picnic.in","w",stdin);
	freopen("picnic.out","r",stdout);
	scanf("%lld%lld",&n,&y);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x[i]);
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(vis[abs(x[i]-x[j])]==0)
			{
				ans++;
				vis[abs(x[i]-x[j])]=1;
			}
		}
	}
	printf("%lld",ans);
}
