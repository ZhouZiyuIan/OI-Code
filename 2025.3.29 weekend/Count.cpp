#include<stdio.h>
int n,cnt;
main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cnt=0;
        for(int j=1;j<=i;j++)for(int k=1;k<=i;k++){
            if(i%(j*k)==0){
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
}
