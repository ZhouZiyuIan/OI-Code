#include <bits/stdc++.h>
using namespace std;
int n;
int x[100005];
long long t, sum;
int main()
{
	freopen("sleep.in", "r", stdin);
	freopen("sleep.out", "w", stdout);
	scanf("%d%lld", &n, &t);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &x[i]);
		sum += x[i];
	}
	t %= sum;
	if(!t)
	{
		printf("%d\n0", n);
		return 0;
	}
	long long now = 0;
	for(int i = 1; i <= n; ++i)
	{
		now += x[i];
		if(now >= t)
		{
			printf("%d\n%lld", i, now - t);
			return 0;
		}
	}
	return 0;
}
