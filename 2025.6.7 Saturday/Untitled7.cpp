#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
vector<vector<pair<int,int>>> adj;
vector<pair<int,int>> edges;
vector<int> vis, in_cycle, parent, stk;
vector<int> cycle_nodes;
bool found_cycle = false;

// 找环（只要找到一条回边就上溯）
void dfs_find(int u, int p_edge_id){
    vis[u] = 1;
    stk.push_back(u);
    for(auto [v, eid] : adj[u]){
        if(eid == p_edge_id) continue;
        if(!vis[v]){
            parent[v] = u;
            dfs_find(v, eid);
            if(found_cycle) return;
        } else if(vis[v] == 1 && !found_cycle){
            // 找到环，从 u 回溯到 v
            found_cycle = true;
            int x = u;
            cycle_nodes.push_back(v);
            while(x != v){
                cycle_nodes.push_back(x);
                x = parent[x];
            }
            return;
        }
    }
    stk.pop_back();
    vis[u] = 2;
}

// 对一棵以 root 为根的子树做 DFS，排除环上的边
// 返回：该子树的大小 size，及内部需要的操作数 cnt
pair<ll,ll> dfs_tree(int u){
    ll sz = 1, cnt = 0;
    in_cycle[u] = 1; // 标记，防止进环
    for(auto [v, eid] : adj[u]){
        if(in_cycle[v]) continue;
        auto [s2, c2] = dfs_tree(v);
        sz += s2;
        cnt += c2;
        if(s2 % 2 == 1){
            // 这一条树枝也要用一次
            cnt++;
        }
    }
    return {sz, cnt};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    adj.assign(N+1, {});
    edges.resize(M);
    for(int i = 0; i < M; i++){
        int a,b;
        cin >> a >> b;
        edges[i] = {a,b};
        adj[a].push_back({b,i});
        adj[b].push_back({a,i});
    }
    if(N % 2 == 1){
        cout << -1 << "\n";
        return 0;
    }

    if(M == N-1){
        // 单纯树
        ll ans = 0;
        function<ll(int,int)> dfs = [&](int u, int p){
            ll sz = 1;
            for(auto [v, eid] : adj[u]){
                if(v == p) continue;
                ll s2 = dfs(v, u);
                if(s2 % 2 == 1) ans++;
                sz += s2;
            }
            return sz;
        };
        dfs(1,0);
        cout << ans << "\n";
        return 0;
    }

    // M == N：找单一环
    vis.assign(N+1, 0);
    parent.assign(N+1, 0);
    dfs_find(1, -1);

    // 标记环上点
    in_cycle.assign(N+1, 0);
    for(int u : cycle_nodes){
        in_cycle[u] = 0; // 暂时清零，后面在 dfs_tree 中标记
    }

    int k = cycle_nodes.size();
    vector<ll> sub_sz(k), sub_cnt(k);
    ll base_cnt = 0;

    // 对每个环节点，跑它挂掉的“枝丫树”
    for(int i = 0; i < k; i++){
        int u = cycle_nodes[i];
        // 清理标记，让 dfs_tree 只走非环边
        // 注意：in_cycle[v]=1 表示 v 已算过或在环上
        in_cycle[u] = 1;
    }
    for(int i = 0; i < k; i++){
        int u = cycle_nodes[i];
        auto [s, c] = dfs_tree(u);
        sub_sz[i] = s;
        sub_cnt[i] = c;
        base_cnt += c;
    }

    // 计算环上断边的最小“额外”花费
    // p[i] = sub_sz[i] % 2
    vector<int> p(k), pre(k);
    for(int i = 0; i < k; i++){
        p[i] = sub_sz[i] % 2;
        pre[i] = ((i>0? pre[i-1]:0) + p[i]) % 2;
    }
    ll cnt0 = 0, cnt1 = 0;
    for(int i = 0; i < k; i++){
        if(pre[i] == 0) cnt0++;
        else cnt1++;
    }
    ll extra = min(cnt0, cnt1);

    cout << (base_cnt + extra) << "\n";
    return 0;
}

