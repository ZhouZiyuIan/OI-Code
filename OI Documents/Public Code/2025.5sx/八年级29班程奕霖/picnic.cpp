#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+7;
int n,y,a[N],ans;
map<int,int> mp;
signed main()
{
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	cin>>n>>y;
	mp.clear();
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int v=abs(a[i]-a[j]);
			if(!mp[v]) ans++;
			mp[v]=1;
		}
	}
	cout<<ans<<'\n';
}
