#include<stdio.h>
int n;
long long a[500001],sum,pos,cnt1,cnt2,cur;
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%lld",&a[i]),sum+=a[i];
	if(sum%3ll){
		putchar('0');
		return 0;
	}
	sum/=3ll;
	for(pos;pos<n;pos++){
		cur+=a[pos];
		if(cur==sum){
			cnt1++;
			break;
		}
	}
	pos++;
	for(pos;pos<n&&a[pos]==0ll;pos++)cnt1++;
	cur=0ll;
	for(pos;pos<n;pos++){
		cur+=a[pos];
		if(cur==sum){
			cnt2++;
			break;
		}
	}
	pos++;
	for(;pos<n&&a[pos]==0ll;pos++)cnt2++;
	printf("%lld",cnt1*cnt2);
}
