#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e3 + 10;

int n, y;

int a[N];

int p[N * N], cur;

signed main()
{
	freopen("picnic.in", "r", stdin);
	freopen("picnic.out", "w", stdout);
	
	cin.tie(0) -> sync_with_stdio(0);
	
	cin >> n >> y;
	
	for (int i=1; i<=n; i++)
		cin >> a[i];
	
	sort (a+1, a+n+1);
	
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<i; j++)
		{
			p[++cur] = a[i] - a[j];
		}
	}
	
	sort (p+1, p+cur+1);
	
	int res = 0;
	
	for (int i=1; i<=cur; i++)
	{
		if (p[i] == p[i-1])
			continue;
		
		++res;
	}
	
	cout << res << '\n';
	
	return 0;
}
