#include<stdio.h>
int n,a[101],b;
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<n;i+=2)b+=a[i];
	printf("%d",b);
}