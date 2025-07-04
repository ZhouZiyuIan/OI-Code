#include<bits/stdc++.h>
using namespace std;
int n,a[100005];long long mx,m,ans;
int main()
{
	freopen("sleep1.in","r",stdin);
	freopen("sleep1.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mx+=a[i];
	}
	m%=mx;
	int i=1;
	while(m>a[i])
	{
		m-=a[i];
		i++;
	}
	cout<<i<<endl;
	cout<<a[i]-m;
}

