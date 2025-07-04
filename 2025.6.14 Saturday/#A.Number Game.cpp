#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#ifdef _WIN64
#define getchar_unlocked() _getchar_nolock()
#define putchar_unlocked(_c) _putchar_nolock(_c)
#endif
void read(long long*w){
	long long f=1,x=0;
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
void write(long long x){
	if(x<0)x=-x,putchar_unlocked(45);
	if(x>9)write(x/10);
	putchar_unlocked(x%10+48);
}
int cmp1(const void*a,const void*b){return *(long long*)b-*(long long*)a;}
int cmp(const void*a,const void*b){return *(long long*)a-*(long long*)b;}
long long n,m,a[100001],b[100001],l,ans;
int main(){
	#ifndef ONLINE_JUDGE
	#ifndef _WIN64
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	#endif 
	#endif
	read(&n);
	read(&m);
	for(int i=0;i<n;++i)read(&a[i]);
	for(int i=0;i<m;++i)read(&b[i]);
	qsort(a,n,sizeof(long long),cmp1);
	qsort(b,m,sizeof(long long),cmp1);
	for(int i=0;i<n;i++){
		if(a[i]>0)ans+=a[i]*b[i];
		else break;
	}
	qsort(a,n,sizeof(long long),cmp);
	qsort(b,m,sizeof(long long),cmp);
	for(int i=0;i<n;i++){
		if(a[i]<0)ans+=a[i]*b[i];
		else break;
	}
	write(ans);
}