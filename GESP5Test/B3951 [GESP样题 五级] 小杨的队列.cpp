#include<stdio.h>
#include<algorithm>
int n,a[2001],m,x,tmp[2001],cnt;
main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&x);
        tmp[i]=a[x];
        for(int j=i-1;j>=1;j++)if(tmp[j]>tmp[i])cnt++,std::swap(tmp[i],tmp[j]);
    }
}
