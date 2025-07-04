#include<stdio.h>
#include<algorithm>
using namespace std;
int T,n,m;
long long a[100001],pref_sum[100001],l,r,mid;
int main(){
	#ifndef ONLINE_JUDGE
	#ifndef _WIN64
	freopen("car.in","r",stdin);
	freopen("car.out","w",stdout);
	#endif
	#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i){
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;++i){
			l=1;
			r=i-1;
			mid=(l+r)>>1;
			if(l<=r){
				sort(a,a+i);
				for(int i=1;i<=n;++i)pref_sum[i]=pref_sum[i-1]+a[i];
			}
			while(l<=r){
				if(pref_sum[mid]+a[i]<=m)l=mid+1;
				else r=mid-1;
				mid=(l+r)>>1;
			}
			printf("%lld ",i-1-mid);
		}
		putchar(10);
	}
}//Very Violent
