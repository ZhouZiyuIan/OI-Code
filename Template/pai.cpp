#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
stack < int > pru;
int n, m, head[2010], low[2010], dfn[2010], col[2010], vis[2010], num, z, color; char s1[10], s2[10];
struct node {int next, to;}stu[8010];
void add(int x, int y) {stu[++num].next = head[x]; stu[num].to = y; head[x] = num;}
void tarjan(int u)
{
    dfn[u] = low[u] = ++z; pru.push(u);
    for(int i = head[u]; i; i = stu[i].next)
    {
        int k = stu[i].to;
        if(!dfn[k]) tarjan(k), low[u] = min(low[u], low[k]);
        else if(!col[k]) low[u] = min(low[u], dfn[k]);
    }
    if(low[u] == dfn[u])
    {
        col[u] = ++color;
        while(pru.top() != u)
            col[pru.top()] = color, pru.pop();
        pru.pop();
    }
    return;
}
void dfs(int u)
{
	printf("u:%d\n",u);
    vis[u] = 1;
    for(int i = head[u]; i; i = stu[i].next)
    {
        int k = stu[i].to;
        if(!vis[k]) dfs(k);
    }
    return;
}
int check(int x)
{
	printf("x:%d\n",x);
    memset(vis, 0, sizeof(vis)); dfs(x);
    for(int i = 1; i <= n; ++i)
        if(vis[i] && vis[i + n]) return 0;
    return 1;
}
int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1, x, y, a, b; i <= m; ++i)
    {
        scanf("%d %s %d %s", &x, s1, &y, s2);
        a = (s1[0] == 'Y'), b = (s2[0] == 'Y');
        add(a * n + x, !b * n + y), add(b * n + y, !a * n + x);
    }
    for(int i = 1; i <= 2 * n; ++i)
        if(!dfn[i]) tarjan(i);
    for(int i = 1; i <= n; ++i)
        if(col[i] == col[i + n]) {puts("IMPOSSIBLE"); return 0;}
    for(int i = 1, Tr, Fa; i <= n; ++i)
    {
        Tr = check(i), Fa = check(i + n);
        if(Tr && Fa) putchar('?'); else if(Tr) putchar('Y'); else putchar('N');
    }
    return 0;
}
