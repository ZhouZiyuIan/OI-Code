#include<bits/stdc++.h>
using namespace std;
long long n,y,s[1000000],t[1000000],sam=0;
int main()
{
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	cin>>n>>y;
	for(long long i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(long long i=1;i<n;i++)
	{
		for(long long j=i+1;j<=n;j++)
		{
			if(t[abs(s[i]-s[j])]==0)
			{
				sam++;
				t[abs(s[i]-s[j])]++;
			}
		}
	}
	cout<<sam;
}
