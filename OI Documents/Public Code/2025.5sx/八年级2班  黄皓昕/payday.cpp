#include<bits/stdc++.h>
using namespace std;
int n,a[200005],l,Q,r;long long s;
int main()
{
	freopen("payday.in","r",stdin);
	freopen("payday.out","w",stdout);
	cin>>Q;
	while(Q--)
	{
		cin>>n>>s;
		for(int i=1;i<=n;i++)
		{
			cin>>l>>r;
			if(r>s)a[i]=s;
			else a[i]=r;
		}
		sort(a+1,a+n+1);
		n/=2;
		n++;
		cout<<a[n]<<"\n";
	}
}

