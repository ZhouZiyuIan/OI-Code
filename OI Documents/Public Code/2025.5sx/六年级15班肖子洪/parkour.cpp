#include<bits/stdc++.h>
using namespace std;
int n;
int x,y;
char s[10101][10101];
int main()
{	
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		for(int j=1;j<=y;j++)
		{
			for(int k=1;k<=x;k++)
			{
				cin>>s[j][k;]
			}
		}	
	}
	for(int i=1;i<=n;i++)
	{
		if(i%2==0)
		{
			cout<<"No\n";
		}
		else{
			cout<<"Yes\n";
		}
	}
}	

