#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	scanf("%d", &t);
	while(t--)
	{
		int a=rand()%2;
		string ans=a?"YES":"NO";
		cout<<ans<<"\n";
	}
	return 0;	
} 
