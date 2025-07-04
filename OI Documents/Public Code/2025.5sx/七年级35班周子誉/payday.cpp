#include<stdio.h>
#include<ctype.h>
#include<algorithm>
using namespace std;
template<typename T>
void read(T &n){
	n=0;
	T f=1;
	char s=getchar();
	while(!isdigit(s)){
		if(s=='-')f*=-1;
		s=getchar();
	}
	do{
		n=(n<<1)+(n<<3)+(s^48);
		s=getchar();
	}while(isdigit(s));
	n*=f;
}
template<typename T>
void write(T x){
	if(x<0)putchar(45),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+48);
}
struct human{
	int l,r;
}offer[200001];
long long t,n,s,res;
bool cmp(human a,human b){
	if(a.l==b.l)return a.r<b.r;
	return a.l<b.l;
}
main(){
	freopen("payday.in","r",stdin);
	freopen("payday.out","w",stdout);
	read(t);
	while(t--){
		read(n);
		read(s);
		for(int i=0;i<n;i++){
			read(offer[i].l);
			read(offer[i].r);
			s-=offer[i].l;
		}
		sort(offer,offer+n,cmp);
		n>>=1;
		res=offer[n].l+s/(n+1);
		write(res>offer[n].r?offer[n].r:res);
		putchar(10);
	}
}
