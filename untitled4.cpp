#pragma GCC optimize(2,3,"Ofast")
#include<stdio.h>
#include<string.h>
#include<ctype.h>
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
void read(type &x,T&...y){read(x);read(y...);}
template <typename T>
T min(T a,T b){return a>b?b:a;}
int n,m,times,a[501],sum,w[501][501],tmp,f[501],ans;
int main(){
	#ifndef _WIN64
	freopen("skip.in","r",stdin);
	freopen("skip.out","w",stdout);
	#endif
	read(n,m,times);
	memset(w,0x3f,sizeof(w));
	memset(f,0x3f,sizeof(f));
	ans=f[0];
	f[0]=0;
	for(int i=1;i<=n;++i){
		sum=0;
		for(int j=1;j<=m;++j){
			read(a[j]);
			sum+=a[j];
		}
		w[i][sum]=0;
		for(int j=1;j<=m;++j){
			tmp=0;
			for(int k=j;k<=m;++k){
				tmp+=a[k];
				w[i][sum-tmp]=min(w[i][sum-tmp],k-j+1);
			}
		}
	}
	for(int i=1;i<=n;++i)for(int j=times;j>=0;--j){
		f[j]=f[j]+w[i][0];
		for(int k=j-1;k>=0;--k)f[j]=min(f[j],f[k]+w[i][j-k]);
	}
	for(int i=1;i<=times;++i)ans=min(ans,f[i]);
	write(ans);
}
