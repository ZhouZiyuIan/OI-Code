#include<cstdio>
#include<cmath>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=1e6+1e3;
int n,y,x[maxn],s[maxn],cnt,ans;
signed main()
{
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	scanf("%lld%lld",&n,&y);
	for(int i=1;i<=n;i++)
		scanf("%lld",&x[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			s[++cnt]=abs(x[i]-x[j]);
	sort(s+1,s+cnt+1);
	for(int i=1;i<=cnt;i++)
		if(s[i]!=s[i-1])ans++;
	printf("%lld",ans);
	return 0;
}
