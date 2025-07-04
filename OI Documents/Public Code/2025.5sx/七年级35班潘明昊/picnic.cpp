#include<bits/stdc++.h>
using namespace std;
int n,y,x[10005];
set<long long>ans;
set<double>ans2;
int main()
{
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	scanf("%d%d",&n,&y);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			long long tmp=((max(x[i],x[j])-min(x[i],x[j])));
			if(tmp>0)
			{
				 ans.insert(tmp);
			}
		}
	}
	cout<<ans.size();
	return 0;
}

