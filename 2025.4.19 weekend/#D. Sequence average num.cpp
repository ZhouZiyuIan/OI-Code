#include<stdio.h>
int n,a[500001],tmp,vis[500001];
long long fz=0,fm=1,t;
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;} 
long long lcm(long long a,long long b){return a*b/gcd(a,b);}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),vis[a[i]]++;
	for(int l=1;l<=n;l++){
		for(int r=n;r>=l;r--){
			for(int i=0;;i++)if(vis[i]==0){
				t=lcm(fm,r-l+1);
				fz*=t/fm;
				fz+=i*t/(r-l+1);
				fm=t;
				break;
			}
			vis[a[r]]--;
		}
		for(int r=l+1;r<=n;r++)vis[a[r+1]]++;
		vis[a[l]]--;
	}
	printf("%lld",(fz+998244353)/fm);
}
