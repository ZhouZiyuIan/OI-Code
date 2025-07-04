#include<stdio.h>
long long q,k,lenS,lenT,nxt[5001][60],c[5001][60],i,ans;
char S[5001],T[5001];
main(){
    // freopen("string.in","r",stdin);
    // freopen("string.out","w",stdout);
    scanf("%lld%s%s",&q,S,T);
    for(;T[lenT];lenT++);
    for(;S[lenS];lenS++){
        int j=lenS,cnt=0;
        for(int i=0;i<lenT;i++){
            if(S[j]==T[i]){
                j++;
                if(S[j]==0){
                    cnt++;
                    j=0;
                }
            }
        }
        nxt[lenS][0]=j;
        c[lenS][0]=cnt;
    }
    for(int j=1;j<=59;j++){
        for(int i=0;i<lenS;i++){
            nxt[i][j]=nxt[nxt[i][j-1]][j-1];
            c[i][j]=c[i][j-1]+c[nxt[i][j-1]][j-1];
        }
    }
    while(q--){
        scanf("%lld",&k);
        i=0;
        ans=1;
        for(int j=59;~j;j--){
            if(k>>j&1){
                ans+=c[i][j];
                i=nxt[i][j];
            }
        }
        printf("%lld\n",ans);
    }
}