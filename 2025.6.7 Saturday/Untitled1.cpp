#pragma GCC optimize(3,"Ofast")
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
	if(x<0ll)x=-x,putchar_unlocked(45);
	if(x>9ll)write(x/10ll);
	putchar_unlocked(x%10ll+48ll);
}
long long k,n,lcnt[11][50001],rcnt[11][50001],f,cnt;
char s[11][50001];
int main(){
	freopen("cbs.in","r",stdin);
	freopen("cbs.out","w",stdout);
	read(&k);
	read(&n);
	for(int i=0;i<k;++i){
		getchar_unlocked();
		for(int j=1; j<=n; ++j) {
			s[i][j]=getchar_unlocked();
			lcnt[i][j]=lcnt[i][j-1];
			rcnt[i][j]=rcnt[i][j-1];
			if(s[i][j]==40)++lcnt[i][j];
			else ++rcnt[i][j];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			f=0;
			for(int x=0;x<k;x++){
				if(lcnt[x][j]-lcnt[x][i-1]!=rcnt[x][j]-rcnt[x][i-1]){
					f=1;
					break;
				}
				for(int y=i;y<=j;y++)if(lcnt[x][y]-lcnt[x][i-1]<rcnt[x][y]-rcnt[x][i-1]){
					f=2;
					break;
				}
				if(f)break;
			}
			if(f==2)break;
			if(f)continue;
			cnt++;
		}
	}
	write(cnt);
}
