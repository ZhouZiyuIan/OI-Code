#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
char s[N];
int k,n,p;
int cnt[30],a[30];
bool judge(int x)
{
	for(int i=1;i<=26;i++)
	{
		if(cnt[i]==0&&s[x]==('a'+i-1))
		{
			return false;
		}
	}		
	return true;
}
int main()
{
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	scanf("%s", s+1);
	n=strlen(s+1);
	scanf("%d", &k);
	for(int i=1;i<=n;i++)
	{
		int ch=s[i]-'a'+1;
		cnt[ch]++;
	}
	for(int i=1;i<=26;i++)
	{
		if(cnt[i]!=0)
		{
			a[++p]=cnt[i];
		}
	}
	sort(a+1,a+p+1);
	int sum=0,ans=p;
	for(int i=1;i<=p;i++)
	{
		if(sum+a[i]>k)
		{
			printf("%d\n", ans);
			for(int i=1;i<=n;i++)
			{
				if(judge(i))
				{
					printf("%c", s[i]);
				}
			}
			return 0;
		}
		if(cnt[i]!=0)
		{
			ans--;
			sum+=cnt[i];
			cnt[i]=0;
		}	
	}
	printf("0"); 
	return 0;	
} 
