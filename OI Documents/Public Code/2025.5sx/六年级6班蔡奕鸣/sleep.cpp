#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,t,x[1000005],tmp;
int main()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	cin>>n>>t;
	for(int i = 1; i <= n; i++)
	{
		cin>>x[i];
		t %= x[i];
	}
	for(int i = 1; i <= n; i++)
	{
		if(t <= x[i])
		{
			cout<<i<<endl<<(x[i] - t);
			return 0;
		}
		t -= x[i];
	}
	return 0;
}
