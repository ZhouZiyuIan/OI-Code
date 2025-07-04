#include<stdio.h>
#include<stdlib.h>
typedef long long ll;
ll n,k,a,b[200001],ans,l,r;
int cmp(const void *a,const void *b){return(*(ll*)a-*(ll*)b);}
main(){
    scanf("%lld%lld",&n,&k);
    for(ll i=0;i<n;i++){
        scanf("%lld",&a);
        ans+=a/k;
        b[i]=a%k;
    }
    qsort(b,n,sizeof(ll),cmp);
    r=n-1;
    while(l<r){
        if(b[l]+b[r]>=k){
            ans++;
            l++;
            r--;
        }
        else l++;
    }
    printf("%lld",ans);
}