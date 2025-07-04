#include <bits/stdc++.h>
using namespace std;
#define int long long
#define For(i,x,y) for(int i=x;i<=y;i++)
const int M=100101;
const int inf=1e9+7;
int n,m;
int a[M];
int sum;
signed main()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	For(i,1,n) scanf("%lld",&a[i]);
	For(i,1,n)
	{ 
		sum+=a[i];
		if(sum>=m)
		{
			printf("%lld\n%lld",i,sum-m);
			return 0;
		}
	}
	printf("%lld\n0",n);
	return 0;
}
