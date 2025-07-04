#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int n, ans;
int a[2005];
bool flag[2005];
void dfs(int x)
{
	if(x > n)
	{
		++ans;
		return;
	}
	if(a[x] != -1)
	{
		dfs(x + 1);
		return;
	}
	for(int i = 1; i <= n; ++i)
	{
		if(!flag[i] && i != x)
		{
			flag[i] = true;
			dfs(x + 1);
			flag[i] = false;
		}
	}
}
signed main()
{
	freopen("sheep.in", "r", stdin);
	freopen("sheep.out", "w", stdout);
	scanf("%lld", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%lld", &a[i]);
		if(a[i] != -1) flag[a[i]] = true;
	}
	dfs(1);
	printf("%lld", ans % mod);
	return 0;
}
