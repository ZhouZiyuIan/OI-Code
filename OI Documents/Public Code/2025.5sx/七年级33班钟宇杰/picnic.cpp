#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1005];
map<int,int> mp;
signed main()
{
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	int n,y;
	scanf("%lld%lld",&n,&y);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		for(int j=1;j<i;j++)
		{
			if(!mp[abs(a[i]-a[j])])
			{
				mp[abs(a[i]-a[j])]=1,ans++;
			}
		}
	}
	printf("%lld",ans);
}
