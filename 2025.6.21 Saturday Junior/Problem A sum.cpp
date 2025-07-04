#pragma GCC optimize(2,3,"Ofast")
#include<stdio.h>
#include<ctype.h>
#include<unordered_map>
using namespace std;
unordered_map<long long,bool>vis;
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
long long sum[100001],n,m,a[100001],cnt;
int main(){
	#ifndef _WIN64
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	#endif
	read(n,m);
	vis[0]=1;
	for(int i=1;i<=n;++i){
		read(a[i]);
		sum[i]=sum[i-1]+a[i];
		if(sum[i]>=m)if(vis[sum[i]-m])++cnt;
		vis[sum[i]]=1;
	}
	write(cnt);
}
