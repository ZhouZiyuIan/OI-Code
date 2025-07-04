#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<int, int> vis;
ll m;
ll sum;
int n;
int ans, cnt, tmp;
int a[100005];
int main(){
	freopen("sleep.in","r",stdin); 
	freopen("sleep.out","w",stdout); 
    scanf("%d%lld", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        sum += a[i];
    }
    m = m%sum;
    while(m) {
        tmp = a[ans] < m ? a[ans] : m;
        if(tmp < m) ans = ans % n + 1;
        else cnt = a[ans] - m;
        m -= tmp;
    }
    printf("%d\n%d", ans, cnt);
    return 0;
}