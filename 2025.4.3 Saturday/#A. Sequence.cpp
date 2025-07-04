#include<stdio.h>
#include<set>
#include<vector>
using namespace std;
set<vector<int> >s;
vector<int>tmp;
int n,m,a[51],lens;
main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        for(int i=0;i<n;i++){
            tmp.clear();
            for(int j=0;j<i;j++)tmp.emplace_back(a[j]);
            for(int j=i+1;j<n;j++)tmp.emplace_back(a[j]);
            for(int j=0;j<n;j++)printf("%d ",tmp[j]);
            putchar('\n');
            s.insert(tmp);
        }
        lens=s.size();
        printf("%d\n",n*m-lens);
    }
}
