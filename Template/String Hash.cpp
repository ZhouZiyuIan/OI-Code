#include<stdio.h>
#include<stdbool.h>
const int MOD=998244353,base=131; 
int cnt,n,lens;
long long tmp;
bool vis[998244359];
char s[1501];
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		tmp=0;
		lens=0;
		scanf("%s",s);
		for(;s[lens];lens++);
		for(int j=0;j<lens;j++)tmp=(tmp*base+s[j])%MOD;
		vis[tmp]==0?cnt++:0;
		vis[tmp]=1;
	}
	printf("%d",cnt);
}