#include<stdio.h>
int T,n,A,B,f[1001],w[1001],cntf,cntw,curf,curw,datef,datew;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&A,&B);
        cntf=cntw=curf=curw=datef=datew=0;
        for(int i=0;i<n;i++){
            scanf("%d",&f[i]);
            if(f[i]==1){
                if(i-datef-B<0&&curf)curf--;
                else cntf++,datef=i,curf=A;
            }
        }
        for(int i=0;i<n;i++){
            scanf("%d",&w[i]);
            if(w[i]==1){
                if(i-datew-B<=0&&curw)curw--;
                else cntw++,datew=i,curw=A;
            }
        }
        printf("%d\n",cntf+cntw);
    }
}