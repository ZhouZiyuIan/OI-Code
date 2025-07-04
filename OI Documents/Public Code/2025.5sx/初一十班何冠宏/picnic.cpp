#include<bits/stdc++.h>
using namespace std;
long long n, y, x[101], ma, mi, sum;
double s;
map<double, bool> p; 
int main()
{ 
	freopen("picnic.in", "r", stdin);
	freopen("picnic.out", "w", stdout);
	scanf("%lld %lld", &n, &y);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &x[i]);
	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			ma = max(x[i], x[j]);
			mi = min(x[i], x[j]);
			s = (ma - mi) * y * 1.0 / 2;
			if(!p[s])
			{
				p[s] = 1;
				sum++;
			}
		}
	}
	printf("%lld", sum);
	return 0;
}
