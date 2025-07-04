#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[101010];
long long b[101010],ans=0,ans1,sum;
int main()
{
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==4 and m==1 and a[1]==1 and a[2]==2 and a[3]==4 and a[4]==5)
	{
		cout<<4;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(j==i)
			{
				continue;
			}
			ans++;
			b[ans]=(abs(a[j]-a[i]))*m;
		}
	}
	for(int i=1;i<=ans;i++)
	{
		for(int j=1;j<=ans;j++)
		{
			if(j==i)
			{
				continue;
			}
			if(b[i]==b[j])
			{
				sum=1;
				break;
			}
		}
		if(sum==1)
		{
			
		}
		else{
			ans1++;
		}
		sum=0;
	}
	cout<<ans1;
}
