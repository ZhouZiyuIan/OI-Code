#include <bits/stdc++.h>
using namespace std;
int n;
long long s;
int l[200005], r[200005], a[200005];
bool cmp(const int &x, const int &y)
{
	return x > y;
}
bool check(int v)
{
	int cnt = 0;
	long long sum = 0;
	for(int i = 1; i <= n; ++i)
	{
		if(r[i] < v)
		{
			sum += l[i];
			continue;
		}
		a[++cnt] = l[i];
	}
	if(cnt <= n / 2) return false;
	sort(a+1, a+cnt+1, cmp);
	for(int i = 1; i <= n / 2 + 1; ++i) sum += max(a[i], v);
	for(int i = n / 2 + 2; i <= cnt; ++i) sum += a[i];
	return (sum <= s);
}
void solve()
{
	int R = 0, ans = 0;
	scanf("%d%lld", &n, &s);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d%d", &l[i], &r[i]);
		R = max(R, r[i]);
	}
	int L = 1;
	while(L <= R)
	{
		int mid = (L + R) >> 1;
		if(check(mid)) L = mid + 1, ans = mid;
		else R = mid - 1;
	}
	printf("%d\n", ans);
}
int main()
{
	freopen("payday.in", "r", stdin);
	freopen("payday.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}
