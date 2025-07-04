#include<bits/stdc++.h>//
using namespace std;
char a[10100];
int s,k,b[27],mi=1000,ans;
int main()
{
	//freopen("goof.in","r",stdin);
	//freopen("goof.out","w",stdout);
	scanf("%s",a);
	scanf("%d",&k);
	for(int i=0;i<strlen(a);i++)
	{
		b[a[i]-96]++;
	}
	for(int i=1;i<27;i++)
	{
		if(b[i]<mi)
		{
			mi=b[i];
			b[i]=1001;
		}
		if(k-mi>0)k-=mi;
	else if(k-mi<=0)break;
	}
	
	for(int i=1;i<27;i++)if(b[i]!=0&&b[i]!=1001)ans++;
	printf("%d\n",ans);
	for(int i=1;i<27;i++)
	{
		if(b[i]!=0&&b[i]!=1001)
		{
			cout<<a[i];
		}
	}
} 
