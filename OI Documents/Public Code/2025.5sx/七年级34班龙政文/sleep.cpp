#include<bits/stdc++.h>
using namespace std;
long long n,t,a[100005],sum,ans;
int main()
{
	freopen("sleep.in","r","stdin");
	freopen("sleep.out","w","stdout");
	scanf("%lld%lld",&n,&t);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	t=t%sum;
	for(int i=1;i<=n;i++)
	{
		if(t>a[i])
		{
			t-=a[i];
		}
		else
		{
			ans=a[i]-t;
			printf("%d\n%lld",i,ans);
			return 0;
		}
	}
	return 0;
}
