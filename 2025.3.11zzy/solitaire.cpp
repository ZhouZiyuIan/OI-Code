#include<stdio.h>
#include<string.h>
struct c{
	int e[11],cnt;
}dot[11];
int T,n,s,e,a,b,f,vis[11];
void dfs(int x){
	vis[x]=1;
	if(x==e){
		puts("Yes");
		f=1;
		return;
	}
	for(int i=0;i<dot[x].cnt;i++){
		if(!vis[dot[x].e[i]])dfs(dot[x].e[i]);
		if(f)return;
	}
}
main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&s,&e);
		f=0;
		memset(vis,0,sizeof(vis));
		memset(dot,0,sizeof(dot));
		for(int i=0;i<n;i++){
			scanf("%d%d",&a,&b);
			dot[a].e[dot[a].cnt++]=b;
		}
		dfs(s);
		if(f==0)puts("No");
	}
}
