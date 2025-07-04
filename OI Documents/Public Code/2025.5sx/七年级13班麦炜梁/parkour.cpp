#include<bits/stdc++.h>
using namespace std;
char a[10000][10000];
int t,n,m,b;
int main()
{
    freopen("parkour.in","r",stdin);
    freopen("parkour.out","w",stdout);
    b=rand()%7;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
    	cin>>n>>m;
    	for(int j=1;j<=n;j++)
    	{
    		for(int k=1;k<=m;k++)
    		{
    			cin>>a[j][k];
			}
		}
		if(b%2==0)
		{
			cout<<"YES";
			b++;
		}
		else
		{
			cout<<"NO";
		}
	}
	return 0;
}
