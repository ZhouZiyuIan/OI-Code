#include<bits/stdc++.h>
using namespace std;
long long n,y,x[10010],p,ans;
map<long long,int>vis;
int main()
{
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	scanf("%d%lld",&n,&y);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			p=abs(x[i]-x[j]);
			if(!vis[p])
			{
				vis[p]=1;
				ans++;
			}
		}
	}
	printf("%lld",ans);
 } 
