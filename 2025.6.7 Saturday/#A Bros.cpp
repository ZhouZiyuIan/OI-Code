#include<stdio.h>
#include<ctype.h>
#include<algorithm>
#include<vector>
using namespace std;
#ifdef _WIN64
#define getchar_unlocked() _fgetc_nolock(stdin)
#define putchar_unlocked(_c) _fputc_nolock(_c,stdout)
#endif
template<typename T>
void read(T&n){
	T f=1;
	n=0;
	char s=getchar_unlocked();
	while(!isdigit(s)){
		if(s=='-')f=-f;
		s=getchar_unlocked();
	}
	do{
		n=(n<<1)+(n<<3)+(s^48);
		s=getchar_unlocked();
	}while(isdigit(s));
	n*=f;
}
template<typename T>
void write(T n){
	if(n<0)putchar_unlocked('-'),n=-n;
	if(n>10)write(n/10);
	putchar_unlocked(48+n%10);
}
template<typename type,typename ...T>
void read(type&a,T&...b){
	read(a);
	read(b...);
}
struct edg{
    int to,nxt;
}e[100001];
vector<int>v[100001],s;
int n,f[100001][17],head[100001],cnt,m,a,k,dep[100001],lg=16,dot[100001],dfn[100001],dfc,ed[100001];
void add(int a,int b){
    e[++cnt].to=b;
    e[cnt].nxt=head[a];
    head[a]=cnt;
}
void dfs(int p){
	dot[dfn[p]=++dfc]=p;
	for (int i=head[p];i;i=e[i].nxt)dep[e[i].to]=dep[p]+1,dfs(e[i].to);
	ed[p]=dfc;
}
int que(int p,int l,int r){
	vector<int>::iterator head=lower_bound(v[p].begin(),v[p].end(),l),tail=lower_bound(v[p].begin(),v[p].end(),r+1);
	return tail-head;
}
int kthfa(int x,int y){
	for(int i=0;i<lg;i++)if(y>>i&1)x=f[x][i];
	return x;
}
int ans(int x,int y){
	if(dep[x]-1<y)return 0;
	int fa=kthfa(x,y);
	return que(dep[x],dfn[fa],ed[fa])-1;
}
int main(){
    read(n);
    for(int i=1;i<=n;++i){
        read(f[i][0]);
        if(f[i][0])add(f[i][0],i);
        else s.emplace_back(i),dep[i]=1;
    }
    for(int i=0;i<s.size();++i)dfs(s[i]);
    for(int j=1;j<lg;++j)for(int i=1;i<=n;++i)f[i][j]=f[f[i][j-1]][j-1];
    for(int i=1;i<=n;++i)v[dep[dot[i]]].emplace_back(i);
    read(m);
    while(m--){
    	read(a,k);
    	write(ans(a,k));
    	putchar(32);
    }
}
