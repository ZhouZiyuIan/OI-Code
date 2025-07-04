#include<stdio.h>
int n,k,a[200001],sum,times=1,cnt;
main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int l=0;l<n;l++){
		times=1;
		sum=0;
		for(int r=l;r<(l+60<n?l+60:n);r++){
			times*=a[r];
			sum+=a[r];
			if(times==sum*k)cnt++;
		}
	}
	printf("%d",cnt);
}
