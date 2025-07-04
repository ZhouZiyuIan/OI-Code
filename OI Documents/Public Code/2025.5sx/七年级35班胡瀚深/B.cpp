#include <bits/stdc++.h>
using namespace std;
int n, y;
set<long long> S;
long long x[1005];
int main()
{
	freopen("picnic.in", "r", stdin);
	freopen("picnic.out", "w", stdout);
	scanf("%d%d", &n, &y);
	for(int i = 1; i <= n; ++i) scanf("%lld", &x[i]);
	sort(x+1, x+n+1);
	for(int i = 1; i <= n; ++i)
	{
		for(int j = i + 1; j <= n; ++j)
		{
			S.insert(x[j] - x[i]);
		}
	}
	printf("%d\n", S.size());
	return 0;
}
