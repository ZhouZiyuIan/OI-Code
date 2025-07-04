#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll y;
int n;
const int N=1e3+7;
ll x[N];
map<ll,ll>bz;
ll myabs(ll o)
{
	if(o>=0)
	return o;
	else
	return -o;
}
int main()
{
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	cin>>n>>y;
	for(int i=1;i<=n;i++)
	cin>>x[i];
	int res=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			ll a=myabs(x[i]-x[j]);
			ll b=myabs(y);
			if(bz[a*b]==0)
			{
				bz[a*b]=1;
				res++;
			} 
		}
	}
	cout<<res;
	return 0;
}
