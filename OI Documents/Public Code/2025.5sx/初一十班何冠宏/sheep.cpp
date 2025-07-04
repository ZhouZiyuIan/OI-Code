#include<bits/stdc++.h> 
#define mod 1000000007
using namespace std;
int n, a[2001], sum;
unsigned long long ans = 1;
bool vis[2001];
int main()
{
	freopen("sheep.in", "r", stdin);
	freopen("sheep.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if(a[i] == -1)
			sum++;
		else
			vis[a[i]] = 1;
	}
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == -1)
		{
			if(vis[i])
				ans = ans * sum % mod;
			else
			{
				if(sum == 2)
				{
					bool k = 0;
					for(int j = i + 1; j <= n; j++)
					{
						if(a[j] == -1)
						{
							if(!vis[i])
								k = 1;
							break;
						}
					}
					if(k)
					{
						cout << ans;
						exit(0);
					}
				}
				else
					ans = ans * (sum - 1) % mod;
			}
			sum--;
		}
	}
	cout << ans;
	return 0;
}
