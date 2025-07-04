#include<stdio.h>
#include<ctype.h>
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
int n;
long long ans;
const long long c=1000000007;
long long fstpow(long long a,long long b){
	long long ans=1;
	while(b>1){
		if(b%2){
			b--;
			ans*=a;
			ans%=c;
		}
		else{
			b/=2;
			a*=a;
			a%=c;
		}
	}
	ans*=a;
	return ans%c;
}
void write(long long x){
	if(x<0)x=-x,putchar_unlocked(45);
	if(x>9)write(x/10ll);
	putchar_unlocked(x%10ll+48);
}
main(){
	freopen("case.in","r",stdin);
	freopen("case.out","w",stdout);
	read(&n);
	ans=fstpow(10,n)-fstpow(9,n)-fstpow(9,n)+fstpow(8,n);
	ans%=c;
	ans=(ans+c)%c;
	write(ans);
}
