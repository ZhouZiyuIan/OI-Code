#include<stdio.h>
#include<utility>
#include<string.h>
#include<queue>
using namespace std;
int h,w,a,b,c,d,vis[1001][1001],dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
char s[1001][1001];
void bfs(){
    priority_queue<pair<int,pair<int,int>> > q;
    q.push(make_pair(a,make_pair(b,0)));
    vis[a][b]=0;
    while(!q.empty()){
        int nx=q.top().first,ny=q.top().second.first,dist=q.top().second.second;
        q.pop();
        for(int i=0;i<4;i++){
            int sx=nx+dx[i],sy=ny+dy[i];
            int sxx=sx+dx[i],syy=sy+dy[i];
            printf("%d %d %d %d\n",sx,sy,sxx,syy);
            if(sxx>=0&&sxx<h&&syy>=0&&syy<w&&s[sxx][syy]=='.'){
                if(s[sx][sy]=='#'||s[sxx][syy]=='#'){
                    if(vis[sxx][syy]>dist+1||vis[sxx][syy]==-1){
                        vis[sxx][syy]=dist+1;
                        q.push(make_pair(sxx,make_pair(syy,dist+1)));
                    }
                }
                else if(vis[sxx][syy]>dist||vis[sxx][syy]==-1){
                    vis[sxx][syy]=dist;
                    q.push(make_pair(sxx,make_pair(syy,dist)));
                }
            }
            if(sx>=0&&sx<h&&sy>=0&&sy<w&&s[sx][sy]=='.'&&vis[sx][sy]>dist+1){
                if(s[sx][sy]=='#'){
                    if(vis[sx][sy]>dist+1||vis[sx][sy]==-1){
                        vis[sx][sy]=dist+1;
                        q.push(make_pair(sx,make_pair(sy,dist+1)));
                    }
                }
                else if(vis[sx][sy]>dist||vis[sx][sy]==-1){
                    vis[sx][sy]=dist;
                    q.push(make_pair(sx,make_pair(sy,dist)));
                }
            }
        }
    }
}
main(){
    memset(vis,-1,sizeof(vis));
    scanf("%d%d",&h,&w);
    for(int i=0;i<h;i++)scanf("%s",s[i]);
    scanf("%d%d%d%d",&a,&b,&c,&d);
    a--;b--;c--;d--;
    bfs();
    printf("%d",vis[c][d]);
}