#include<bits/stdc++.h>
using namespace std;
int main()
{ 
	freopen("sleep.in", "r", stdin);
	freopen("sleep.out", "w", stdout);
	long long n, a[10010];
	unsigned long long t, sum = 0;
	scanf("%lld", &n);
	cin >> t;
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		sum += a[i];
	}
	t %= sum;
	for(int i = 1; i <= n; i++)
	{
		if(t <= a[i])
		{
			cout << i << endl << a[i] - t;
			exit(0);
	}	
		t -= a[i];
	}
	return 0;
} 
