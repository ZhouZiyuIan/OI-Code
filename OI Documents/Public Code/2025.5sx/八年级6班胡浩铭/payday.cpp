#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=2e5+7;

int n,s;
struct node {
	int l,r;
} p[MAXN];

bool cmp()

signed main()
{
	freopen("payday.in","r",stdin);
	freopen("payday.out","w",stdout);
	int T;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld %lld",&n,&s);
		for(int i=1;i<=n;i++)
			scanf("%lld %lld",&p[i].l,&p[i].r);
		sort(p+1,p+n+1,cmp);
	}
	return 0;
}

