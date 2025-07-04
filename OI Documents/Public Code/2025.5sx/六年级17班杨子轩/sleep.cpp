#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;
ull sum,t;
int n,a[1000005];
int main()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	scanf("%d%lld",&n,&t);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	t=t%sum;
	for(int i=1;i<=n;i++)
	{
		if(t<=a[i])
		{
			printf("%d\n%lld",i,a[i]-t);
			return 0;
		}else
		{
			t-=a[i];
		}
	}
}

