#include<stdio.h>
int n,a[1000001],b[1000001],stk[1000001],top=0,p[1000001];
long long mid,l=0,r=1e18,now,sum,tmp;
void push(int x){stk[top++]=x;}
void pop(){if(top>0)top--;}
int front(){return stk[top-1];}
int empty(){return top==0;}
int size(){return top;}
long long min(long long x,long long y){return x<y?x:y;}
int chk(long long x){
    now=sum=0;
    for(int i=0;i<n;i++){
        sum+=b[i];
        if(p[i]){
            if(now<1ll*(p[i]-i)*x){
                tmp=1ll*(p[i]-i)*x-now;
                l=min(tmp/a[i]+(tmp%a[i]>0),sum);
                now+=l*a[i];
                sum-=l;
            }
        }
        else{
            now+=sum*a[i];
            sum=0;
        }
        now-=x;
        if(now<0)return 0;
    }
    return 1;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<n;i++)scanf("%d",&b[i]);
    for(int i=n-1;i>=0;i--){
        while(!empty()&&a[front()]<=a[i])pop();
        p[i]=empty()?0:front();
        push(i);
    }
    while(l<r){
        mid=(l+r)/2+1;
        if(chk(mid))l=mid;
        else r=mid-1;
    }
    printf("%lld",l);
}