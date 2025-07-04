#include<bits/stdc++.h>
using namespace std;
char maz[15][10005];
int t, n, m, k;
int mar;
int d[5] = {0, 1, -1};
bool chk(int x, int y) {
    if(x < 1 || x > m) return true;
    for(int j = 0; j <= 2; j++)
        if(y+j <= n && maz[x][y+j] != '.') 
            return true;
    return false;
}
bool bfs(int sx, int sy) {
    queue<pair<int, int> > que;
    que.push({sx, sy});
    int x, y;
    while(!que.empty()) {
        x = que.front().first;
        y = que.front().second+1;
        que.pop();
        if(maz[x][y] != '.') continue;
        for(int i = 0; i < 3; i++) {
            if(chk(x+d[i], y)) continue;
            if(y+2 >= n) return true;
            maz[x+d[i]][y+2] = 'X';
            que.push({x+d[i], y+2});
        }
    }
    return false;
} 
void sol() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= m; i++) {
        scanf("%s", maz[i]+1);
        if(maz[i][1] == 's') {
            maz[i][1] = '.';
            mar = i;
        }
    }
    if(bfs(mar, 1)) printf("YES\n");
    else printf("NO\n");
}
int main() {
    freopen("parkour.in","r",stdin);
    freopen("parkour.out","w",stdout);
    scanf("%d", &t);
    while(t--) sol();
}