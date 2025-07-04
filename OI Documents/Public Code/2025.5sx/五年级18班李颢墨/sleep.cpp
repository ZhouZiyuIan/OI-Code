#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n;
long long a[N],s[N],t,ans,id;
int main(){
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	scanf("%d%lld",&n,&t);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	t=t%s[n];
	for(int i=1;i<=n;i++){
		if(s[i]>=t){
			id=i;
			ans=s[i]-t;
			break;
		}
	}
	printf("%lld\n",id);
	printf("%lld",ans);
	return 0;
}
