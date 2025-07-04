#include<bits/stdc++.h>
using namespace std;
long long n,x[1000010],t,ans;
int main()
{
	//freopen("sleep.in","r",stdin);
	//freopen("sleep.out","w",stdout);
	cin>>n>>t;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	int j=0;
	while(1)
	{
		j++;
		if(j>n)
		j=j%n;
		t-=x[j];
		if(t<=0)
		{
			ans++;
			if(ans>n)
			ans=ans%n;
			cout<<ans<<endl;
			cout<<0-t;
			break;
		}
		else
		{
			ans++;
		}
	}
	return 0;
}
