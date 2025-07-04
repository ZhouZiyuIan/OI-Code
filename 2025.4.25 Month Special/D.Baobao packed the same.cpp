#include<stdio.h>
int n;
long long sum,cnt,aa,ans,a[500001];
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%lld",&a[i]),cnt+=a[i];
	if(cnt%3ll){
		putchar('0');
		return 0;
	}
	cnt/=3ll;
	for(int i=0;i<n-1;i++){
		sum+=a[i];
		if(sum==cnt<<1ll)ans+=aa;
		if(sum==cnt)aa++;
	}
	printf("%lld",ans);
}
