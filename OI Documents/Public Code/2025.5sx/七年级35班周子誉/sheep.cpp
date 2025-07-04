#include<stdio.h>
#include<ctype.h>
template<typename T>
void read(T &n){
	n=0;
	T f=1;
	char s=getchar();
	while(!isdigit(s)){
		if(s=='-')f*=-1;
		s=getchar();
	}
	do{
		n=(n<<1)+(n<<3)+(s^48);
		s=getchar();
	}while(isdigit(s));
	n*=f;
}
template<typename T>
void write(T x){
	if(x<0)putchar(45),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+48);
}
int n,a[2001],b[2001],cnt,vis[2001],pos[2001],lim[2001],ans;
void dfs(int x){
	if(x==cnt){
		ans++;
		return;
	}
	for(int i=0;i<cnt-x-(lim[b[x]]?1:0);i++)dfs(x+1);
}
main(){
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	read(n);
	for(int i=0;i<n;i++){
		read(a[i]);
		pos[i]=1;
		if(~a[i])vis[a[i]]=1;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			b[cnt++]=i;
			if(pos[i])lim[i]=1;
		}
	}
	dfs(0);
	write(ans);
}
