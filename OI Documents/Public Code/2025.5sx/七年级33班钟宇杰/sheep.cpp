#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int a[2005],bz[2005],n;
long long ans;
void dfs(int x)
{
	if(x>n) ans++;
	else
	{
		if(a[x]!=-1) dfs(x+1);
		for(int i=1;i<=n;i++)
		{
			if(!bz[i]&&i!=x)
			{
				bz[i]=1;
				dfs(x+1);
				bz[i]=0;
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
		if(a[i]!=-1) bz[a[i]]=1;
	}
	dfs(1);
	printf("%lld",ans%mod);
}
