#include <bits/stdc++.h>
using namespace std;
const int M=1001;
int n,m,cnt;
long long a[M];
long long ans;
long long b[M*M];
signed main()
{
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			b[++cnt]=abs(a[i]-a[j]);
		}
	}
	sort(b+1,b+1+cnt);
	for(int i=1;i<=cnt;i++) if(i==1||b[i]!=b[i-1]) ans++;
	printf("%lld",ans);
	return 0;
}
