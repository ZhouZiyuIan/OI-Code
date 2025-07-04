#include<stdio.h>
#include<string.h>
int q,k,lenS,lenT,f,cnt=1;
char S[5001],T[5001];
main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d%s%s",&q,S,T);
	lenS=strlen(S);
	lenT=strlen(T);
	for(int i=0;i<lenT;i++){
		f=1;
		for(int j=0;j<lenS;j++){
			if(S[j]!=T[i+j]){
				f=0;
				break;
			}
		}
		if(f)cnt++;
	}
	while(q--){
		scanf("%d",&k);
		printf("%d\n",cnt*k-(k==1?0:1));
	}
}
