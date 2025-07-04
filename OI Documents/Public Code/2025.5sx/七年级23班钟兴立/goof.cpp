#include<bits/stdc++.h>
using namespace std;
int len,k,vis[26],ans;
char s[500005];
struct li
{
	int name;
	int number;
}a[31];
bool cmp(li a,li b)
{
	return a.number<b.number;
}
int main()
{
	freopen("goof.in","w",stdin);
	freopen("goof.out","r",stdout);
	scanf("%s",s+1);
	scanf("%d",&k);
	len=strlen(s+1);
	if(k>=len)
	{
		printf("0");
		return 0;
	}
	for(int i=1;i<=len;i++)
	{
		if(a[s[i]-96].number==0)
		{
			ans++;
		}
		a[s[i]-96].number++;
		a[s[i]-96].name=s[i]-96;
	}
	sort(a+1,a+26+1,cmp);
	for(int i=1;i<=26;i++)
	{
		if(k>=a[i].number&&a[i].number!=0)
		{
			k-=a[i].number;
			vis[a[i].name]=1;
			ans--;
		}
	}
	
	printf("%d",ans);
	printf("\n");
	for(int i=1;i<=len;i++)
	{
		if(vis[s[i]-96]==0)
		{
			printf("%c",s[i]);
		}
	}
	
	
}
