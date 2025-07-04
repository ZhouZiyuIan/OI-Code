#include<bits/stdc++.h>
using namespace std;
const int M=31,N=1e5+7;
struct node
{
	int cnt,id;
}bz[M];
int lim[M];
char s[N];
int k;
int res=0;
bool cmp(node x,node y)
{
	return x.cnt<y.cnt;
}
int main()
{
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	cin>>s+1>>k;
	for(int i=1;i<=strlen(s+1);i++)
	{
		bz[s[i]-96].cnt++;
		if(bz[s[i]-96].cnt==1)
		res++;
		bz[s[i]-96].id=s[i]-96;
		lim[s[i]-96]++;
	}	
	sort(bz+1,bz+27,cmp);
	for(int i=1;i<=26;i++)
	{
		if(k>=bz[i].cnt&&bz[i].cnt!=0)
		{
			res--;
			k-=bz[i].cnt;
			lim[bz[i].id]=0;
		}
	}
	cout<<res<<endl;
	for(int i=1;i<=strlen(s+1);i++)
	{
		if(lim[s[i]-96]!=0)
		cout<<s[i];
	}
	return 0;
}
