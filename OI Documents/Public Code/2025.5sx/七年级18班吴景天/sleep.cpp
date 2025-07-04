#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,t,mus[100010],allt;
int main(){
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	scanf("%lld%lld",&n,&t);
	for(ll i=1;i<=n;i++) scanf("%lld",&mus[i]),allt+=mus[i];
	t%=allt;
	for(ll i=1;true;i++){
		if(i>n) i=1;
		if(t-mus[i]>0) t-=mus[i];
		else{
			printf("%lld\n%lld",i,mus[i]-t);
			break;
		}
	}
	return 0;
}
