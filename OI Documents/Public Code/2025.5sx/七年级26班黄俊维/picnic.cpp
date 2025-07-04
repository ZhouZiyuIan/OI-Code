#include<bits/stdc++.h>
using namespace std;
int n;
long long y;
long long x[1005];
long long ans;
long long vis[4005];
int main()
{
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
    cin>>n;
    cin>>y;
    for(int i=1;i<=n;i++)
    {
    	cin>>x[i];
    }
    ans=((n-1)+1)*(n-1)/2;
    for(int i=1;i<=n;i++)
    {
    	for(int j=i+1;j<=n;j++)
    	{
    		if(vis[abs(x[i]-x[j])]==0)
    		{
    			vis[abs(x[i]-x[j])]++;
			}
			else
			{
				ans--;
			}
		}
	}
	cout<<ans;
	return 0;
}
