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
int n,c[1000001],d[1000001],lg[1000001];
int main(){
	read(n);
	for(int i=0;i<n;i++)read(c[i],d[i]);
	lg[1]=0;
	for(int i=0;i<n;i++){;}
}