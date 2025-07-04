#include<stdio.h>
int n;
double t,l=-1e8,r=1e8,mid,d[1001],s[1001];
int chk(double x){
	double time=0;
	for(int i=0;i<n;i++){
		if(x+s[i]<=0)return 0;
		time+=d[i]/(x+s[i]);
	}
	return time<=t;
}
main(){
	scanf("%d%lf",&n,&t);
	for(int i=0;i<n;i++)scanf("%lf%lf",&d[i],&s[i]);
	while(r-l>1e-9){
		mid=(l+r)/2;
		if(chk(mid))r=mid;
		else l=mid;
	}
	printf("%lf",l);
}
