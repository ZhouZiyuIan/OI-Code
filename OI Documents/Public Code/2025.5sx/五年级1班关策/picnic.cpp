#include<bits/stdc++.h>
using namespace std;
long long n,x[1005],y;
map<int,int> mp;
int main()
{
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	cin>>n>>y;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		for(int j=1;j<i;j++)
		{
			mp[x[i]-x[j]]++;
		}
	}
	cout<<mp.size();
	return 0;
}
