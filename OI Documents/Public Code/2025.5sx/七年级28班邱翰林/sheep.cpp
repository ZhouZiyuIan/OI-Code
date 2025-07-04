#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e3 + 10;
const int MOD = 1e9 + 7;

int n, m;

int a[N], b[N];

int vis[N];

int f[N];

int res;

void dfs(int x)
{
	if (x == n+1)
	{
		for (int i=1; i<=n; i++)
		{
			if (a[i] > 0)
			{
				if (a[i] != b[i])
					return;
			}
		}
		
		for (int i=1; i<=n; i++)
			if (b[i] == i) return;
		
		return ++res, void();
	}
	
	for (int i=1; i<=n; i++)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			
			b[x] = i;
			
			dfs(x + 1);
			
			vis[i] = 0;
		}
	}
}

int solve(int n)
{
	f[0] = 1;
	
	f[1] = 0;
	
	for (int i=2; i<=n; i++)
	{
		f[i] = (f[i-1] + f[i-2]) * (i-1) % MOD;
	}
	
	return f[n];
}

signed main()
{
	freopen("sheep.in", "r", stdin);
	freopen("sheep.out", "w", stdout);
	
	cin.tie(0) -> sync_with_stdio(0);
	
	cin >> n;
	
	int m = 0;
	
	for (int i=1; i<=n; i++)
		cin >> a[i], m += (a[i] == -1);
	
	if (n <= 10)
	{
		dfs(1);
		
		cout << res << '\n';
		
		return 0;
	}
	
	cout << solve(m) << '\n';
	
	return 0;
}
