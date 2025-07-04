#include<bits/stdc++.h>
using namespace std;
long long n,t;
long long a[100005];
long long end;
int main()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
    cin>>n>>t;
    long long tmp=0;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	tmp+=a[i];
	}
	if(tmp==t)
	{
		cout<<n<<endl;
		cout<<end;
		return 0;
	}
	else if(tmp<t)
	{
		tmp=t%tmp;
		t=tmp;
	}
	for(int i=1;i<=n;i++)
	{
		if(t>a[i])
		{
			t-=a[i];
		}
		else if(t==a[i])
		{
			cout<<i<<endl;
			cout<<end;
			return 0;
		}
		else if(t<a[i])
		{
			cout<<i<<endl;
			end=a[i]-t;
			cout<<end;
			return 0;
		}
	}
}
