#include<stdio.h>
int n,k,cnt[27],j,ans=1;
char A[5000010];
main(){
	scanf("%d%d%s",&n,&k,A);
	for(int i=0;i<n;i++){
		cnt[A[i]-'a']++;
		while(j<=i&&cnt[A[i]-'a']>k)cnt[A[j++]-'a']--;
		ans+=i-j+1;
	}
	printf("%d",ans);
}
