#ifndef ONLINE_JUDGE
#pragma GCC optimize(2,3,"Ofast")
#endif
#include<stdio.h>
#include<algorithm>
using namespace std;
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
void read(long long*w){
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
void write(long long x){
	if(x<0ll)x=-x,putchar_unlocked(45);
	if(x>9ll)write(x/10ll);
	putchar_unlocked(x%10ll+48ll);
}
bool cmp(long long a,long long b){return a>b;}
long long n,a[501],b[501],t,cnt,ans[501];
void mjn(int id){
	t=0;
	for(int i=0;i<=n;++i){
		if(i==id)continue;
		b[t++]=a[i];
	}
}
bool chk(){
	long long k=n;
	stable_sort(b,b+k,cmp);
	while(k){
		long long id=1;
		while(b[0]&&b[id]){
			--b[0];
			--b[id++];
		}
		if(b[0])return 1;
		stable_sort(b,b+k,cmp);
		--k;
	}
	return 0;
}
int main(){
	#ifndef ONLINE_JUDGE
	#ifndef _WIN64
	freopen("fcount.in","r",stdin);
	freopen("fcount.out","w",stdout);
	#endif
	#endif
	read(&n);
	for(int i=0;i<=n;++i)read(&a[i]);
	for(int i=0;i<=n;++i){
		mjn(i);
		if(!chk())ans[cnt++]=i+1;
	}
	write(cnt);
	putchar_unlocked(10);
	for(int i=0;i<cnt;++i){
		write(ans[i]);
		putchar_unlocked(10);
	}
}
