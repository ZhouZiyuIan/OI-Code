#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,ans;
unsigned long long a[10101010];
int main()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	cin>>n>>m;
	for(unsigned long long i=1;i<=n;i++)
	{
		cin>>a[i];
		ans+=a[i];
	}
	unsigned long long sum=m%ans;
	ans=0;
	for(unsigned long long i=1;i<=n;i++)
	{
		ans+=a[i];
		if(sum<=ans)
		{
			cout<<i<<"\n"<<ans-sum;
			return 0;
		}
	}
} 
