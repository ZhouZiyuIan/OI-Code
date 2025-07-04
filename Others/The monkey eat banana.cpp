#include<map>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
map<int,int>f;
const int MOD=1000000007;
int d,n,k,cnt,b[1001],a[100000001];
main(){
    scanf("%d",&d);
    while(d--){
        scanf("%d%d",&n,&k);
        f.clear();
        cnt=0;
        for(int i=1;i<=sqrt(k);i++){
            if(k%i==0){
                a[++cnt]=i;
                if(i*i!=k)a[++cnt]=k/i;
            }
        }
        sort(a+1,a+1+cnt);
        for(int i=0;i<n;i++)scanf("%d",&b[i]);
        for(int i=0;i<n;i++){
            for(int j=cnt;j;j--)if(b[i])if(a[j]%b[i]==0){
                f[a[j]]+=f[a[j]/b[i]];
                f[a[j]]%=MOD;
                if(a[j]==b[i]){
                    f[a[j]]++;
                    f[a[j]]%=MOD;
                }
            }
        }
        printf("%d\n",f[a[cnt]]);
    }
}
