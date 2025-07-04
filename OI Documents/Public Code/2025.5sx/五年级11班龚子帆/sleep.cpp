#include<bits/stdc++.h>
using namespace std;
unsigned long long x,n,t[100020];
int main()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i];
	}
	for(unsigned long long i=1;i<=n;i++)
	{
		x-=t[i];
		if(x<=0)
		{
			cout<<i<<"\n"<<0-x;
			return 0;
		}
		if(i==n)
		{
			i=0;
		}
	}
	return 0;
}
