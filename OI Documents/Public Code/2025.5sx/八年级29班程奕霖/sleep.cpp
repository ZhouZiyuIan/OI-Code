#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+7;
int x[N];
signed main()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	int n,t,sum=0;
	cin>>n>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		sum+=x[i];
	}
	t%=sum;
	if(!t)
	{
		cout<<n<<'\n'<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(t>x[i])
		{
			t-=x[i];
		}
		else
		{
			cout<<i<<'\n'<<x[i]-t;
			return 0;
		}
	}
}
