#include<bits/stdc++.h>
using namespace std;
char str[100001];
unsigned long long k,n=0,a[100001],x[100001];
unsigned long long ans=0;
int main()
{
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	scanf("%s",str);
	cin>>k;
	for(unsigned long long i=0;i<strlen(str);i++)
	{
		x[str[i]-48]++;
		if(x[str[i]-48]==1)
		{
			n++;
		}
		a[n]=x[str[i]-48];
	}
	sort(a+1,a+1+n);
	for(unsigned long long i=1;i<=n;i++)
	{
		if(k>=a[i])
		{
			k-=a[i];
			ans++;
			for(unsigned long long j=0;j<strlen(str);j++)
			{
				if(x[str[j]-48]==a[i])
				{
					str[j]=' ';
				}
			}
		}
	}
	cout<<n-ans<<endl;
	for(unsigned long long i=0;i<strlen(str);i++)
	{
		if(str[i]!=' ')
		{
			printf("%c",str[i]); 
		}
	}
	return 0;
}
/*从小到大*/ 
