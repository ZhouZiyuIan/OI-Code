#include<bits/stdc++.h>
using namespace std;
int t;
long long n,m;
int x,y;
char tmp[10005],a[15][10005];
int main()
{
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
    cin>>t;
    while(t--)
    {
    	cin>>n>>m;
    	for(int i=1;i<=m;i++)
    	{
    		cin>>tmp+1;
    		for(int j=1;j<=n;j++)
    		{
    			a[i][j]=tmp[j];
    			if(a[i][j]=='s')
    			{
    				x=i;
    				y=j;
				}
			}
		}
		if(a[x][y+1]!='.')
		{
			cout<<"NO"<<endl;
			continue;
		}
		int star_m=2,end_m=3;
		if(x==1)
		{
			star_m=1;
			end_m=2;
		}
		if(x==3)
		{
			star_m=2;
			end_m=3;
		}
		int mar;
		for(int i=3;i<=n;i++)
		{
			mar=0;
			for(int j=star_m;j<=end_m;j++)
			{
				if(a[i][j]!='.')
				{
					mar++;
				}
				if(mar>1)
				{
					cout<<"NO"<<endl;
					break;
				}
			}
			if(mar>1)
			{
				break;
			}
			if(star_m==1)
			{
				star_m=2;
				end_m=3;
			}
			else
			{
				star_m=1;
				end_m=2;
			}
		}
		if(mar>1)
		{
			continue;
		}
		cout<<"YES"<<endl;
	}
	return 0;
}
