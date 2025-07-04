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
template<typename type>
type min(type a,type b){return a<b?a:b;}
template<typename type>
type max(type a,type b){return a>b?a:b;}
int n,c[1000001],d[1000001],curmin,curmax,curlen,curstart,pos,queuecnt,ava,lststart,lstmin,lstmax;
int main(){
	freopen("cat.in","r",stdin);
	freopen("cat.out","w",stdout);
	read(n);
	for(int i=0;i<n;i++)read(c[i],d[i]);
	curmin=c[0];
	curmax=d[0];
	curlen=1;
	curstart=0; 
	while(pos<n){
		ava=0;
		for(;pos<=curmin-1+curstart&&pos-curstart+1<=curmax&&pos<n;){
			curmin=max(curmin,c[pos]);
			curmax=min(curmax,d[pos]);
			pos++;
			ava++;
		}
		if(curmin>pos-curstart){
			putchar_unlocked('N');
			putchar_unlocked('O');
			return 0;
		}
		if(!ava){
			queuecnt--;
			curstart=lststart;
			curmin=lstmin;
			curmax=lstmax;
			continue;
		}
		queuecnt++;
		lststart=curstart;
		lstmin=curmin;
		lstmax=curmax;
		curmin=c[pos];
		curmax=d[pos];
		curstart=pos;
	}
	write(queuecnt);
	putchar_unlocked(32);
	freopen("/dev/urandom","r",stdin);
	read(curmin);
	write(curmin%n);
}
