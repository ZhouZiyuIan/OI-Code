#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;
const int maxn=1e6;
int t,n,m,x,y,cnt,res,flag;
struct Node {int l,r;} s[maxn];
void solve()
{
	res=cnt=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		s[i]={x,y};
	}
	int top=n/2+1;cnt=top-1;
	sort(s+1,s+n+1,[](Node a,Node b){return a.l==b.l?a.r<b.r:a.l<b.l;});
	sort(s+1,s+cnt+1,[](Node a,Node b){return a.r-a.l>b.r-b.l;});
	q.push({s[top].r,top});
	s[n+1].l=0x3f3f3f3f;
	for(int i=top+1;i<=n+1;i++)
	{
		flag=0;
		res=max(res,min(q.top().first,s[i-1].l+m/(i-top)));
		while(q.top().first<s[i].l)
		{
			auto tmp=q.top();q.pop();
			if(!cnt){flag=1;break;}
			while(s[cnt].r<tmp.first&&cnt>0)cnt--;
			q.push({s[cnt].r,tmp.second});
			m=m-s[tmp.second].l+s[cnt].l;
			if(m<0){flag=1;break;}
			res=max(res,min(q.top().first,s[i-1].l+m/(i-top)));
			cnt--;
		}
		if(m<(i-top)*(s[i].l-s[i-1].l))flag=1;
		if(flag)
		{
			printf("%d\n",res);
			return;
		}
		m-=(i-top)*(s[i].l-s[i-1].l);
		q.push({s[i].r,i});
	}
}
int main()
{
	freopen("payday.in","r",stdin);
	freopen("payday.out","w",stdout);
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
