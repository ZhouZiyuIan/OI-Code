#pragma GCC optimize(2,3,"Ofast","inline")
#include<stdio.h>
#include<ctype.h>
#include<vector>
#include<algorithm>
using namespace std;
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
template<typename T>
T lowbit(T a){return a&-a;}
int T,n,k,t[400001];
long long a[200001],l,r,mid,f[200001];
vector<long long>disc;
int rk(long long x){return lower_bound(disc.begin(),disc.end(),x)-disc.begin()+1;}
void upd(unsigned p,int v){
	for(unsigned i=p;i>0;i-=lowbit(i))t[i]=max(t[i],v);
}
int que(int x,unsigned B){
	int ret=-1000000000;
	for(int i=x;i<B;i+=lowbit(i))ret=max(t[i],ret);
	return ret;
}
void rmv(unsigned x,unsigned B){
	for(unsigned i=x;i<B;i+=lowbit(i))t[i]=-1e9;
	for(unsigned i=x;i>0;i-=lowbit(i))t[i]=-1e9;
}
bool chk(long long ans,int n,int k){
	disc.clear();
	for(int i=1;i<=n;++i){
		disc.emplace_back(a[i]);
		disc.emplace_back(a[i]-ans);
	}
	disc.emplace_back(0);
	sort(disc.begin(),disc.end());
	disc.erase(unique(disc.begin(),disc.end()),disc.end());
	for(unsigned i=1;i<=disc.size();++i)rmv(i,disc.size());
	f[0]=0;
	upd(rk(0),0);
	for(int i=1;i<=n;++i){
		f[i]=que(rk(a[i]-ans),disc.size()+1)+1;
		upd(rk(a[i]),f[i]);
		if(f[i]>=k)return 1;
	}
	return 0;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	read(T);
	while(T--){
		read(n);
		read(k);
		for(int i=1;i<=n;++i){
			read(a[i]);
			a[i]+=a[i-1];
		}
		r=1e15;
		l=-r;
		while(l+1<r){
			mid=(l+r)/2;
			if(chk(mid,n,k))r=mid;
			else l=mid;
		}
		write(r);
		putchar_unlocked(10);
	}
}
