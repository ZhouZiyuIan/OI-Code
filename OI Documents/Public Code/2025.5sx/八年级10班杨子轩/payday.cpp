#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e05 * 2 + 7;

int T;

#define int long long

int n, s;

struct Line {
	int l, r;
} a[MAXN];

bool cmp(Line a, Line b)
{
	return a.r == b.r ? a.l < b.l : a.r < b.r;
}

bool check(int midl)
{
	int l = m;
	for(int i = 1; i <= n; i++)
	{
		if(a[i].r >= mid)
		{
			if(a[i].l < mid and l - (mid - a[i].l) >= 0)
			else
			
		}
	}
}

signed main()
{
	scanf("%d", &T);
	
	while(T--)
	{
		scanf("%lld%lld", &n, &s);
		for(int i = 1; i <= n; i++)
			scanf("%lld%lld", &a[i].l, &a[i].r);
		sort(a + 1, a + n + 1, cmp);
		int l = 1, r = 1000000000, ans;
		while(l <= r)
		{
			int mid = (l + r) >> 1ll;
			if(check(mid))
			{
				l = mid + 1;
				ans = mid;
			}
			else
			{
				r = mid - 1;
			}
		}
		printf("%lld\n", ans);
	}

	return 0;
}


