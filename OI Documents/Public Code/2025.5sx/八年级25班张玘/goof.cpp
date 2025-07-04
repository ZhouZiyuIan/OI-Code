#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6;
int b[100],vis[100],n,k,ans=26;
char a[maxn];
struct Node{int id,cnt;} s[100];
int main()
{
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	scanf("%s%d",a+1,&k);
	n=strlen(a+1);
	for(int i=1;i<=n;i++)b[a[i]-'a']++;
	for(int i=0;i<=25;i++)s[i]={i,b[i]};
	sort(s,s+26,[](Node x,Node y){return x.cnt<y.cnt;});
	for(int i=0;i<=25;i++)
	{
		if(k<s[i].cnt)break;
		vis[s[i].id]=1;ans--;
		k-=s[i].cnt;
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
	{
		if(vis[a[i]-'a'])continue;
		printf("%c",a[i]);
	}
	return 0;
}
