#include<bits/stdc++.h>
using namespace std;
int n,ans;long double a[1005],now,y;
set<long double>s;
int main()
{
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	cin>>n>>y;
	y/=2;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			now=a[i]>a[j]?a[i]-a[j]:a[j]-a[i];
			now*=y;
			s.insert(now);
		}
	}
	ans=s.size();
	printf("%d",ans);
}

