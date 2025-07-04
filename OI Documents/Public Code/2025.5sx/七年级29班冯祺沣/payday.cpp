#include<bits/stdc++.h>
using namespace std;
void fre()
{
	freopen("payday.in","r",stdin);
	freopen("payday.out","w",stdout);
}
int n,t,s,sum;
map<int,int> l,r;
int main()
{
	fre();
	for(cin>>t;t;t--,sum=0)
	{
		cin>>n>>s;
		for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
		int a[n+4];
		for(int i=1;i<=n;i++) a[i]=l[i];
		sort(a+1,a+1+n);
		cout<<a[(n+1)/2]<<endl;
	}
	return 0;
}
