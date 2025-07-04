#pragma GCC optimize(3,"Ofast","inline")
#include<stdio.h>
#include<ctype.h>
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
long long n,l,r,a[13],cnt;
void dfs(int x,long long val){
	if(x==n){
		if(l<=val&&val<=r)cnt++;
		return;
	}
	if(val>r)return;
	for(int i=0;i<=(r-val)/a[x];i++)dfs(x+1,val+i*a[x]);
}
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	read(n,l,r);
	for(int i=0;i<n;i++)read(a[i]);
	dfs(0,0);
	write(cnt);
}
