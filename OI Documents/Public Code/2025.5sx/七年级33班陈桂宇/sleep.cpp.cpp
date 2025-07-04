#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int n,t,x[N];
char s;
signed main()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	cin>>n>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		
	}
	while(1)
	{
		for(int i=1;i<=n;i++)
    	{
	     	if(t-x[i]>0)
	    	{
		    	t-=x[i];
		    }
	    	else
		    {
			    cout<<i<<"\n"<<abs(t-x[i]);
			    return 0;
		    }
     	}
	}
	
	return 0;
}

