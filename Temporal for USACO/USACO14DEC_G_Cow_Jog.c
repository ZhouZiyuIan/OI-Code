#include<stdio.h>
long long n,t,p,v,end[100001],l,r,cnt,ans,mid,s[100001];
main(){
    freopen("cowjog.in","r",stdin);
    freopen("cowjog.out","w",stdout);
    scanf("%lld%lld",&n,&t);
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&p,&v);
        end[i]=p+v*t;
    }
    for(int i=n-1;i>=0;i--){
        if(!cnt||end[i]>=s[cnt])s[++cnt]=end[i];
        else{
            l=1,r=cnt,ans=0;
            while(l<r){
                mid=(l+r)>>1;
                if(s[mid]<=end[i])l=mid+1;
                else r=mid;
            }
            s[l]=end[i];
        }
    }
    printf("%lld",cnt);
}