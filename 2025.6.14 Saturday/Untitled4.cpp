#include<stdio.h>
#include<string.h>
#include<vector>
#include<ctype.h>
#include<algorithm>
#include<unordered_map>
#ifdef _WIN64
#define getchar_unlocked() _getchar_nolock()
#define putchar_unlocked(_c) _putchar_nolock(_c)
#endif
#define lowbit(x) ((x)&(-x))
using namespace std;
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
vector<int>num;
unordered_map<int,int>ma;
long long p[100001],a[100001],T,n,m,tree1[100001],tree2[100001],l,r,mid;
void add(long long*tr,long long x,long long k){
	while(x<=n){
		tr[x]+=k;
		x+=lowbit(x);
	}
}
long long que(long long*tr,long long x){
	long long tmp=0;
	while(x){
		tmp+=tr[x];
		x-=lowbit(x);
	}
	return tmp;
}
int main(){
	#ifndef ONLINE_JUDGE
	#ifndef _WIN64
	freopen("car.in","r",stdin);
	freopen("car.out","w",stdout);
	#endif
	#endif
	read(T);
	while(T--){
		ma.clear();num.clear();
		memset(tree1,0,sizeof(tree1));
		memset(tree2,0,sizeof(tree2));
		read(n);read(m);
		for(long long i=1;i<=n;++i)read(a[i]),num.emplace_back(a[i]);
		sort(num.begin(),num.end());
		for(long long i=n-1;i>=0;--i)ma[num[i]]=i+1;
		for(long long i=1;i<=n;++i)p[i]=ma[a[i]],++ma[a[i]];
		putchar_unlocked(48);
		putchar_unlocked(32);
		for(long long i=2;i<=n;++i){
			add(tree1,p[i-1],a[i-1]);
			add(tree2,p[i-1],1);
			l=0;
			r=n;
			while(l<r){
				mid=(l+r+1)>>1;
				if(que(tree1,mid)<=m-a[i])l=mid;
				else r=mid-1;
			}
			write(i-que(tree2,l)-1);
			putchar_unlocked(32);
		}
		putchar_unlocked(10);
	}
}
