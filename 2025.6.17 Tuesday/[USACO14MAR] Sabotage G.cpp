#ifndef ONLINE_JUDGE
#pragma GCC optimize(2,3,"Ofast")
#endif
#include<stdio.h>
#include<ctype.h>
#ifdef _WIN64
#define getchar_unlocked() _getchar_nolock()
#define putchar_unlocked(_c) _putchar_nolock(_c)
#endif
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
	if(x<0ll)x=-x,putchar_unlocked(45);
	if(x>9ll)write(x/10ll);
	putchar_unlocked(x%10ll+48ll);
}
double min(double x,double y){return x<y?x:y;}
int n,m,sum[100001];
double l,r,mid;
bool chk(double x){
	double minval=sum[1]-x;
	for(int i=2;i<n;++i){
		if(sum[n]-x*n-(sum[i]-x*i)+minval<=0)return 1;
		minval=min(minval,sum[i]-x*i);
	}
	return 0;
}
int main(){
	#ifndef ONLINE_JUDGE
	#ifndef _WIN64
	freopen("sabotage.in","r",stdin);
	freopen("sabotage.out","w",stdout);
	#endif
	#endif
	read(&n);
	for(int i=1;i<=n;++i){
		read(&m);
		sum[i]=sum[i-1]+m;
	}
	l=0;
	r=10000;
	while(r-l>1e-5){
		mid=(l+r)/2.0;
		if(chk(mid))r=mid;
		else l=mid;
	}
	printf("%.3lf",r);
}
