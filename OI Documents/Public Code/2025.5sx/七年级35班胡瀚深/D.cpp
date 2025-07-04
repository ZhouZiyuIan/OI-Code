#include <bits/stdc++.h>
using namespace std;
char a[10005][15];
bool can[10005][15];
void solve()
{
	memset(can, false, sizeof(can));
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			cin >> a[j][i];
			if(a[j][i] == 's') can[j][i] = true;
		}
	}
	for(int i = 2; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			if((i - 2) * 2 + i <= n && a[(i - 2) * 2 + i][j] == 'X') continue;
			if((i - 1) * 2 + i <= n && a[(i - 1) * 2 + i][j] == 'X') continue;
			if((i - 1) * 2 + i - 1 <= n && a[(i - 1) * 2 + i - 1][j] == 'X') continue;
			if(can[i - 1][j - 1])
			{
				if((i - 2) * 2 + i <= n && a[(i - 2) * 2 + i][j - 1] == 'X');
				else can[i][j] = true;
			}
			if(can[i - 1][j])
			{
				if((i - 2) * 2 + i <= n && a[(i - 2) * 2 + i][j] == 'X');
				else can[i][j] = true;
			}
			if(can[i - 1][j + 1])
			{
				if((i - 2) * 2 + i <= n && a[(i - 2) * 2 + i][j + 1] == 'X');
				else can[i][j] = true;
			}
			if(i == n)
			{
				if(can[i][j])
				{
					puts("YES");
					return;
				}
			}
		}
	}
	puts("NO");
}
int main()
{
	freopen("parkour.in", "r", stdin);
	freopen("parkour.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}
