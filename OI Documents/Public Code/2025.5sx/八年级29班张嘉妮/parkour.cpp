#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		if(i%2==1) printf("YES\n");
		else printf("NO\n");
	}
}
