#include<bits/stdc++.h>
using namespace std;
long long n,t,x[110000];
int main(){
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	scanf("%lld%lld",&n,&t);
	long long sum=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&x[i]);
	}for(int i=1;;i++){
		if(i>n)i=1;
		sum+=x[i];
		if(sum>=t){
			printf("%d\n%lld",i,sum-t);
			return 0;
		}
	}
}
