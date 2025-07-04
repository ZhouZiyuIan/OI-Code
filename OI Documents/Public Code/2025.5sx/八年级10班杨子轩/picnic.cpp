#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e03 + 7, N = 1e06 * 5 + 7;

#define int long long

int n, y;

int a[MAXN];

int all[N], cnt;

signed main()
{
	freopen("picnic.in", "r", stdin);
	freopen("picnic.out", "w", stdout);
	
	cin >> n >> y;
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];
		
	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			int h = abs(a[i] - a[j]);
			if(h == 0 or y == 0)
				continue;
			all[++cnt] = h;
		}
	}
	
	sort(all + 1, all + cnt + 1);
	
	int m = unique(all + 1, all + cnt + 1) - all - 1;
	
	printf("%lld", m);

	return 0;
}


