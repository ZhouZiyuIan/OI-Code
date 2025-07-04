#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,y,x[N];
set<double> s;
int main()
{
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	scanf("%d%d", &n, &y);
	for(int i=1;i<=n;i++)
		scanf("%d", &x[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			double a=y*1.0*abs(x[j]-x[i])/2;
			s.insert(a);
		}
	}
	printf("%d", s.size());
	return 0;	
} 
