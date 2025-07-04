#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int k,len,cnt=26;
char a[N];
bool l=1;
struct node{
	int num;
	char s;
}m[30];
bool cmp(node x,node y)
{
	return x.num<y.num;
}
int main()
{
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	for(int i=1;i<=26;i++)
	  m[i].s=i+'a'-1;
	scanf("%s",a+1);
	len=strlen(a+1);
	for(int i=1;i<=len;i++)
	  m[a[i]-'a'+1].num++;
	sort(m+1,m+1+26,cmp);
	scanf("%d",&k);
	for(int i=1;i<=26;i++)
	{
		if(m[i].num<=k)
		{
			cnt--;
			k-=m[i].num;
		}
		else
		{
			if(l)
			{
				printf("%d\n",cnt);
				l=0;	
			}
			for(int j=1;j<=m[i].num;j++)
			  printf("%c",m[i].s);
		}
	}
	if(l) printf("%d",cnt);
	return 0;
}

