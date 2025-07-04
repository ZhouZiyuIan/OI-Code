#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e3+7;

int n,a[MAXN],ans;
map<int,int> mp;

signed main()
{
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	int in;
	scanf("%lld %lld",&n,&in);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int tmp=abs(a[j]-a[i]);
			if(mp[tmp])
				continue ;
			mp[tmp]=1;
			++ans;
		}
	}
	printf("%lld",ans);
	return 0;
}

