#include<bits/stdc++.h>
using namespace std;
int n,k,p,inf=1e5+5,vis[100010],ans,sum,a[50][100010];
char s[100010];
struct node{
	int cnt,id;
}e[30];
bool cmp(node x,node y){
	return x.cnt<y.cnt;
}
int main()
{
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%d",&k);
	if(k>=n)
	{
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		p=s[i]-'0'-48;
		e[p].cnt++;
		if(e[p].cnt==1) sum++;
		a[p][e[p].cnt]=i;
		e[p].id=p;
		
	}
	for(int i=1;i<=30;i++){
		if(e[i].cnt==0){
			e[i].cnt=inf;
		}
	}
	sort(e+1,e+30,cmp);
	for(int i=1;i<=30;i++){
		if(k<e[i].cnt){
			ans=sum-i+1;	
			break;
		}
		k-=e[i].cnt;
		for(int j=1;j<=e[i].cnt;j++)
		{
			vis[ a [e[i].id][j] ]=1;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++){
		if(!vis[i]) printf("%c",s[i]);
	}
 }
