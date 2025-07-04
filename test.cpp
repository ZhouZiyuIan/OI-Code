#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;
struct Node{
    long long val;
    int l,r;
    int idx;
    long long b;
};
vector<Node>nodes;
long long dfs(long long u){
    if (nodes[u].idx!=-1)return nodes[u].val;
    long long lv=dfs(nodes[u].l);
    long long rv=dfs(nodes[u].r);
    nodes[u].val=(lv+rv)*nodes[u].b;
    return nodes[u].val;
}
int n,m,num_cnt,op_cnt,b_ptr,x,y;
stack<int>st;
vector<long long>nums,b(100001),num2node(100001);
vector<string>expr(200001);
int main() {
	#ifndef _WIN64
	freopen("addmul.in","r",stdin);
	freopen("addmul.out","w",stdout);
	#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n+n-1;++i)cin>>expr[i];
    for(int i=0;i<n-1;++i)cin>>b[i];
    for(int i=0;i<n+n-1;++i){
        if(expr[i]!="*"){
            long long v=stoll(expr[i]);
            nodes.push_back({v,-1,-1,num_cnt,0});
            st.push(nodes.size()-1);
            nums.emplace_back(v);
            num_cnt++;
        }
		else{
            int r=st.top();
			st.pop();
            int l=st.top();
			st.pop();
            nodes.push_back({0,l,r,-1,b[b_ptr++]});
            st.emplace(nodes.size()-1);
            op_cnt++;
        }
    }
    int root=st.top();
    for(int i=0;i<nodes.size();++i)if(nodes[i].idx!=-1)num2node[nodes[i].idx]=i;
    vector<int>fa(nodes.size(),-1);
    for(int i=0;i<nodes.size();++i){
        if(nodes[i].l!=-1)fa[nodes[i].l]=i;
        if(nodes[i].r!=-1)fa[nodes[i].r]=i;
    }
    dfs(root);
    vector<vector<int>>path2root(nodes.size());
    for (int i=0;i<n;++i){
        int u=num2node[i];
        while(u!=-1){
            path2root[i].emplace_back(u);
            u=fa[u];
        }
    }
    while(m--){
        cin>>x>>y;
        --x;
        int u=num2node[x];
        nodes[u].val=y;
        for (int i=1;i<path2root[x].size();++i){
            int v=path2root[x][i];
            long long lv=nodes[nodes[v].l].val;
            long long rv=nodes[nodes[v].r].val;
            nodes[v].val=(lv+rv)*nodes[v].b;
        }
        cout<<nodes[root].val<<endl;
    }
    return 0;
}
