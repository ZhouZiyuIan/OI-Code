#include<stdio.h>
long long n,L,R,f[50]={1,1};
char sol(long long n,long long x){
	if(n==0)return '0';
	if(n==1)return '1';
	if(x>f[n-2])return sol(n-1,x-f[n-2]);
	return sol(n-2,x);
}
int main(){
	scanf("%lld%lld%lld",&n,&L,&R);
	for(int i=2;i<50;i++)f[i]=f[i-2]+f[i-1];
	for(int i=0;i<50;i++)if(f[i]>=R&&i%2==n%2ll){
		n=i;
		break;
	}
	for(int i=L+1;i<=R+1;i++)putchar(sol(n,i));
}