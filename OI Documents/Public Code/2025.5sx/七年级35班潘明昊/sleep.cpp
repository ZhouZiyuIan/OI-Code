#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
long long t,sum;
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
	int i=1;
	while(t&&i<=n)
	{
		if(t>a[i])
		{
			t-=a[i];
		}else if(t==a[i])
		{
			printf("%d %d",i,0);
			t=0;
			return 0;
		}else {
			printf("%d %d",i,a[i]-t);
			t=0;
			return 0;
		}
		i++;
	}
	return 0;
}

