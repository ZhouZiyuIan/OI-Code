#include<stdio.h>
int n,c[2001],a[2001],res,pre,l,r,lstl;
int min(int a,int b){return a<b?a:b;}
main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d",&c[i]);
	for(int i=1;i<n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++)if(a[i]){
		l=r=i;
		while(pre<l){
			res++;
			lstl=l;
			for(int j=lstl;j<=r;j++)l=min(l,j-c[j]);
		}
		pre=i;
	}
	printf("%d",res);
}