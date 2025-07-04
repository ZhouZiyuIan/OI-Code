#include<bits/stdc++.h>
using namespace std;
long long n,y,sum=1,ans,c;
int x[1000001];
double cnt[505050],m;
int main()
{
//	freopen("picnic.in","r",stdin);
//	freopen("picnic.out","w",stdout);
	cin>>n>>y;
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		ans+=i;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			cnt[sum]=abs(x[i]-x[j])*y*1.0/2;
			sum++;
		}
	}
	sort(cnt+1,cnt+sum+1);
	for(int i=1;i<=ans;i++)
	{
		if(cnt[i]==m)
		{
			continue;
		}
		else
		{
			m=cnt[i];
			c++;
		}
	}
	cout<<c-1;
}

