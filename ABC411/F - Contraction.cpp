#include<stdio.h>
#include<set>
std::set<int>s[300001];
std::set<int>::iterator t;
int n,m,x,u[300001],v[300001],i,j,f[300001],q;
int fa(int x){return x^f[x]?f[x]=fa(f[x]):x;}
int main(){
	scanf("%d%d",&n,&m);
	for(;x^m;){
		scanf("%d%d",&i,&j);
		s[u[++x]=i].insert(j);
		s[v[x]=j].insert(i);
	}
	for(i=n;i;--i)f[i]=i;
	scanf("%d",&q);
	while(q--){
		scanf("%d",&x);
		if(fa(u[x])^fa(v[x])){
			if(s[i=f[u[x]]].size()<s[j=f[v[x]]].size())i^=j^=i^=j;
			--m;
			s[i].erase(j);
			s[j].erase(i);
			for(int w:s[j]){
				s[w].erase(j);
				t=s[i].lower_bound(w);
				if((!(t==s[i].end()))&&*t==w)--m;
				else{
					s[i].insert(w);
					s[w].insert(i);
				}
			}
			f[j]=i;
		}
		printf("%d\n",m);
	}
}
