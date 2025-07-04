#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+10;
int n,y,x[N],l[N],vis[N],ans;
char s;
signed main()
{
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	cin>>n>>y; 
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
		    if(vis[abs(x[i]-x[j])]==0) ans++;
	        vis[abs(x[i]-x[j])]++;
		}
	}
	cout<<ans;
	return 0;
}

