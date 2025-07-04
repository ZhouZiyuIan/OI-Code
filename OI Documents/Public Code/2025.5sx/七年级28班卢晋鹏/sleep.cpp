#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int n,a[N];
ll s,sum,t;
int main()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	scanf("%d%lld",&n,&s);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		t+=a[i];
	}
	s%=t;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		if(s<=sum)
		{
			printf("%d\n%lld",i,sum-s);
			break;
		}
	}
	return 0;
}

