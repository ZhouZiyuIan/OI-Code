#include<stdio.h>
int n,m,a[501][501],maxS,maxval,curS,curval,lst;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&a[i][j]);
    for(int i=0;i<n;i++){
        curS=0,curval=a[i][0];
        for(int j=i;j<n;j++){
            curS+=m;
            curval=lst;
            lst=gcd(curval,a[j+1][0]);
            if(lst==1||lst==0){
                printf("%d %d\n",i,j);
                break;
            }
        }
        if(curS>maxS&&curval>1){
            maxS=curS;
            maxval=lst;
        }
        else if(curS==maxS)if(curval>maxval&&curval>1)maxval=curval;
    }
    printf("%d\n%d",maxS,maxval);
}