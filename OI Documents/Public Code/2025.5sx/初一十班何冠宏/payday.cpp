#include<bits/stdc++.h>
using namespace std;
long long n, s, sum, l, r, ans;
struct node{
	long long l, r;
	int i; 
}f[200001];
bool cmp(node x, node y)
{
	if(x.l != y.l)
		return x.l < y.l;
	return x.r < y.r;
}
bool chk(long long mid)
{
	long long k = s;
	for(int i = n / 2 + 1; i <= n; i++)
	{
		k -= (mid - f[i].l);
		if(k < 0 || mid > f[i].r)
			return false;
		if(f[i].l >= mid)
			break;
	}
	if(k >= 0)
		return true;
}
int main()
{
	freopen("payday.in", "r", stdin);
	freopen("payday.out", "w", stdout);
	long long t;
	scanf("%lld", &t);
	while(t--)
	{
		sum = 0;
		scanf("%lld %lld", &n, &s);
		for(int i = 1; i <= n; i++)
		{
			scanf("%lld %lld", &f[i].l, &f[i].r);
			f[i].i = i;
			sum += f[i].l;
		}
		s -= sum;
		sort(f + 1, f + 1 + n, cmp);
		l = f[n / 2 + 1].l;
		r = f[n].r;
		ans = 0;
		while(l <= r)
		{
			long long mid = (l + r) >> 1;
			if(chk(mid))
			{
				ans = mid;
				l = mid + 1;
			}
			else
				r = mid - 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
