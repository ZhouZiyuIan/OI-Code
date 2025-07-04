#include<stdio.h>
#include<math.h>
int n,m,temp,cnt,lst;
double tmp,tmp1,temp1;
int main(){
    scanf("%d%d",&n,&m);
    for(int a=1;a<=n;a++){
        for(int b=1;b<=m;b++){
            tmp=sqrt(a);
            tmp1=sqrt(b);
            temp=temp1=a+b+2*tmp*tmp1;
            if(temp1==temp){
//                 printf("%d %d\n",a,b);
                cnt++;
            }
        }
    }
    printf("%d",cnt);
}
