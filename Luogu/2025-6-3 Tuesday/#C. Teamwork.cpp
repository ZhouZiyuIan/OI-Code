#include<stdio.h>
#include<ctype.h>
#ifdef _WIN64
#define getchar_unlocked() _fgetc_nolock(stdin)
#define putchar_unlocked(_c) _fputc_nolock((_c),stdout)
#endif
template<typename T>
void read(T&w){
	T f=1;
	w=0;
	char s=getchar_unlocked();
	while(!isdigit(s)){
		if(s=='-')f=-f;
		s=getchar_unlocked();
	}
	do{
		w=(w<<1)+(w<<3)+(s^48);
		s=getchar_unlocked();
	}while(isdigit(s));
	w*=f;
}
void write(int x){
	if(x<0)putchar_unlocked(45);
	if(x>9)write(x/10);
	putchar_unlocked(x%10+48);
}
int max(int a,int b){return a>b?a:b;}
int n,k,s[10001],tmpmax,f[10001];
main(){
	freopen("teamwork.in","r",stdin);
	freopen("teamwork.out","w",stdout);
	read(n);
	read(k);
	for(int i=1;i<=n;i++)read(s[i]);
	for(int i=1;i<=n;i++){
		tmpmax=0;
		for(int j=i;j>=max(1,i-k+1);j--){
			tmpmax=max(tmpmax,s[j]);
			f[i]=max(f[i],f[j-1]+tmpmax*(i-j+1));
		}
	}
	write(f[n]);
}
