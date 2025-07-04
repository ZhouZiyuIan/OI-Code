#include<stdio.h>
#ifdef _WIN64
#define getchar_unlocked() _getchar_nolock()
#define putchar_unlocked(_c) _putchar_nolock(_c)
#endif
#define _U 0x01
#define _L 0x02
#define _D 0x04
#define _C 0x08
#define _P 0x10
#define _S 0x20
#define _X 0x40
#define _SP 0x80
extern unsigned char _ctype[];
#define isdigit(c) ((_ctype+1)[c]&(_D))
unsigned char _ctype[]={0x00,_C,_C,_C,_C,_C,_C,_C,_C,_C,_C|_S,_C|_S,_C|_S,_C|_S,_C|_S,_C,_C,_C,_C,_C,_C,_C,_C,_C,_C,_C,_C,_C,_C,_C,_C,_C,_C,_S|_SP,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_D,_D,_D,_D,_D,_D,_D,_D,_D,_D,_P,_P,_P,_P,_P,_P,_P,_U|_X,_U|_X,_U|_X,_U|_X,_U|_X,_U|_X,_U,_U,_U,_U,_U,_U,_U,_U,_U,_U,_U,_U,_U,_U,_U,_U,_U,_U,_U,_U,_P,_P,_P,_P,_P,_P,_L|_X,_L|_X,_L|_X,_L|_X,_L|_X,_L|_X,_L,_L,_L,_L,_L,_L,_L,_L,_L,_L,_L,_L,_L,_L,_L,_L,_L,_L,_L,_L,_P,_P,_P,_P,_C,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
void read(int*w){
	int f=1,x=0;
	char s=getchar_unlocked();
	while(!isdigit(s)){
		if(s=='-')f=-f;
		s=getchar_unlocked();
	}
	do{
		x=(x<<1)+(x<<3)+(s^48);
		s=getchar_unlocked();
	}while(isdigit(s));
	x*=f;
	*w=x;
}
void write(int x){
	if(x<0ll)putchar_unlocked(45);
	if(x>9ll)write(x/10ll);
	putchar_unlocked(x%10ll+48ll);
}
int min(int a,int b){return a<b?a:b;}
struct edg{
	int to,nxt;
}ed[1000001];
int n,k,cnt,head[1000001],s,e,fa[1000001],dep[1000001],sd[1000001];
void add(int a,int b){
	ed[++cnt].nxt=head[a];
	ed[cnt].to=b;
	head[a]=cnt;
}
int dfs1(int x,int fat){
    fa[x]=fat;
    dep[x]=dep[fat]+1;
    int is_leaf=1;
    for(int i=head[x];i;i=ed[i].nxt){
        int v=ed[i].to;
        if(v==fat)continue;
        sd[x]=min(dfs1(v,x),sd[x]);
        is_leaf=0;
    }
    if(is_leaf)return sd[x]=dep[x];
    return sd[x];
}
int dfs2(int x){
    if((dep[x]*2)>sd[x])return 1;
    int res=0;
    for(int i=head[x];i;i=ed[i].nxt){
        int v=ed[i].to;
        if(v==fa[x])continue;
        res+=dfs2(v);
    }
    return res;
}
main(){
    freopen("atlarge.in","r",stdin);
    freopen("atlarge.out","w",stdout);
    read(&n);
    read(&k);
    for(int i=1;i<n;i++){
		read(&s);
		read(&e);
		add(s,e);
		add(e,s);
        sd[i]=2147483647;
	}
    sd[n]=2147483647;
    dfs1(k,0);
    write(dfs2(k));
}