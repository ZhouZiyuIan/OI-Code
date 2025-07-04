#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<ll, int> vis;
int t, n, y;
ll x[1005];
ll ans, tmp;
int main() {
	freopen("picnic.in","r",stdin); 
	freopen("picnic.out","w",stdout); 
    scanf("%d%d", &n, &y); 
    for(int i = 1; i <= n; i++) {
        scanf("%lld", x+i);
        for(int j = 1; j < i; j++) {
            tmp = x[i]-x[j];
            if(!vis[abs(tmp)]) {
                vis[abs(tmp)] = 1;
                ans++;
            }
        }
    }
    printf("%lld\n", ans);
    
}