#include<bits/stdc++.h>
using namespace std;
long long a,b,c[100005],d,f,g;
int main()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
cin>>a>>b;
for(int i=1;i<=a;i++)
{
	cin>>c[i];
	d+=c[i];
}
b=b%d;
for(int i=1;i<=a;i++)
{
	b=b-c[i];
	if(b<=0)
	{
		g=i;
		b=0-b;
		break;
	}
	
}
cout<<g<<" "<<b;
	return 0;
}

