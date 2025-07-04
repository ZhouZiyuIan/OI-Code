#pragma GCC optimize(2,3,"Ofast")
#include<stdio.h>
#include<ctype.h>
#include<string.h>
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
T max(T a,T b){return a>b?a:b;}
template<typename T>
T min(T a,T b){return a<b?a:b;}
template<typename type,typename ...T>
inline void read(type &x,T&...y){read(x);read(y...);}
int n,k,a[1<<21],rk[1<<21],alivecnt,groupsiz,groupnum,l,r,alipcnt;
bool alive[1<<21];
int main(){
	#ifndef _WIN64
	freopen("gaming.in","r",stdin);
	freopen("gaming.out","w",stdout);
	#endif
	read(n,k);
	for(int i=0;i<(1<<n);++i)read(a[i]);
	memset(alive,1,1<<n);
	alivecnt=(1<<n);
	for(int round=1;round<=n;++round){
		groupsiz=(1<<round);
		if(groupsiz<=k)continue;
		groupnum=(1<<n)/groupsiz;
		vector<int>die;
		for(int i=0;i<groupnum;++i){
			alipcnt=0;
			l=i*groupsiz;
			r=(i+1)*groupsiz-1;
			vector<int>alivepeople;
			for(int j=l;j<=r;++j)if(alive[j]){
				alivepeople.emplace_back(j);
				++alipcnt;
			}
			if(alipcnt>k){
				nth_element(alivepeople.begin(),alivepeople.begin()+k,alivepeople.end(),[&](int x,int y){return a[x]>a[y];});
				for(int j=k;j<alipcnt;++j){
					alive[alivepeople[j]]=0;
					die.emplace_back(alivepeople[j]);
				}
			}
		}
		alivecnt-=die.size();
		for(auto i:die)rk[i]=alivecnt+1;
	}
	vector<int>finalalive;
	for(int i=0;i<(1<<n);++i)if(alive[i])finalalive.emplace_back(i);
	sort(finalalive.begin(),finalalive.end(),[&](int x,int y){return a[x]>a[y];});
	for(unsigned i=0;i<finalalive.size();++i)rk[finalalive[i]]=i+1;
	for(int i=0;i<(1<<n);++i){
		write(rk[i]); 
		putchar_unlocked(32);
	}
}
