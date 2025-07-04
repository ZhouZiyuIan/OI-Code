#include<bits/stdc++.h>
using namespace std;
long long a,b,c[100011],d=0,e,f=0,g;
int main()
{#include<bits/stdc++.h>
using namespace std;
long long a,b,c[100011],d=0,e,f=0,g;
int main()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	scanf("%lld%lld",&a,&b);
	for(long long i=1;i<=a;i++)
	{
		scanf("%lld",&c[i]);
		d=d+c[i];
	}
	e=b/d;
	g=e*d;
	d=b-g;
	for(long long i=1;i<=a;i++)
	{
		f=f+c[i];
		if(f>=d)
		{
			printf("%lld\n%lld",i,f-d);
			break;
		}
	}
	return 0;
}
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	scanf("%lld%lld",&a,&b);
	for(long long i=1;i<=a;i++)
	{
		scanf("%lld",&c[i]);
		d=d+c[i];
	}
	e=b/d;
	g=e*d;
	d=b-g;
	for(long long i=1;i<=a;i++)
	{
		f=f+c[i];
		if(f>=d)
		{
			printf("%lld\n%lld",i,f-d);
			break;
		}
	}
	return 0;
}
