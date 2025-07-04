#include<cstdio>
#include<vector>
#include<algorithm>
using std::sort;
using std::vector;
using std::lower_bound;
template<class type>inline const void read(type &in)
{
	in=0;char ch=getchar();bool fh=0;
	while (ch<48||ch>57)fh=ch=='-'?1:fh,ch=getchar();
	while (ch>47&&ch<58)in=(in<<3)+(in<<1)+(ch&15),ch=getchar();
	if (fh)in=-in;
}
const int N=1e6+5,LOG=15;
int n,q;
int to[N],next[N],cnt,head[N];
inline const void addedge(int u,int v)
{
	next[++cnt]=head[u];to[head[u]=cnt]=v;
}
vector<int>v[N],s;
inline const int query(int p,int l,int r)
{
	vector<int>::iterator head=lower_bound(v[p].begin(),v[p].end(),l),tail=lower_bound(v[p].begin(),v[p].end(),r+1);
	return tail-head;
}
int fa[N][LOG],dep[N],dfn[N],dot[N],end[N],dfc;
inline const void dfs(int p)
{
	printf("%d\n",p);
	dot[dfn[p]=++dfc]=p;
	for (int i=head[p];i;i=next[i])dep[to[i]]=dep[p]+1,dfs(to[i]);
	end[p]=dfc;
}
inline const void getfa()
{
	for (int j=1;j<LOG;j++)
		for (int i=1;i<=n;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
}
inline const int jump(int x,int y)
{
	for (int i=0;i<LOG;i++)
		if (y>>i&1)
			x=fa[x][i];
	return x;
}
inline const int query(int x,int y)
{
	if (dep[x]-1<y)return 0;
	int fa=jump(x,y);
	return query(dep[x],dfn[fa],end[fa])-1;
}
int main()
{
	read(n);
	for (int i=1;i<=n;i++){
		read(fa[i][0]);
		if(fa[i][0])addedge(fa[i][0],i);
		else s.emplace_back(i),dep[i]=1;
	}
	for(int i=1;i<=s.size();i++){
//		printf("%d",i);
		dfs(s[i]);
	}
	getfa();
	for (int i=1;i<=n;i++)v[dep[dot[i]]].push_back(i);read(q);
	for (int x,y;q--;)read(x),read(y),printf("%d ",query(x,y));
	return 0;
}
