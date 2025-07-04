#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,t,a[N];
long long tmp,s,cnt; 
int main()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	scanf("%lld%lld", &n, &t);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld", &tmp);
		a[i]=a[i-1]+tmp;
	}
	s=t/a[n];
	t-=s*a[n];
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=t)
		{
			printf("%lld\n%lld", i, a[i]-t);
			return 0;
		}
	}
	return 0;	
} 
