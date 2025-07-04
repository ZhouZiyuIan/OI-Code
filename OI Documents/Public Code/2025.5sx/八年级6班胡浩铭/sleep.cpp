#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e5+7;

int a[MAXN],n,m,sum;

signed main()
{
	freopen("sleep.in","r",stdin);
	freoepn("sleep.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	m%=sum;
	if(!m)
	{
		printf("%lld\n0",n);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=m)
		{
			printf("%lld\n",i);
			printf("%lld",a[i]-m);
			return 0;
		}
		else
			m-=a[i];
	}
	return 0;
}
