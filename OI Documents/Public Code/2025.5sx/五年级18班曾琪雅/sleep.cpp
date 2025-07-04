#include<bits/stdc++.h>
using namespace std;
unsigned long long n,t,x[100001];
unsigned long long cnt=0;
int main()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	cin>>n>>t;
	for(unsigned long long i=1;i<=n;i++)
	{
		cin>>x[i]; 
		cnt+=x[i];
	}
	t=t%cnt;
	if(t==0)
	{
		cout<<n<<endl<<"0";
		return 0;
	}
	for(unsigned long long i=1;i<=n;i++)
	{
		if(t>x[i])
		{
			t-=x[i];
		}
		else if(t==x[i])
		{
			cout<<i<<endl<<"0";
			return 0;
		}
		else
		{
			cout<<i<<endl<<x[i]-t;
			return 0;
		}
	}
	return 0;
}
