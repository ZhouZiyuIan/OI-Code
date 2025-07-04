#include<bits/stdc++.h>
using namespace std;
long long n,t,x[100000000],q,w=1;
int main()
{
    freopen("sleep.in","r",stdin);
    freopen("sleep.out","w",stdout);
    cin>>n>>t;
    for(int i=1;i<=n;i++)
    {
    	cin>>x[i];
    	q+=x[i];
	}
    t=t%q;
    while(1)
    {
    	if(x[w]<t)
    	{
    		t-=x[w];
		}
		else if(x[w]>=t)
		{
			cout<<w<<endl;
			cout<<x[w]-t;
			return 0;
		}
		
		if(w==n)
		{
			w=1;
		}
		else
		{
		w++;	
		}
		
	}
    return 0;
}
