#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 10;

int n, t;

int a[N], sum[N];

int res;

signed main()
{
	freopen("sleep.in", "r", stdin);
	freopen("sleep.out", "w", stdout);
	
	cin.tie(0) -> sync_with_stdio(0);
	
	cin >> n >> t;
	
	for (int i=1; i<=n; i++)
		cin >> a[i], sum[i] = sum[i-1] + a[i];
	
	t %= sum[n];
	
	for (int i=n; i; i--)
	{
		if (t < sum[i-1])
			continue;
		
		if (t == sum[i-1])
			res = 0;
		else
			res = a[i] - t + sum[i-1];
		
		if (res == 0)
			cout << (i == 1 ? n : i-1) << '\n';
		else
			cout << i << '\n';
		
		break;
	}
	
	cout << res << '\n';
	
	return 0;
}
