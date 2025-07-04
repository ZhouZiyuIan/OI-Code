#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,t;
const int N=1e5+7;
ll sum=0;
ll a[N];
int main()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	scanf("%lld%lld",&n,&t);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	t=t%sum;
	ll res=0;
	for(int i=1;i<=n;i++)
	{
		res+=a[i];
		if(res>=t)
		{
			cout<<i<<endl<<res-t;
			return 0;
		}
	}
	return 0;
}
