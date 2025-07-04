#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,y,x[10000005],ans;
map<ll,ll> vis;
int main()
{
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	cin>>n>>y;
	for(int i = 1;i <= n;i++)
	{
		cin>>x[i];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i+1;j <= n;j++)
		{
			if(!vis[x[j] - x[i]] && x[j] - x[i] != 0)
			{
				vis[x[j] - x[i]] = 1;
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
