#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e05 + 7;

#define int long long

int n, t;

int x[MAXN], sum[MAXN];

signed main()
{
	freopen("sleep.in", "r", stdin);
	freopen("sleep.out", "w", stdout);
	
	scanf("%lld%lld", &n, &t);
	
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &x[i]);
		sum[i] = sum[i - 1] + x[i];
	}
	
	if(sum[n] < t)
	{
		t = t % sum[n];
	}
	else if(sum[n] == t)
	{
		printf("%lld\n0", n);
		return 0;
	}
	
	int id = 0;
	
	for(int i = 1; i <= n; i++)
	{
		if(t > x[i])
		{
			t -= x[i];
			continue;
		}
		else if(t < x[i])
		{
			id = i;
			break;
		}
		else if(t == x[i])
		{
			id = i;
			break;
		}
	}
	
	printf("%lld\n%lld", id, x[id] - t);

	return 0;
}


