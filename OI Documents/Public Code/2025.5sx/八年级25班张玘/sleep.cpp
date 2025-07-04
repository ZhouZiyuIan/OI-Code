#include<cstdio>
#define int long long
using namespace std;
const int maxn=1e6;
int n,a[maxn],t,s;
signed main()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	scanf("%lld%lld",&n,&t);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		s+=a[i];
	}
	t%=s;
	for(int i=1;i<=n;i++)
	{
		if(t<=a[i])
		{
			printf("%lld\n%lld",i,a[i]-t);
			break;
		}
		t-=a[i];
	}
	return 0;
}
