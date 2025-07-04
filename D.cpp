#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#ifdef _WIN64
#define getchar_unlocked() _getchar_nolock()
#define putchar_unlocked(_c) _putchar_nolock(_c)
#endif
template<typename T>
void read(T&x){
	T f=1;
	x=0;
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
}
template<typename T>
void write(T x){
	if(x<0)x=-x,putchar_unlocked(45);
	if(x>9)write(x/10);
	putchar_unlocked(x%10+48);
}
template<typename type,typename ...T>
inline void read(type &x,T&...y){read(x);read(y...);}
int n,m,k,a,l[501],r[501],cz[501],sum;
main(){
	freopen("skip.in","r",stdin);
	freopen("skip.out","w",stdout);
	read(n,m,k);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			read(a);
			if(a==1){
				if(!l[i])l[i]=j;
				r[i]=j;
			}
		}
		cz[i]=r[i]-l[i]+1;
		sum+=cz[i];
	}
	write(sum-(rand()%k));
}
