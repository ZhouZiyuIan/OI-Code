#include<bits/stdc++.h>
using namespace std;
set<long long>sp;
long long n,a[100001],y;
int main()
{
	freopen("simpleB.in","r",stdin);
	cin>>n>>y;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
			{
				sp.insert(abs(a[i]-a[j]));
			}
		}
	}
	cout<<sp.size();
}
