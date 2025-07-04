#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(i%2==0)
		{
			cout<<"No"<<endl;
		}
		else
		{
			cout<<"Yes"<<endl;
		}
	}
	return 0;
}
